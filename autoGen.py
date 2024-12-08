import csv
import sys
from datetime import datetime
import re
from pathlib import Path


script_dir = Path(__file__).parent
csv_file = script_dir / 'commands.csv'
header_file = script_dir / 'master/include/asservissement_interface.h'
fonction_file = script_dir / 'master/src/asservissement_interface.cpp'
robot_interface_file = script_dir / 'slave/include/robot_interface.h'
function_interface_file = script_dir / 'slave/src/robot_interface.cpp'
doc_file = script_dir / 'Readme.md'

def parse_params(param):
    param = param.strip().strip('"')
    arguments = param.split(',')
    result = []
    for arg in arguments:
        parts = arg.strip().split('=')
        declaration = parts[0].strip().split()
        default_value = parts[1].strip() if len(parts) > 1 else None
        if len(declaration) >= 2:
            is_reference = '&' in declaration[-2] or '&' in declaration[-1]
            arg_type = declaration[-2].replace('&', '')
            arg_name = declaration[-1].replace('&', '')
            result.append({
                'type': arg_type,
                'name': arg_name,
                'is_reference': is_reference,
                'default_value': default_value
            })
    return result

def create_header_content(rows):
    public_methods = []
    public_methods_overloading = []
    private_methods = []
    private_methods_overloading = []
    for row in rows:
        returnParameter = row['return'].strip() if row['return'] else "void"
        command_name = row['name'].strip()
        param = row['paramater'].strip() if row['paramater'] else ""
        method_type = row['type'].strip().lower()
        id = row['commandId'].strip()

        if command_name:
            method_signature = f"    {returnParameter} {command_name}({param});\n"
            if method_type == "public":
                if id:
                    public_methods.append(method_signature)
                else:
                    public_methods_overloading.append(method_signature)
            elif method_type == "private":
                if id:
                    private_methods.append(method_signature)
                else:
                    private_methods_overloading.append(method_signature)

    generated_content = []
    generated_content.append("public:\n")
    generated_content.extend(public_methods)
    generated_content.append("\n    //Overloding function\n")
    generated_content.extend(public_methods_overloading)
    generated_content.append("\nprivate:\n")
    generated_content.extend(private_methods)
    generated_content.append("\n    //Overloding function\n")
    generated_content.extend(private_methods_overloading)
    return generated_content

def generate_function_content(param,commandId):
    function_content = []

    # empty focntion
    if not param:
        function_content.append("    uint8_t* data = nullptr;\n")
        function_content.append("    int length = 0;\n")
        function_content.append("    I2cSendData(" + commandId + ", data, length);\n")
        return function_content

    param_list = param.split(",")
    reference_params = []
    value_params = []

    for p in param_list:
        p = p.strip()
        if '&' in p:  # Paramètre passé par référence
            reference_params.append(p)
        else:
            value_params.append(p)

    if len(reference_params) > 0:
        function_content.append(f"    uint8_t data[{len(reference_params)*2}];\n")
        function_content.append(f"    int length = {len(reference_params)*2};\n")
        function_content.append( "    I2cReceiveData(" + commandId + ", data, length);\n")
        function_content.append( "    DataUnpacker unpacker(data, length);\n")

        for ref_param in reference_params:
            param_type = ref_param.split(" ")[0].replace("&", "").strip()
            param_name = ref_param.split(" ")[-1].replace("&", "").strip()
            function_content.append(f"    {param_name} = ({param_type})unpacker.popUint16();\n")

    elif len(value_params) > 0:
        function_content.append("    DataPacker packer;\n")
        for val_param in value_params:
            param_type = val_param.split(" ")[0]
            param_name = val_param.split(" ")[-1]
            function_content.append(f"    packer.addUint16((int16_t){param_name});\n")

        function_content.append("    I2cSendData(" + commandId + ", packer.getData(), packer.getSize());\n")

    return function_content

def create_fonction_content(rows):
    fonction = []
    for row in rows:
        returnParameter = row['return'].strip() if row['return'] else "void"
        command_name = row['name'].strip()
        params = row['paramater'].strip() if row['paramater'] else ""
        id = row['commandId'].strip()


        cleaned_params = []
        for param in params.split(','):
            cleaned_param = re.split(r'\s*=\s*', param.strip())[0]
            cleaned_params.append(cleaned_param)
        output_params = ', '.join(cleaned_params)

        if command_name and id:
            fonction.append(f"{returnParameter} asservissement_interface::{command_name}({output_params})" + "{\n")
            fonction.extend(generate_function_content(output_params,row['commandId']))
            fonction.append("}\n\n")
    return fonction

def create_robot_interface_content(rows):
    virtual_methods = []
    virtual_methods.append(f"private:\n")

    for row in rows:
        command_name = row['name'].strip()
        param = row['paramater'].strip() if row['paramater'] else ""
        id = row['commandId'].strip()

        if id:
            virtual_methods.append(f"    virtual void {command_name}({param}) = 0;\n")
    return virtual_methods

def create_function_interface_content(rows):
    function_content = []
    function_content.append("void Robot_interface::I2CDataSwitch(uint8_t* data, int size){\n")
    function_content.append("    uint8_t dataPack[64];\n")
    function_content.append("    DataPacker packer(dataPack, 64);\n")
    function_content.append("    DataUnpacker unPacker(&data[1], size + 1);\n")
    function_content.append("    switch (data[0]){\n")

    for row in rows:
        returnParameter = row['return'].strip() if row['return'] else "void"
        command_name = row['name'].strip()
        params = parse_params(row['paramater'].strip())
        id = row['commandId'].strip()

        if id:
            function_content.append(f"        case {id}:" + "{\n")
            for arg in params:
                function_content.append(f"            {arg['type']} {arg['name']};\n")
            for arg in params:
                if not(arg['is_reference']):
                    function_content.append(f"            {arg['name']} = ({arg['type']})unPacker.popUint16();\n")
            function_param = ""
            for arg in params:
                function_param += f"{arg['name']}, "
            if function_param:
                function_param = function_param[:-2]
            function_content.append(f"            {command_name}({function_param});\n")
            for arg in params:
                if arg['is_reference']:
                    function_content.append(f"            packer.addUint16((int16_t){arg['name']});\n")
            if any(arg['is_reference'] for arg in params):
                function_content.append( "            setReponseBuffer(packer.getData(),packer.getSize());\n")
            function_content.append( "            break;\n")
            function_content.append( "        }\n")


    function_content.append("        default:\n")
    function_content.append("            break;\n")
    function_content.append("    }\n")
    function_content.append("}\n")
    return function_content


def create_class_id_content(rows):
    ids = []
    class_id = []
    for row in rows:
        command_name = row['name'].strip().upper()
        id = row['commandId'].strip()

        if command_name and id:
            ids.append(f"    {command_name} = {id}")

    for i in range(len(ids) - 1):
        ids[i]+=",\n"

    class_id.append("enum class CommandNum {\n")
    class_id.extend(ids)
    class_id.append("\n};\n")
    return class_id

def create_doc_content(rows):
    docContent = []

    lastCategory = ""
    number = 1
    docContent.append(f"## Table of Contents\n")
    for row in rows:
        category = row['category'].strip()
        if lastCategory != category:
            docContent.append(f"{number}. [{category}](#{category})\n")
            number = number + 1
            lastCategory = category

    lastCategory = ""
    number = 1
    for row in rows:
        returnParameter = row['return'].strip() if row['return'] else "void"
        command_name = row['name'].strip()
        params = row['paramater'].strip() if row['paramater'] else "void"
        method_type = row['type'].strip().lower()
        description = row['description'].strip()
        usage = row['usage'].strip()
        category = row['category'].strip()

        if lastCategory != category:
            docContent.append(f"## {number}. {category}\n\n")
            number = number + 1
            lastCategory = category

        if method_type:
            docContent.append(f"#### {command_name}\n")
            if returnParameter == "void":
                docContent.append(f"**Return**: void  \n")
            else:
                docContent.append(f"**Return**:  \n")
                docContent.append(f"- `{returnParameter}`  \n")
                docContent.append(f"\n")
            if params == "void":
                docContent.append(f"**Parameters**: void  \n")
            else:
                docContent.append(f"**Parameters**:  \n")
                for param in params.split(','):
                    docContent.append(f"- `{param}`  \n")
                docContent.append(f"\n")
            if description:
                docContent.append(f"**Description**: {description}  \n")
            if usage:
                docContent.append(f"**Usage**: {usage}  \n")
            docContent.append(f"\n\n---\n\n")
    return docContent

def update_file(header_file, content, marker):
    with open(header_file, 'r') as file:
        lines = file.readlines()

    start_markers = [
        f"<!-- Start auto generation {marker} -->",
        f"// Start auto generation {marker}"
    ]
    end_markers = [
        f"<!-- End auto generation {marker} -->",
        f"// End auto generation {marker}"
    ]

    start_idx, end_idx = None, None

    for idx, line in enumerate(lines):
        if any(start_marker in line for start_marker in start_markers):
            start_idx = idx
        if any(end_marker in line for end_marker in end_markers):
            end_idx = idx
            break

    if start_idx is None or end_idx is None:
        print("Marqueurs non trouvés dans le fichier.")
        return

    start_marker_line = lines[start_idx].strip()
    if start_marker_line.startswith("<!--"):
        comment_style = "<!-- -->"
    else:
        comment_style = "//"

    current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    command_comment = "python3 autoGen.py"

    if comment_style == "<!-- -->":
        generated_content = [
            f"<!-- Last generation {current_time}: {command_comment} -->\n",
            "<!-- DO NOT EDIT -->\n"
        ]
    else:
        generated_content = [
            f"// Last generation {current_time}: {command_comment}\n",
            "// DO NOT EDIT\n"
        ]

    generated_content.extend(content)

    if "".join(generated_content[+1:]) == "".join(lines[start_idx + 2:end_idx]):
        print("Le contenu généré est identique à l'existant. Aucun changement n'a été effectué.")
        return

    updated_lines = (
        lines[:start_idx + 1] +
        generated_content +
        lines[end_idx:]
    )

    with open(header_file, 'w') as file:
        file.writelines(updated_lines)
    print(f"Le fichier {header_file} a été mis à jour avec succès. {len(generated_content)} lignes ajoutées.")


with open(csv_file, 'r') as csvfile:
    reader = csv.DictReader(csvfile)
    rows = list(reader)

    content_header = create_header_content(rows)
    update_file(header_file, content_header, "CMD_HEADER")

    # content_class_id = create_class_id_content(rows)
    # update_file(header_file, content_class_id, "CMD_CLASS_ID")

    content_focntion = create_fonction_content(rows)
    update_file(fonction_file, content_focntion, "CMD_FONCTION")

    content_robot_interface = create_robot_interface_content(rows)
    update_file(robot_interface_file, content_robot_interface, "CMD_ROBOT_INTERFACE")

    content_function_interface = create_function_interface_content(rows)
    update_file(function_interface_file, content_function_interface, "CMD_ROBOT_FUNCTION_INTERFACE")

    content_doc = create_doc_content(rows)
    update_file(doc_file, content_doc, "CMD_DOC")

import csv
import sys
from datetime import datetime
import re
from pathlib import Path


script_dir = Path(__file__).parent
csv_file = script_dir / 'commands.csv'
header_file = script_dir / 'include/asservissement_interface.h'
fonction_file = script_dir / 'src/asservissement_interface.cpp'


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
        function_content.append("    I2cReceiveData(" + commandId + ", data, length);\n")
        function_content.append("    DataUnpacker unpacker(data, length);\n")

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

def update_file(header_file, content, marker):
    with open(header_file, 'r') as file:
        lines = file.readlines()

    start_marker = "// Start auto generation " + marker
    end_marker = "// End auto generation " + marker
    start_idx, end_idx = None, None

    for idx, line in enumerate(lines):
        if start_marker in line:
            start_idx = idx
        if end_marker in line:
            end_idx = idx
            break

    if start_idx is None or end_idx is None:
        print("Marqueurs non trouvés dans le fichier.")
        return

    current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    command_comment = "python3 autoGen.py"

    generated_content = []
    generated_content.append(f"// Last generation {current_time}: {command_comment}\n")
    generated_content.append("// DO NOT EDIT\n")
    generated_content.extend(content)

    updated_lines = (
        lines[:start_idx + 1] +
        generated_content +
        lines[end_idx:]
    )

    with open(header_file, 'w') as file:
        file.writelines(updated_lines)
    print(f"Le fichier {header_file} a été mis à jour avec succès.")


with open(csv_file, 'r') as csvfile:
    reader = csv.DictReader(csvfile)
    rows = list(reader)

    content_header = create_header_content(rows)
    update_file(header_file, content_header, "CMD_HEADER")

    # content_class_id = create_class_id_content(rows)
    # update_file(header_file, content_class_id, "CMD_CLASS_ID")

    content_focntion = create_fonction_content(rows)
    update_file(fonction_file, content_focntion, "CMD_FONCTION")

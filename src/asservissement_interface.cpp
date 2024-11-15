#include "asservissement_interface.h"



void asservissement_interface::turn_on_LED_1(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(CMD_TURN_ON_LED_1, data, length);
}

void asservissement_interface::turn_off_LED_1(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(CMD_TURN_OFF_LED_1, data, length);
}

void asservissement_interface::turn_on_LED_2(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(CMD_TURN_ON_LED_2, data, length);
}

void asservissement_interface::turn_off_LED_2(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(CMD_TURN_OFF_LED_2, data, length);
}

void asservissement_interface::get_coordinates(int16_t &x, int16_t &y, int16_t &theta) {
    uint8_t data[6];
    int length = 6;
    I2cReceiveData(CMD_GET_COORDINATES, data, length);
    DataUnpacker unpacker(data, length);
    x = unpacker.popUint16();
    y = unpacker.popUint16();
    theta = unpacker.popUint16();
}

void asservissement_interface::set_coordinates(int16_t x, int16_t y, int16_t theta){
    DataPacker packer;
    packer.addUint16(x);
    packer.addUint16(y);
    packer.addUint16(theta);
    I2cSendData(CMD_SET_COORDINATES, packer.getData(), packer.getSize());
}

void asservissement_interface::stop(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(CMD_STOP, data, length);
}

void asservissement_interface::brake(bool enable){

}

void asservissement_interface::set_consigne_lineaire(int16_t x, int16_t y){
    DataPacker packer;
    packer.addUint16(x);
    packer.addUint16(y);

    I2cSendData(CMD_SET_CONSIGNE_LINEAIRE, packer.getData(), packer.getSize());
}

void asservissement_interface::set_consigne_angulaire(int16_t angle, int16_t rotation){
    DataPacker packer;
    packer.addUint16(angle);
    packer.addUint16(rotation);

    I2cSendData(CMD_SET_CONSIGNE_ANGULAIRE, packer.getData(), packer.getSize());
}

void asservissement_interface::set_consigne_lookAt_forward(int16_t x, int16_t y, int16_t rotation){
    DataPacker packer;
    packer.addUint16(x);
    packer.addUint16(y);
    packer.addUint16(rotation);

    I2cSendData(CMD_SET_CONSIGNE_LOOKAT_FORWARD, packer.getData(), packer.getSize());
}

void asservissement_interface::set_consigne_lookAt_backward(int16_t x, int16_t y, int16_t rotation){
    DataPacker packer;
    packer.addUint16(x);
    packer.addUint16(y);
    packer.addUint16(rotation);

    I2cSendData(CMD_SET_CONSIGNE_LOOKAT_BACKWARD, packer.getData(), packer.getSize());
}

void asservissement_interface::robot_moving_is_finish(int16_t &resbool){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(CMD_ROBOT_MOVING_IS_DONE, data, length);

    DataUnpacker unpacker(data, length);
    resbool = unpacker.popUint16();
}

void asservissement_interface::robot_running_is_finish(int16_t &resbool){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(CMD_ROBOT_RUNNING_IS_DONE, data, length);

    DataUnpacker unpacker(data, length);
    resbool = unpacker.popUint16();
}

void asservissement_interface::robot_turning_is_finish(int16_t &resbool){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(CMD_ROBOT_TURNING_IS_DONE, data, length);

    DataUnpacker unpacker(data, length);
    resbool = unpacker.popUint16();
}

void asservissement_interface::get_linear_error(int16_t &error){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(CMD_GET_LINEAR_ERROR, data, length);

    DataUnpacker unpacker(data, length);
    error = unpacker.popUint16();
}

void asservissement_interface::get_angular_error(int16_t &error){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(CMD_GET_ANGULAR_ERROR, data, length);

    DataUnpacker unpacker(data, length);
    error = unpacker.popUint16();
}

void asservissement_interface::get_braking_distance(int16_t &distance){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(CMD_GET_BRAKING_DISTANCE, data, length);

    DataUnpacker unpacker(data, length);
    distance = unpacker.popUint16();
}

int16_t asservissement_interface::get_linear_error(){
    int16_t distance;
    get_linear_error(distance);
    return distance;
}

int16_t asservissement_interface::get_angular_error(){
    int16_t distance;
    get_angular_error(distance);
    return distance;
}

int16_t asservissement_interface::get_braking_distance(){
    int16_t distance;
    get_braking_distance(distance);
    return distance;
}

void asservissement_interface::disable_motor(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(CMD_DISABLE_MOTOR, data, length);
}

void asservissement_interface::enable_motor(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(CMD_ENABLE_MOTOR, data, length);
}

void asservissement_interface::set_max_speed_forward(int16_t speed){
    DataPacker packer;
    packer.addUint16(speed);

    I2cSendData(CMD_SET_MAX_SPEED_FORWARD, packer.getData(), packer.getSize());
}

void asservissement_interface::set_max_speed_backward(int16_t speed){
    DataPacker packer;
    packer.addUint16(speed);

    I2cSendData(CMD_SET_MAX_SPEED_BACKWARD, packer.getData(), packer.getSize());
}

void asservissement_interface::set_max_speed_trigo(int16_t speed){
    DataPacker packer;
    packer.addUint16(speed);

    I2cSendData(CMD_SET_MAX_SPEED_TRIGO, packer.getData(), packer.getSize());
}

void asservissement_interface::set_max_speed_horloge(int16_t speed){
    DataPacker packer;
    packer.addUint16(speed);

    I2cSendData(CMD_SET_MAX_SPEED_HORLOGE, packer.getData(), packer.getSize());
}
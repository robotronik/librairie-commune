#include "asservissement_interface.h"

//***********************************************
// Start auto generation CMD_FONCTION
// Last generation 2024-12-08 19:31:48: python3 autoGen.py
// DO NOT EDIT
void asservissement_interface::turn_on_LED_1(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(10, data, length);
}

void asservissement_interface::turn_off_LED_1(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(11, data, length);
}

void asservissement_interface::turn_on_LED_2(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(12, data, length);
}

void asservissement_interface::turn_off_LED_2(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(13, data, length);
}

void asservissement_interface::get_coordinates(int16_t &x, int16_t &y, int16_t &theta){
    uint8_t data[6];
    int length = 6;
    I2cReceiveData(20, data, length);
    DataUnpacker unpacker(data, length);
    x = (int16_t)unpacker.popUint16();
    y = (int16_t)unpacker.popUint16();
    theta = (int16_t)unpacker.popUint16();
}

void asservissement_interface::set_coordinates(int16_t x, int16_t y, int16_t theta){
    DataPacker packer;
    packer.addUint16((int16_t)x);
    packer.addUint16((int16_t)y);
    packer.addUint16((int16_t)theta);
    I2cSendData(21, packer.getData(), packer.getSize());
}

void asservissement_interface::stop(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(30, data, length);
}

void asservissement_interface::set_consigne_lineaire(int16_t x, int16_t y){
    DataPacker packer;
    packer.addUint16((int16_t)x);
    packer.addUint16((int16_t)y);
    I2cSendData(31, packer.getData(), packer.getSize());
}

void asservissement_interface::set_consigne_angulaire(int16_t angle, int16_t rotation){
    DataPacker packer;
    packer.addUint16((int16_t)angle);
    packer.addUint16((int16_t)rotation);
    I2cSendData(32, packer.getData(), packer.getSize());
}

void asservissement_interface::set_consigne_lookAt_forward(int16_t x, int16_t y, int16_t rotation){
    DataPacker packer;
    packer.addUint16((int16_t)x);
    packer.addUint16((int16_t)y);
    packer.addUint16((int16_t)rotation);
    I2cSendData(33, packer.getData(), packer.getSize());
}

void asservissement_interface::set_consigne_lookAt_backward(int16_t x, int16_t y, int16_t rotation){
    DataPacker packer;
    packer.addUint16((int16_t)x);
    packer.addUint16((int16_t)y);
    packer.addUint16((int16_t)rotation);
    I2cSendData(34, packer.getData(), packer.getSize());
}

void asservissement_interface::robot_moving_is_finish(int16_t &resbool){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(40, data, length);
    DataUnpacker unpacker(data, length);
    resbool = (int16_t)unpacker.popUint16();
}

void asservissement_interface::robot_running_is_finish(int16_t &resbool){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(41, data, length);
    DataUnpacker unpacker(data, length);
    resbool = (int16_t)unpacker.popUint16();
}

void asservissement_interface::robot_turning_is_finish(int16_t &resbool){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(42, data, length);
    DataUnpacker unpacker(data, length);
    resbool = (int16_t)unpacker.popUint16();
}

void asservissement_interface::get_linear_error(int16_t &error){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(43, data, length);
    DataUnpacker unpacker(data, length);
    error = (int16_t)unpacker.popUint16();
}

void asservissement_interface::get_angular_error(int16_t &error){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(44, data, length);
    DataUnpacker unpacker(data, length);
    error = (int16_t)unpacker.popUint16();
}

void asservissement_interface::get_braking_distance(int16_t &distance){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(45, data, length);
    DataUnpacker unpacker(data, length);
    distance = (int16_t)unpacker.popUint16();
}

void asservissement_interface::get_robot_running(bool &robot_runnning){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(46, data, length);
    DataUnpacker unpacker(data, length);
    robot_runnning = (bool)unpacker.popUint16();
}

void asservissement_interface::get_directio_side(Direction &direction_side){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(47, data, length);
    DataUnpacker unpacker(data, length);
    direction_side = (Direction)unpacker.popUint16();
}

void asservissement_interface::get_rotation_side(Rotation &rotation_side){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(48, data, length);
    DataUnpacker unpacker(data, length);
    rotation_side = (Rotation)unpacker.popUint16();
}

void asservissement_interface::get_current_consigne(int16_t &x, int16_t &y, int16_t &theta){
    uint8_t data[6];
    int length = 6;
    I2cReceiveData(49, data, length);
    DataUnpacker unpacker(data, length);
    x = (int16_t)unpacker.popUint16();
    y = (int16_t)unpacker.popUint16();
    theta = (int16_t)unpacker.popUint16();
}

void asservissement_interface::disable_motor(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(50, data, length);
}

void asservissement_interface::enable_motor(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(51, data, length);
}

void asservissement_interface::brake_on(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(52, data, length);
}

void asservissement_interface::brake_off(){
    uint8_t* data = nullptr;
    int length = 0;
    I2cSendData(53, data, length);
}

void asservissement_interface::set_max_torque(int16_t max_torque){
    DataPacker packer;
    packer.addUint16((int16_t)max_torque);
    I2cSendData(54, packer.getData(), packer.getSize());
}

void asservissement_interface::set_max_speed_forward(int16_t speed){
    DataPacker packer;
    packer.addUint16((int16_t)speed);
    I2cSendData(60, packer.getData(), packer.getSize());
}

void asservissement_interface::set_max_speed_backward(int16_t speed){
    DataPacker packer;
    packer.addUint16((int16_t)speed);
    I2cSendData(61, packer.getData(), packer.getSize());
}

void asservissement_interface::set_max_speed_trigo(int16_t speed){
    DataPacker packer;
    packer.addUint16((int16_t)speed);
    I2cSendData(62, packer.getData(), packer.getSize());
}

void asservissement_interface::set_max_speed_horloge(int16_t speed){
    DataPacker packer;
    packer.addUint16((int16_t)speed);
    I2cSendData(63, packer.getData(), packer.getSize());
}

void asservissement_interface::go_to_point(int16_t x, int16_t y, Rotation rotation, Direction direction){
    DataPacker packer;
    packer.addUint16((int16_t)x);
    packer.addUint16((int16_t)y);
    packer.addUint16((int16_t)rotation);
    packer.addUint16((int16_t)direction);
    I2cSendData(70, packer.getData(), packer.getSize());
}

void asservissement_interface::go_to_point(int16_t x, int16_t y, int16_t theta, Rotation rotationFirst, Direction direction, Rotation rotationSecond){
    DataPacker packer;
    packer.addUint16((int16_t)x);
    packer.addUint16((int16_t)y);
    packer.addUint16((int16_t)theta);
    packer.addUint16((int16_t)rotationFirst);
    packer.addUint16((int16_t)direction);
    packer.addUint16((int16_t)rotationSecond);
    I2cSendData(71, packer.getData(), packer.getSize());
}

// End auto generation CMD_FONCTION
//***********************************************

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
#include "asservissement_interface.h"
#include "utils/logger.hpp"

//***********************************************
// Start auto generation CMD_FONCTION
// Last generation 2025-04-06 23:08:15: python3 autoGen.py
// DO NOT EDIT
void asservissement_interface::get_version(uint16_t &part1, uint16_t &part2, uint16_t &part3, uint16_t &part4){
    uint8_t data[8];
    int length = 8;
    I2cReceiveData(1, data, length);
    DataUnpacker unpacker(data, length);
    part1 = (uint16_t)unpacker.popUint16();
    part2 = (uint16_t)unpacker.popUint16();
    part3 = (uint16_t)unpacker.popUint16();
    part4 = (uint16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_version : ","part1 ",(int16_t)part1,", ","part2 ",(int16_t)part2,", ","part3 ",(int16_t)part3,", ","part4 ",(int16_t)part4,", ");
}

void asservissement_interface::set_led_1(bool status){
    DataPacker packer;
    packer.addUint16((int16_t)status);
    I2cSendData(10, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_led_1 : ","status ",(int16_t)status,", ");
}

void asservissement_interface::set_led_2(bool status){
    DataPacker packer;
    packer.addUint16((int16_t)status);
    I2cSendData(11, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_led_2 : ","status ",(int16_t)status,", ");
}

void asservissement_interface::get_coordinates(int16_t &x, int16_t &y, int16_t &theta){
    uint8_t data[6];
    int length = 6;
    I2cReceiveData(20, data, length);
    DataUnpacker unpacker(data, length);
    x = (int16_t)unpacker.popUint16();
    y = (int16_t)unpacker.popUint16();
    theta = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_coordinates : ","x ",(int16_t)x,", ","y ",(int16_t)y,", ","theta ",(int16_t)theta,", ");
}

void asservissement_interface::set_coordinates(int16_t x, int16_t y, int16_t theta){
    DataPacker packer;
    packer.addUint16((int16_t)x);
    packer.addUint16((int16_t)y);
    packer.addUint16((int16_t)theta);
    I2cSendData(21, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_coordinates : ","x ",(int16_t)x,", ","y ",(int16_t)y,", ","theta ",(int16_t)theta,", ");
}

void asservissement_interface::stop(){
    uint8_t* data = nullptr;
    int length = 0;
    LOG_ASSERV_SET_INFO("stop");
    I2cSendData(30, data, length);
}

void asservissement_interface::pause(){
    uint8_t* data = nullptr;
    int length = 0;
    LOG_ASSERV_SET_INFO("pause");
    I2cSendData(31, data, length);
}

void asservissement_interface::resume(){
    uint8_t* data = nullptr;
    int length = 0;
    LOG_ASSERV_SET_INFO("resume");
    I2cSendData(32, data, length);
}

void asservissement_interface::go_to_point(int16_t x, int16_t y, Rotation rotation, Direction direction){
    DataPacker packer;
    packer.addUint16((int16_t)x);
    packer.addUint16((int16_t)y);
    packer.addUint16((int16_t)rotation);
    packer.addUint16((int16_t)direction);
    I2cSendData(33, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("go_to_point : ","x ",(int16_t)x,", ","y ",(int16_t)y,", ","rotation ",(int16_t)rotation,", ","direction ",(int16_t)direction,", ");
}

void asservissement_interface::go_to_point(int16_t x, int16_t y, int16_t theta, Rotation rotationFirst, Direction direction, Rotation rotationSecond){
    DataPacker packer;
    packer.addUint16((int16_t)x);
    packer.addUint16((int16_t)y);
    packer.addUint16((int16_t)theta);
    packer.addUint16((int16_t)rotationFirst);
    packer.addUint16((int16_t)direction);
    packer.addUint16((int16_t)rotationSecond);
    I2cSendData(34, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("go_to_point : ","x ",(int16_t)x,", ","y ",(int16_t)y,", ","theta ",(int16_t)theta,", ","rotationFirst ",(int16_t)rotationFirst,", ","direction ",(int16_t)direction,", ","rotationSecond ",(int16_t)rotationSecond,", ");
}

void asservissement_interface::consigne_angulaire(int16_t angle, Rotation rotation){
    DataPacker packer;
    packer.addUint16((int16_t)angle);
    packer.addUint16((int16_t)rotation);
    I2cSendData(35, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("consigne_angulaire : ","angle ",(int16_t)angle,", ","rotation ",(int16_t)rotation,", ");
}

void asservissement_interface::consigne_angulaire(int16_t x, int16_t y, Rotation rotation, Direction direction){
    DataPacker packer;
    packer.addUint16((int16_t)x);
    packer.addUint16((int16_t)y);
    packer.addUint16((int16_t)rotation);
    packer.addUint16((int16_t)direction);
    I2cSendData(36, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("consigne_angulaire : ","x ",(int16_t)x,", ","y ",(int16_t)y,", ","rotation ",(int16_t)rotation,", ","direction ",(int16_t)direction,", ");
}

void asservissement_interface::set_linear_max_speed(int16_t max_speed, int16_t max_acceleration, int16_t max_deceleration){
    DataPacker packer;
    packer.addUint16((int16_t)max_speed);
    packer.addUint16((int16_t)max_acceleration);
    packer.addUint16((int16_t)max_deceleration);
    I2cSendData(37, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_linear_max_speed : ","max_speed ",(int16_t)max_speed,", ","max_acceleration ",(int16_t)max_acceleration,", ","max_deceleration ",(int16_t)max_deceleration,", ");
}

void asservissement_interface::set_angular_max_speed(int16_t max_speed, int16_t max_acceleration, int16_t max_deceleration){
    DataPacker packer;
    packer.addUint16((int16_t)max_speed);
    packer.addUint16((int16_t)max_acceleration);
    packer.addUint16((int16_t)max_deceleration);
    I2cSendData(38, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_angular_max_speed : ","max_speed ",(int16_t)max_speed,", ","max_acceleration ",(int16_t)max_acceleration,", ","max_deceleration ",(int16_t)max_deceleration,", ");
}

int16_t asservissement_interface::get_braking_distance(){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(50, data, length);
    DataUnpacker unpacker(data, length);
    int16_t retPara = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_braking_distance : ",(int16_t)retPara);
    return retPara;
}

int16_t asservissement_interface::get_command_buffer_size(){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(51, data, length);
    DataUnpacker unpacker(data, length);
    int16_t retPara = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_command_buffer_size : ",(int16_t)retPara);
    return retPara;
}

Direction asservissement_interface::get_direction_side(){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(52, data, length);
    DataUnpacker unpacker(data, length);
    Direction retPara = (Direction)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_direction_side : ",(int16_t)retPara);
    return retPara;
}

Rotation asservissement_interface::get_rotation_side(){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(53, data, length);
    DataUnpacker unpacker(data, length);
    Rotation retPara = (Rotation)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_rotation_side : ",(int16_t)retPara);
    return retPara;
}

void asservissement_interface::get_current_target(int16_t &x, int16_t &y, int16_t &theta){
    uint8_t data[6];
    int length = 6;
    I2cReceiveData(54, data, length);
    DataUnpacker unpacker(data, length);
    x = (int16_t)unpacker.popUint16();
    y = (int16_t)unpacker.popUint16();
    theta = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_current_target : ","x ",(int16_t)x,", ","y ",(int16_t)y,", ","theta ",(int16_t)theta,", ");
}

bool asservissement_interface::get_moving_is_done(){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(55, data, length);
    DataUnpacker unpacker(data, length);
    bool retPara = (bool)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_moving_is_done : ",(int16_t)retPara);
    return retPara;
}

bool asservissement_interface::get_running_is_done(){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(56, data, length);
    DataUnpacker unpacker(data, length);
    bool retPara = (bool)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_running_is_done : ",(int16_t)retPara);
    return retPara;
}

bool asservissement_interface::get_turning_is_done(){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(57, data, length);
    DataUnpacker unpacker(data, length);
    bool retPara = (bool)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_turning_is_done : ",(int16_t)retPara);
    return retPara;
}

int16_t asservissement_interface::get_linear_error(){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(58, data, length);
    DataUnpacker unpacker(data, length);
    int16_t retPara = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_linear_error : ",(int16_t)retPara);
    return retPara;
}

int16_t asservissement_interface::get_angular_error(){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(59, data, length);
    DataUnpacker unpacker(data, length);
    int16_t retPara = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_angular_error : ",(int16_t)retPara);
    return retPara;
}

void asservissement_interface::get_current(int16_t &currentRight, int16_t &currentLeft){
    uint8_t data[4];
    int length = 4;
    I2cReceiveData(60, data, length);
    DataUnpacker unpacker(data, length);
    currentRight = (int16_t)unpacker.popUint16();
    currentLeft = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_current : ","currentRight ",(int16_t)currentRight,", ","currentLeft ",(int16_t)currentLeft,", ");
}

void asservissement_interface::get_speed(int16_t &speedRight, int16_t &speedLeft){
    uint8_t data[4];
    int length = 4;
    I2cReceiveData(61, data, length);
    DataUnpacker unpacker(data, length);
    speedRight = (int16_t)unpacker.popUint16();
    speedLeft = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_speed : ","speedRight ",(int16_t)speedRight,", ","speedLeft ",(int16_t)speedLeft,", ");
}

void asservissement_interface::set_motor_state(bool motorEnable){
    DataPacker packer;
    packer.addUint16((int16_t)motorEnable);
    I2cSendData(90, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_motor_state : ","motorEnable ",(int16_t)motorEnable,", ");
}

void asservissement_interface::set_brake_state(bool brakeEnable){
    DataPacker packer;
    packer.addUint16((int16_t)brakeEnable);
    I2cSendData(91, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_brake_state : ","brakeEnable ",(int16_t)brakeEnable,", ");
}

void asservissement_interface::set_max_torque(int16_t max_torque){
    DataPacker packer;
    packer.addUint16((int16_t)max_torque);
    I2cSendData(100, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_max_torque : ","max_torque ",(int16_t)max_torque,", ");
}

void asservissement_interface::set_linear_position_control(int16_t max_speed_for, int16_t max_speed_back, int16_t max_acceleration_for, int16_t max_acceleration_back, int16_t max_deceleration_for, int16_t max_deceleration_back){
    DataPacker packer;
    packer.addUint16((int16_t)max_speed_for);
    packer.addUint16((int16_t)max_speed_back);
    packer.addUint16((int16_t)max_acceleration_for);
    packer.addUint16((int16_t)max_acceleration_back);
    packer.addUint16((int16_t)max_deceleration_for);
    packer.addUint16((int16_t)max_deceleration_back);
    I2cSendData(101, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_linear_position_control : ","max_speed_for ",(int16_t)max_speed_for,", ","max_speed_back ",(int16_t)max_speed_back,", ","max_acceleration_for ",(int16_t)max_acceleration_for,", ","max_acceleration_back ",(int16_t)max_acceleration_back,", ","max_deceleration_for ",(int16_t)max_deceleration_for,", ","max_deceleration_back ",(int16_t)max_deceleration_back,", ");
}

void asservissement_interface::set_angular_position_control(int16_t max_speed_clock, int16_t max_speed_anti, int16_t max_acceleration_clock, int16_t max_acceleration_anti, int16_t max_deceleration_clock, int16_t max_deceleration_anti){
    DataPacker packer;
    packer.addUint16((int16_t)max_speed_clock);
    packer.addUint16((int16_t)max_speed_anti);
    packer.addUint16((int16_t)max_acceleration_clock);
    packer.addUint16((int16_t)max_acceleration_anti);
    packer.addUint16((int16_t)max_deceleration_clock);
    packer.addUint16((int16_t)max_deceleration_anti);
    I2cSendData(102, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_angular_position_control : ","max_speed_clock ",(int16_t)max_speed_clock,", ","max_speed_anti ",(int16_t)max_speed_anti,", ","max_acceleration_clock ",(int16_t)max_acceleration_clock,", ","max_acceleration_anti ",(int16_t)max_acceleration_anti,", ","max_deceleration_clock ",(int16_t)max_deceleration_clock,", ","max_deceleration_anti ",(int16_t)max_deceleration_anti,", ");
}

void asservissement_interface::set_pid_linear_static(int16_t p, int16_t i, int16_t d){
    DataPacker packer;
    packer.addUint16((int16_t)p);
    packer.addUint16((int16_t)i);
    packer.addUint16((int16_t)d);
    I2cSendData(103, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_pid_linear_static : ","p ",(int16_t)p,", ","i ",(int16_t)i,", ","d ",(int16_t)d,", ");
}

void asservissement_interface::set_pid_linear_dynamic(int16_t p, int16_t i, int16_t d){
    DataPacker packer;
    packer.addUint16((int16_t)p);
    packer.addUint16((int16_t)i);
    packer.addUint16((int16_t)d);
    I2cSendData(104, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_pid_linear_dynamic : ","p ",(int16_t)p,", ","i ",(int16_t)i,", ","d ",(int16_t)d,", ");
}

void asservissement_interface::set_pid_angular_static(int16_t p, int16_t i, int16_t d){
    DataPacker packer;
    packer.addUint16((int16_t)p);
    packer.addUint16((int16_t)i);
    packer.addUint16((int16_t)d);
    I2cSendData(105, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_pid_angular_static : ","p ",(int16_t)p,", ","i ",(int16_t)i,", ","d ",(int16_t)d,", ");
}

void asservissement_interface::set_pid_angular_dynamic(int16_t p, int16_t i, int16_t d){
    DataPacker packer;
    packer.addUint16((int16_t)p);
    packer.addUint16((int16_t)i);
    packer.addUint16((int16_t)d);
    I2cSendData(106, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_pid_angular_dynamic : ","p ",(int16_t)p,", ","i ",(int16_t)i,", ","d ",(int16_t)d,", ");
}

void asservissement_interface::set_odometry_metric(int16_t sizeWheelLeft, int16_t sizeWheelRight, int16_t spaceInterWheel){
    DataPacker packer;
    packer.addUint16((int16_t)sizeWheelLeft);
    packer.addUint16((int16_t)sizeWheelRight);
    packer.addUint16((int16_t)spaceInterWheel);
    I2cSendData(107, packer.getData(), packer.getSize());
    LOG_ASSERV_SET_INFO("set_odometry_metric : ","sizeWheelLeft ",(int16_t)sizeWheelLeft,", ","sizeWheelRight ",(int16_t)sizeWheelRight,", ","spaceInterWheel ",(int16_t)spaceInterWheel,", ");
}

int16_t asservissement_interface::get_max_torque(){
    uint8_t data[2];
    int length = 2;
    I2cReceiveData(130, data, length);
    DataUnpacker unpacker(data, length);
    int16_t retPara = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_max_torque : ",(int16_t)retPara);
    return retPara;
}

void asservissement_interface::get_linear_position_control(int16_t &max_speed_for, int16_t &max_speed_back, int16_t &max_acceleration_for, int16_t &max_acceleration_back, int16_t &max_deceleration_for, int16_t &max_deceleration_back){
    uint8_t data[12];
    int length = 12;
    I2cReceiveData(131, data, length);
    DataUnpacker unpacker(data, length);
    max_speed_for = (int16_t)unpacker.popUint16();
    max_speed_back = (int16_t)unpacker.popUint16();
    max_acceleration_for = (int16_t)unpacker.popUint16();
    max_acceleration_back = (int16_t)unpacker.popUint16();
    max_deceleration_for = (int16_t)unpacker.popUint16();
    max_deceleration_back = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_linear_position_control : ","max_speed_for ",(int16_t)max_speed_for,", ","max_speed_back ",(int16_t)max_speed_back,", ","max_acceleration_for ",(int16_t)max_acceleration_for,", ","max_acceleration_back ",(int16_t)max_acceleration_back,", ","max_deceleration_for ",(int16_t)max_deceleration_for,", ","max_deceleration_back ",(int16_t)max_deceleration_back,", ");
}

void asservissement_interface::get_angular_position_control(int16_t &max_speed_clock, int16_t &max_speed_anti, int16_t &max_acceleration_clock, int16_t &max_acceleration_anti, int16_t &max_deceleration_clock, int16_t &max_deceleration_anti){
    uint8_t data[12];
    int length = 12;
    I2cReceiveData(132, data, length);
    DataUnpacker unpacker(data, length);
    max_speed_clock = (int16_t)unpacker.popUint16();
    max_speed_anti = (int16_t)unpacker.popUint16();
    max_acceleration_clock = (int16_t)unpacker.popUint16();
    max_acceleration_anti = (int16_t)unpacker.popUint16();
    max_deceleration_clock = (int16_t)unpacker.popUint16();
    max_deceleration_anti = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_angular_position_control : ","max_speed_clock ",(int16_t)max_speed_clock,", ","max_speed_anti ",(int16_t)max_speed_anti,", ","max_acceleration_clock ",(int16_t)max_acceleration_clock,", ","max_acceleration_anti ",(int16_t)max_acceleration_anti,", ","max_deceleration_clock ",(int16_t)max_deceleration_clock,", ","max_deceleration_anti ",(int16_t)max_deceleration_anti,", ");
}

void asservissement_interface::get_pid_linear_static(int16_t &p, int16_t &i, int16_t &d){
    uint8_t data[6];
    int length = 6;
    I2cReceiveData(133, data, length);
    DataUnpacker unpacker(data, length);
    p = (int16_t)unpacker.popUint16();
    i = (int16_t)unpacker.popUint16();
    d = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_pid_linear_static : ","p ",(int16_t)p,", ","i ",(int16_t)i,", ","d ",(int16_t)d,", ");
}

void asservissement_interface::get_pid_linear_dynamic(int16_t &p, int16_t &i, int16_t &d){
    uint8_t data[6];
    int length = 6;
    I2cReceiveData(134, data, length);
    DataUnpacker unpacker(data, length);
    p = (int16_t)unpacker.popUint16();
    i = (int16_t)unpacker.popUint16();
    d = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_pid_linear_dynamic : ","p ",(int16_t)p,", ","i ",(int16_t)i,", ","d ",(int16_t)d,", ");
}

void asservissement_interface::get_pid_angular_static(int16_t &p, int16_t &i, int16_t &d){
    uint8_t data[6];
    int length = 6;
    I2cReceiveData(135, data, length);
    DataUnpacker unpacker(data, length);
    p = (int16_t)unpacker.popUint16();
    i = (int16_t)unpacker.popUint16();
    d = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_pid_angular_static : ","p ",(int16_t)p,", ","i ",(int16_t)i,", ","d ",(int16_t)d,", ");
}

void asservissement_interface::get_pid_angular_dynamic(int16_t &p, int16_t &i, int16_t &d){
    uint8_t data[6];
    int length = 6;
    I2cReceiveData(136, data, length);
    DataUnpacker unpacker(data, length);
    p = (int16_t)unpacker.popUint16();
    i = (int16_t)unpacker.popUint16();
    d = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_pid_angular_dynamic : ","p ",(int16_t)p,", ","i ",(int16_t)i,", ","d ",(int16_t)d,", ");
}

void asservissement_interface::get_odometry_metric(int16_t &sizeWheelLeft, int16_t &sizeWheelRight, int16_t &spaceInterWheel){
    uint8_t data[6];
    int length = 6;
    I2cReceiveData(137, data, length);
    DataUnpacker unpacker(data, length);
    sizeWheelLeft = (int16_t)unpacker.popUint16();
    sizeWheelRight = (int16_t)unpacker.popUint16();
    spaceInterWheel = (int16_t)unpacker.popUint16();
    LOG_ASSERV_GET_INFO("get_odometry_metric : ","sizeWheelLeft ",(int16_t)sizeWheelLeft,", ","sizeWheelRight ",(int16_t)sizeWheelRight,", ","spaceInterWheel ",(int16_t)spaceInterWheel,", ");
}

void asservissement_interface::start_calibration(){
    uint8_t* data = nullptr;
    int length = 0;
    LOG_ASSERV_SET_INFO("start_calibration");
    I2cSendData(160, data, length);
}

void asservissement_interface::end_calibration(){
    uint8_t* data = nullptr;
    int length = 0;
    LOG_ASSERV_SET_INFO("end_calibration");
    I2cSendData(161, data, length);
}

void asservissement_interface::get_status_calibration(){
    uint8_t* data = nullptr;
    int length = 0;
    LOG_ASSERV_SET_INFO("get_status_calibration");
    I2cSendData(162, data, length);
}

void asservissement_interface::get_all_status(){
    uint8_t* data = nullptr;
    int length = 0;
    LOG_ASSERV_SET_INFO("get_all_status");
    I2cSendData(200, data, length);
}

void asservissement_interface::get_all_error(){
    uint8_t* data = nullptr;
    int length = 0;
    LOG_ASSERV_SET_INFO("get_all_error");
    I2cSendData(201, data, length);
}

void asservissement_interface::get_all_parameter(){
    uint8_t* data = nullptr;
    int length = 0;
    LOG_ASSERV_SET_INFO("get_all_parameter");
    I2cSendData(202, data, length);
}

void asservissement_interface::set_all_parameter(){
    uint8_t* data = nullptr;
    int length = 0;
    LOG_ASSERV_SET_INFO("set_all_parameter");
    I2cSendData(203, data, length);
}

// End auto generation CMD_FONCTION
//***********************************************

bool asservissement_interface::checkVersion(){
    uint8_t part1;
    uint8_t part2;
    uint8_t part3;
    uint8_t part4;
    get_version(part1, part2, part3, part4);
    if( part1 == GIT_COMMIT_SHA_PART1 &&
        part2 == GIT_COMMIT_SHA_PART2 &&
        part3 == GIT_COMMIT_SHA_PART3 &&
        part4 == GIT_COMMIT_SHA_PART4)
    {
        return true;
    }
    return false;
}

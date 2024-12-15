#pragma once

#include "DataPacker.h"
#include "DataUnpacker.h"
#include "type.h"

class Robot_interface
{

public:
    void I2CDataSwitch(uint8_t* data, int size);

//***********************************************
// Start auto generation CMD_ROBOT_INTERFACE
// Last generation 2024-12-15 13:59:15: python3 autoGen.py
// DO NOT EDIT
private:
    virtual void set_led_1(bool status) = 0;
    virtual void set_led_2(bool status) = 0;
    virtual void get_coordinates(int16_t &x, int16_t &y, int16_t &theta) = 0;
    virtual void set_coordinates(int16_t x, int16_t y, int16_t theta) = 0;
    virtual void stop() = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void go_to_point(int16_t x,int16_t y,Rotation rotation = Rotation::SHORTEST, Direction direction = Direction::FORWARD) = 0;
    virtual void go_to_point(int16_t x,int16_t y,int16_t theta, Rotation rotationFirst, Direction direction, Rotation rotationSecond) = 0;
    virtual void consigne_angulaire(int16_t angle, Rotation rotation = Rotation::SHORTEST) = 0;
    virtual void consigne_angulaire(int16_t x, int16_t y, Rotation rotation = Rotation::SHORTEST, Direction direction = Direction::FORWARD) = 0;
    virtual void set_linear_max_speed(int16_t max_speed, int16_t max_acceleration = 0, int16_t max_deceleration = 0) = 0;
    virtual void set_angular_max_speed(int16_t max_speed, int16_t max_acceleration = 0, int16_t max_deceleration = 0) = 0;
    virtual int16_t get_braking_distance() = 0;
    virtual int16_t get_command_buffer_size() = 0;
    virtual Direction get_direction_side() = 0;
    virtual Rotation get_rotation_side() = 0;
    virtual void get_current_target(int16_t &x, int16_t &y, int16_t &theta) = 0;
    virtual bool get_moving_is_done() = 0;
    virtual bool get_running_is_done() = 0;
    virtual bool get_turning_is_done() = 0;
    virtual int16_t get_linear_error() = 0;
    virtual int16_t get_angular_error() = 0;
    virtual void get_current(int16_t &currentRigth, int16_t &currentLeft) = 0;
    virtual void get_speed(int16_t &speedRigth, int16_t &speedLeft) = 0;
    virtual void set_motor_state(bool motorEnable) = 0;
    virtual void set_brake_state(bool brakeEnable) = 0;
    virtual void set_max_torque(int16_t max_torque) = 0;
    virtual void set_linear_position_control(int16_t max_speed_for, int16_t max_speed_back, int16_t max_acceleration_for, int16_t max_acceleration_back, int16_t max_deceleration_for, int16_t max_deceleration_back) = 0;
    virtual void set_angular_position_control(int16_t max_speed_clock, int16_t max_speed_anti, int16_t max_acceleration_clock, int16_t max_acceleration_anti, int16_t max_deceleration_clock, int16_t max_deceleration_anti) = 0;
    virtual void set_pid_linear_static(int16_t p, int16_t i, int16_t d) = 0;
    virtual void set_pid_linear_dynamic(int16_t p, int16_t i, int16_t d) = 0;
    virtual void set_pid_angular_static(int16_t p, int16_t i, int16_t d) = 0;
    virtual void set_pid_angular_dynamic(int16_t p, int16_t i, int16_t d) = 0;
    virtual void set_odometry_metric(int16_t sizeWheelLeft, int16_t sizeWheelRigth, int16_t spaceInterWheel) = 0;
    virtual int16_t get_max_torque() = 0;
    virtual void get_linear_position_control(int16_t &max_speed_for, int16_t &max_speed_back, int16_t &max_acceleration_for, int16_t &max_acceleration_back, int16_t &max_deceleration_for, int16_t &max_deceleration_back) = 0;
    virtual void get_angular_position_control(int16_t &max_speed_clock, int16_t &max_speed_anti, int16_t &max_acceleration_clock, int16_t &max_acceleration_anti, int16_t &max_deceleration_clock, int16_t &max_deceleration_anti) = 0;
    virtual void get_pid_linear_static(int16_t &p, int16_t &i, int16_t &d) = 0;
    virtual void get_pid_linear_dynamic(int16_t &p, int16_t &i, int16_t &d) = 0;
    virtual void get_pid_angular_static(int16_t &p, int16_t &i, int16_t &d) = 0;
    virtual void get_pid_angular_dynamic(int16_t &p, int16_t &i, int16_t &d) = 0;
    virtual void get_odometry_metric(int16_t &sizeWheelLeft, int16_t &sizeWheelRigth, int16_t &spaceInterWheel) = 0;
    virtual void start_calibration() = 0;
    virtual void end_calibration() = 0;
    virtual void get_status_calibration() = 0;
    virtual void get_all_status() = 0;
    virtual void get_all_error() = 0;
    virtual void get_all_parameter() = 0;
    virtual void set_all_parameter() = 0;
// End auto generation CMD_ROBOT_INTERFACE
//***********************************************

private:
    virtual void setReponseBuffer(uint8_t* data, int size) = 0;

};



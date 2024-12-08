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
// Last generation 2024-12-08 16:19:33: python3 autoGen.py
// DO NOT EDIT
private:
    virtual void turn_on_LED_1() = 0;
    virtual void turn_off_LED_1() = 0;
    virtual void turn_on_LED_2() = 0;
    virtual void turn_off_LED_2() = 0;
    virtual void get_coordinates(int16_t &x, int16_t &y, int16_t &theta) = 0;
    virtual void set_coordinates(int16_t x, int16_t y, int16_t theta) = 0;
    virtual void stop() = 0;
    virtual void set_consigne_lineaire(int16_t x, int16_t y) = 0;
    virtual void set_consigne_angulaire(int16_t angle, int16_t rotation) = 0;
    virtual void set_consigne_lookAt_forward(int16_t x, int16_t y, int16_t rotation) = 0;
    virtual void set_consigne_lookAt_backward(int16_t x, int16_t y, int16_t rotation) = 0;
    virtual void robot_moving_is_finish(int16_t &resbool) = 0;
    virtual void robot_running_is_finish(int16_t &resbool) = 0;
    virtual void robot_turning_is_finish(int16_t &resbool) = 0;
    virtual void get_linear_error(int16_t &error) = 0;
    virtual void get_angular_error(int16_t &error) = 0;
    virtual void get_braking_distance(int16_t &distance) = 0;
    virtual void get_robot_running(bool &robot_runnning) = 0;
    virtual void get_directio_side(Direction &direction_side) = 0;
    virtual void get_rotation_side(Rotation &rotation_side) = 0;
    virtual void get_current_consigne(int16_t &x, int16_t &y, int16_t &theta) = 0;
    virtual void disable_motor() = 0;
    virtual void enable_motor() = 0;
    virtual void brake_on() = 0;
    virtual void brake_off() = 0;
    virtual void set_max_torque(int16_t max_torque) = 0;
    virtual void set_max_speed_forward(int16_t speed) = 0;
    virtual void set_max_speed_backward(int16_t speed) = 0;
    virtual void set_max_speed_trigo(int16_t speed) = 0;
    virtual void set_max_speed_horloge(int16_t speed) = 0;
    virtual void go_to_point(int16_t x,int16_t y,Rotation rotation = Rotation::SHORTEST, Direction direction = Direction::FORWARD) = 0;
    virtual void go_to_point(int16_t x,int16_t y,int16_t theta, Rotation rotationFirst, Direction direction, Rotation rotationSecond) = 0;
// End auto generation CMD_ROBOT_INTERFACE
//***********************************************

private:
    virtual void setReponseBuffer(uint8_t* data, int size) = 0;

};



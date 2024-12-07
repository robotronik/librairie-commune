#pragma once

#include "DataPacker.h"
#include "DataUnpacker.h"
#include "type.h"


class asservissement_interface
{
public:

//***********************************************
// Start auto generation CMD_HEADER
// Last generation 2024-12-07 19:59:03: python3 autoGen.py
// DO NOT EDIT
public:
    void turn_on_LED_1();
    void turn_off_LED_1();
    void turn_on_LED_2();
    void turn_off_LED_2();
    void get_coordinates(int16_t &x, int16_t &y, int16_t &theta);
    void set_coordinates(int16_t x, int16_t y, int16_t theta);
    void stop();
    void set_consigne_lineaire(int16_t x, int16_t y);
    void set_consigne_angulaire(int16_t angle, int16_t rotation);
    void set_consigne_lookAt_forward(int16_t x, int16_t y, int16_t rotation);
    void set_consigne_lookAt_backward(int16_t x, int16_t y, int16_t rotation);
    void robot_moving_is_finish(int16_t &resbool);
    void robot_running_is_finish(int16_t &resbool);
    void robot_turning_is_finish(int16_t &resbool);
    void get_linear_error(int16_t &error);
    void get_angular_error(int16_t &error);
    void get_braking_distance(int16_t &distance);
    void get_robot_running(bool &robot_runnning);
    void get_directio_side(Direction &direction_side);
    void get_rotation_side(Rotation &rotation_side);
    void get_current_consigne(int16_t &x, int16_t &y, int16_t &theta);
    void disable_motor();
    void enable_motor();
    void brake_on();
    void brake_off();
    void set_max_torque(int16_t max_torque);
    void set_max_speed_forward(int16_t speed);
    void set_max_speed_backward(int16_t speed);
    void set_max_speed_trigo(int16_t speed);
    void set_max_speed_horloge(int16_t speed);
    void go_to_point(int16_t x,int16_t y,Rotation rotation = ROTATION_DIRECT, Direction direction = MOVE_FORWARD);
    void go_to_point(int16_t x,int16_t y,int16_t theta, Rotation rotationFirst, Direction direction, Rotation rotationSecond);

    //Overloding function
    int16_t get_linear_error(void);
    int16_t get_angular_error();
    int16_t get_braking_distance();

private:

    //Overloding function
// End auto generation CMD_HEADER
//***********************************************

private:
    virtual void I2cSendData (uint8_t command, uint8_t* data, int length) = 0;
    virtual void I2cReceiveData (uint8_t command, uint8_t* data, int length) = 0;

};





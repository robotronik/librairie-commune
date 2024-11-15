#pragma once

#include "DataPacker.h"
#include "DataUnpacker.h"

enum CommandNum {
    // LED Commands
    CMD_TURN_ON_LED_1 = 10,
    CMD_TURN_OFF_LED_1 = 11,
    CMD_TURN_ON_LED_2 = 12,
    CMD_TURN_OFF_LED_2 = 13,

    // Coordinate Commands
    CMD_GET_COORDINATES = 20,
    CMD_SET_COORDINATES = 21,

    // Motion Commands
    CMD_STOP = 30,
    CMD_SET_CONSIGNE_LINEAIRE = 31,
    CMD_SET_CONSIGNE_ANGULAIRE = 32,
    CMD_SET_CONSIGNE_LOOKAT_FORWARD = 33,
    CMD_SET_CONSIGNE_LOOKAT_BACKWARD = 34,

    // Robot Status Commands
    CMD_ROBOT_MOVING_IS_FINISH = 40,
    CMD_ROBOT_RUNNING_IS_FINISH = 41,
    CMD_ROBOT_TURNING_IS_FINISH = 42,
    CMD_GET_LINEAR_ERROR = 43,
    CMD_GET_ANGULAR_ERROR = 44,
    CMD_GET_BRAKING_DISTANCE = 45,

    // Motor Commands
    CMD_DISABLE_MOTOR = 50,
    CMD_ENABLE_MOTOR = 51,
	CMD_MOTOR_52 = 52, //TODO : Docs doesnt talk about these !!
	CMD_MOTOR_53 = 53,
	CMD_MOTOR_TORQUE_54 = 54,

    // Speed Commands
    CMD_SET_MAX_SPEED_FORWARD = 60,
    CMD_SET_MAX_SPEED_BACKWARD = 61,
    CMD_SET_MAX_SPEED_TRIGO = 62,
    CMD_SET_MAX_SPEED_HORLOGE = 63
};

class asservissement_interface
{
public:
    typedef enum {
        ROTATION_DIRECT = 0,
        ROTATION_TRIGO = 1,
        ROTATION_HORRAIRE = 2
    }rotation;

    typedef enum {
        MOVE_FORWARD = 0,
        MOVE_BACKWARD = 1,
    }direction;

public:

    void turn_on_LED_1();           
    void turn_off_LED_1();          
    void turn_on_LED_2();           
    void turn_off_LED_2();          


    void get_coordinates(int16_t &x, int16_t &y, int16_t &theta);  
    void set_coordinates(int16_t x, int16_t y, int16_t theta);     


    void stop();
    void brake(bool enable);
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
    int16_t get_linear_error();
    int16_t get_angular_error();
    int16_t get_braking_distance();


    void disable_motor();          
    void enable_motor();           


    void set_max_speed_forward(int16_t speed);      
    void set_max_speed_backward(int16_t speed);     
    void set_max_speed_trigo(int16_t speed);        
    void set_max_speed_horloge(int16_t speed);


    virtual void I2cSendData (uint8_t command, uint8_t* data, int length) = 0;
    virtual void I2cReceiveData (uint8_t command, uint8_t* data, int length) = 0;

};



    

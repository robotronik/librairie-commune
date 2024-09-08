#pragma once

#include "DataPacker.h"
#include "DataUnpacker.h"


class asservissement_interface
{
private:
    /* data */
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


    void disable_motor();          
    void enable_motor();           


    void set_max_speed_forward(int16_t speed);      
    void set_max_speed_backward(int16_t speed);     
    void set_max_speed_trigo(int16_t speed);        
    void set_max_speed_horloge(int16_t speed);


    virtual void I2cSendData (uint8_t command, uint8_t* data, int length) = 0;
    virtual void I2cReceiveData (uint8_t command, uint8_t* data, int length) = 0;

};



    

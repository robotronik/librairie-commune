# Robot Command API Documentation

## Introduction
This document provides a comprehensive overview of the available commands in the Robot Command API. Each function is detailed with its purpose, parameters, and usage.


<!-- *********************************************** -->
<!-- Start auto generation CMD_DOC -->
<!-- Last generation 2024-12-08 19:31:48: python3 autoGen.py -->
<!-- DO NOT EDIT -->
## Table of Contents
1. [LED_STATUS](#LED_STATUS)
2. [COORDINATE](#COORDINATE)
3. [COMMANDE](#COMMANDE)
4. [MOTOR](#MOTOR)
5. [PARAMETER](#PARAMETER)
6. [COMMANDE](#COMMANDE)
## 1. LED_STATUS

#### turn_on_LED_1
**Return**: void  
**Parameters**: void  
**Description**: turn led 1 on  


---

#### turn_off_LED_1
**Return**: void  
**Parameters**: void  
**Description**: turn led 1 on  


---

#### turn_on_LED_2
**Return**: void  
**Parameters**: void  
**Description**: turn led 1 on  


---

#### turn_off_LED_2
**Return**: void  
**Parameters**: void  
**Description**: turn led 1 on  


---

## 2. COORDINATE

#### get_coordinates
**Return**: void  
**Parameters**:  
- `int16_t &x`  
- ` int16_t &y`  
- ` int16_t &theta`  

**Description**: get coordinates (in mm and degres)  


---

#### set_coordinates
**Return**: void  
**Parameters**:  
- `int16_t x`  
- ` int16_t y`  
- ` int16_t theta`  

**Description**: set coordinates (in mm and degres)  


---

## 3. COMMANDE

#### stop
**Return**: void  
**Parameters**: void  
**Description**: stop (a cleanne deceleration is provide and the commande buffer is clean  


---

#### set_consigne_lineaire
**Return**: void  
**Parameters**:  
- `int16_t x`  
- ` int16_t y`  



---

#### set_consigne_angulaire
**Return**: void  
**Parameters**:  
- `int16_t angle`  
- ` int16_t rotation`  



---

#### set_consigne_lookAt_forward
**Return**: void  
**Parameters**:  
- `int16_t x`  
- ` int16_t y`  
- ` int16_t rotation`  



---

#### set_consigne_lookAt_backward
**Return**: void  
**Parameters**:  
- `int16_t x`  
- ` int16_t y`  
- ` int16_t rotation`  



---

#### robot_moving_is_finish
**Return**: void  
**Parameters**:  
- `int16_t &resbool`  



---

#### robot_running_is_finish
**Return**: void  
**Parameters**:  
- `int16_t &resbool`  



---

#### robot_turning_is_finish
**Return**: void  
**Parameters**:  
- `int16_t &resbool`  



---

#### get_linear_error
**Return**: void  
**Parameters**:  
- `int16_t &error`  



---

#### get_angular_error
**Return**: void  
**Parameters**:  
- `int16_t &error`  



---

#### get_braking_distance
**Return**: void  
**Parameters**:  
- `int16_t &distance`  



---

#### get_robot_running
**Return**: void  
**Parameters**:  
- `bool &robot_runnning`  



---

#### get_directio_side
**Return**: void  
**Parameters**:  
- `Direction &direction_side`  



---

#### get_rotation_side
**Return**: void  
**Parameters**:  
- `Rotation &rotation_side`  



---

#### get_current_consigne
**Return**: void  
**Parameters**:  
- `int16_t &x`  
- ` int16_t &y`  
- ` int16_t &theta`  



---

## 4. MOTOR

#### disable_motor
**Return**: void  
**Parameters**: void  


---

#### enable_motor
**Return**: void  
**Parameters**: void  


---

#### brake_on
**Return**: void  
**Parameters**: void  


---

#### brake_off
**Return**: void  
**Parameters**: void  


---

## 5. PARAMETER

#### set_max_torque
**Return**: void  
**Parameters**:  
- `int16_t max_torque`  



---

#### set_max_speed_forward
**Return**: void  
**Parameters**:  
- `int16_t speed`  



---

#### set_max_speed_backward
**Return**: void  
**Parameters**:  
- `int16_t speed`  



---

#### set_max_speed_trigo
**Return**: void  
**Parameters**:  
- `int16_t speed`  



---

#### set_max_speed_horloge
**Return**: void  
**Parameters**:  
- `int16_t speed`  



---

## 6. COMMANDE

#### go_to_point
**Return**: void  
**Parameters**:  
- `int16_t x`  
- `int16_t y`  
- `Rotation rotation = Rotation::SHORTEST`  
- ` Direction direction = Direction::FORWARD`  



---

#### go_to_point
**Return**: void  
**Parameters**:  
- `int16_t x`  
- `int16_t y`  
- `int16_t theta`  
- ` Rotation rotationFirst`  
- ` Direction direction`  
- ` Rotation rotationSecond`  



---

#### get_linear_error
**Return**:  
- `int16_t`  

**Parameters**: void  


---

#### get_angular_error
**Return**:  
- `int16_t`  

**Parameters**: void  


---

#### get_braking_distance
**Return**:  
- `int16_t`  

**Parameters**: void  


---

<!-- End auto generation CMD_DOC -->
<!--*********************************************** -->

## Notes
- All parameters with `&` are references and will be modified to store results or inputs.
- Ensure proper initialization and configuration of the robot before using these commands.


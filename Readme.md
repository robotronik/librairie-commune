# Robot Command API Documentation

## Introduction
This document provides a comprehensive overview of the available commands in the Robot Command API. Each function is detailed with its purpose, parameters, and usage.


<!-- *********************************************** -->
<!-- Start auto generation CMD_DOC -->
<!-- Last generation 2024-12-11 17:28:34: python3 autoGen.py -->
<!-- DO NOT EDIT -->
## Table of Contents
1. [LED](#LED)
2. [COORDINATE](#COORDINATE)
3. [COMMANDE](#COMMANDE)
4. [STATUS](#STATUS)
5. [MOTOR](#MOTOR)
6. [PARAMETER](#PARAMETER)
7. [CALIBRATION](#CALIBRATION)
8. [OPTIMIZATION](#OPTIMIZATION)
## 1. LED

#### set_led_1
**Return**: void  
**Parameters**:  
- `bool status`  

**Description**: set status led 1  
**Usage**: debug i2c interface  


---

#### set_led_2
**Return**: void  
**Parameters**:  
- `bool status`  

**Description**: set status led 2  
**Usage**: debug i2c interface  


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
**Description**: stop (a clean deceleration is provide and the commande buffer is clean)  
**Usage**: ex: stop if you want change the path  


---

#### pause
**Return**: void  
**Parameters**: void  
**Description**: pause (a clean deceleration is provide and the current commande and all next commande is keep for a future resume)  
**Usage**: ex: when you want to wait for what the opponent robot pass (you can use stop after pause if you don't want to resume)  


---

#### resume
**Return**: void  
**Parameters**: void  
**Description**: resume after pause  
**Usage**: ex: resume when the opponent robot is no longer in front  


---

#### go_to_point
**Return**: void  
**Parameters**:  
- `int16_t x`  
- `int16_t y`  
- `Rotation rotation = Rotation::SHORTEST`  
- ` Direction direction = Direction::FORWARD`  

**Description**: the robot go to point  


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

**Description**: the robot go to point and turn at the final position  


---

#### consigne_angulaire
**Return**: void  
**Parameters**:  
- `int16_t angle`  
- ` Rotation rotation = Rotation::SHORTEST`  

**Description**: to make the robot turn on itself by indicating an angle  


---

#### consigne_angulaire
**Return**: void  
**Parameters**:  
- `int16_t x`  
- ` int16_t y`  
- ` Rotation rotation = Rotation::SHORTEST`  
- ` Direction direction = Direction::FORWARD`  

**Description**: to make the robot turn on itself by indicating a point to look  


---

## 4. STATUS

#### get_braking_distance
**Return**:  
- `int16_t`  

**Parameters**: void  
**Description**: give the distance to stop the robot when stop or pause is use (not applicable with brake)  
**Usage**: This allows you to determine the distance at which to start braking. Used with lidar, it allows you to determine when to start stopping the robot  


---

#### get_commande_buffer_size
**Return**:  
- `int16_t`  

**Parameters**: void  
**Description**: number of command remaining (with the current command)  
**Usage**: can be use to determine the free space in the command buffer if you want send a path with lot of got to point or angle. It can also be use to dertermine when the robot movement is finish  


---

#### get_direction_side
**Return**:  
- `Direction`  

**Parameters**: void  
**Description**: give the direction (NONE when the robot don't move backward or forward)  
**Usage**: usefull to dermine wich side of the lidar point is usefull to look when you want avoid the opponent robot  


---

#### get_rotation_side
**Return**:  
- `Rotation`  

**Parameters**: void  
**Description**: give the rotation  


---

#### get_current_target
**Return**: void  
**Parameters**:  
- `int16_t &x`  
- ` int16_t &y`  
- ` int16_t &theta`  

**Description**: get current static consigne (angular consigne may change as robot moves forward or backward to compensate path variations)  


---

#### get_current_target
**Return**: void  
**Parameters**: void  
**Description**: Overloading  


---

#### get_moving_is_done
**Return**:  
- `int16_t`  

**Parameters**: void  
**Description**: return true when the current consigne is finish (is equal to between get_running_is_finish or get_turning_is_finish)  
**Usage**: when you pause the robot, to know when the robot is stop because you can't use get_commande_buffer_size. Otherwise, prefere to use get_commande_buffer_size.  


---

#### get_running_is_done
**Return**:  
- `int16_t`  

**Parameters**: void  
**Description**: return true when the linear current consigne is finish  


---

#### get_turning_is_done
**Return**:  
- `int16_t`  

**Parameters**: void  
**Description**: return true when the angular current consigne is finish  


---

#### get_linear_error
**Return**:  
- `int16_t`  

**Parameters**:  
- `int16_t &error`  

**Description**: return the error between the dynamic consigne and the robot  


---

#### get_angular_error
**Return**:  
- `int16_t`  

**Parameters**:  
- `int16_t &error`  

**Description**: return the error between the dynamic consigne and the robot  


---

#### get_current
**Return**: void  
**Parameters**:  
- `int16_t &currentRigth`  
- ` int16_t &currentLeft`  

**Description**: gives the current average since the last reading for each motor  


---

#### get_speed
**Return**: void  
**Parameters**:  
- `int16_t &speedRigth`  
- ` int16_t &speedLeft`  

**Description**: gives the speed average since the last reading for each motor  


---

## 5. MOTOR

#### set_motor_state
**Return**: void  
**Parameters**:  
- `bool motorEnable`  

**Description**: enable enables the motors (disabled at startup)  
**Usage**: enable motor at the begening of a match and stop motor when the main program is finish or kill to avoid problems and to move freely the robot  


---

#### set_brake_state
**Return**: void  
**Parameters**:  
- `bool brakeEnable`  

**Description**: enable brake (the brake are disable at startup).  
**Usage**: use to stop quickly the robot, but prefere to use pause or stop  


---

## 6. PARAMETER

#### set_max_torque
**Return**: void  
**Parameters**:  
- `int16_t max_torque`  

**Description**: set max torque  
**Usage**: constant  


---

#### set_max_speed_forward
**Return**: void  
**Parameters**:  
- `int16_t speed`  

**Description**: set max speed forward  
**Usage**: constant  


---

#### set_max_speed_backward
**Return**: void  
**Parameters**:  
- `int16_t speed`  

**Description**: set max speed backward  
**Usage**: constant  


---

#### set_max_speed_trigo
**Return**: void  
**Parameters**:  
- `int16_t speed`  

**Description**: set max speed anticlockwise  
**Usage**: constant  


---

#### set_max_speed_horloge
**Return**: void  
**Parameters**:  
- `int16_t speed`  

**Description**: set max speed clockwise  
**Usage**: constant  


---

#### set_pid_linear_static
**Return**: void  
**Parameters**:  
- `int16_t p`  
- ` int16_t i`  
- ` int16_t d`  

**Description**: set pid linear static  
**Usage**: constant  


---

#### set_pid_linear_dynamic
**Return**: void  
**Parameters**:  
- `int16_t p`  
- ` int16_t i`  
- ` int16_t d`  

**Description**: set pid linear dynamic  
**Usage**: constant  


---

#### set_pid_angular_static
**Return**: void  
**Parameters**:  
- `int16_t p`  
- ` int16_t i`  
- ` int16_t d`  

**Description**: set pid angular static  
**Usage**: constant  


---

#### set_pid_angular_dynamic
**Return**: void  
**Parameters**:  
- `int16_t p`  
- ` int16_t i`  
- ` int16_t d`  

**Description**: set pid angular dynamic  
**Usage**: constant  


---

#### set_odometry_metric
**Return**: void  
**Parameters**:  
- `int16_t sizeWheelLeft`  
- ` int16_t sizeWheelRigth`  
- ` int16_t spaceInterWheel`  

**Description**: set odometry metric  
**Usage**: constant  


---

#### get_max_torque
**Return**:  
- `int16_t`  

**Parameters**:  
- `int16_t max_torque`  

**Description**: get max torque  
**Usage**: constant  


---

#### get_max_speed_forward
**Return**:  
- `int16_t`  

**Parameters**:  
- `int16_t speed`  

**Description**: get max speed forward  
**Usage**: constant  


---

#### get_max_speed_backward
**Return**:  
- `int16_t`  

**Parameters**:  
- `int16_t speed`  

**Description**: get max speed backward  
**Usage**: constant  


---

#### get_max_speed_trigo
**Return**:  
- `int16_t`  

**Parameters**:  
- `int16_t speed`  

**Description**: get max speed anticlockwise  
**Usage**: constant  


---

#### get_max_speed_horloge
**Return**:  
- `int16_t`  

**Parameters**:  
- `int16_t speed`  

**Description**: get max speed clockwise  
**Usage**: constant  


---

#### get_pid_linear_static
**Return**: void  
**Parameters**:  
- `int16_t &p`  
- ` int16_t &i`  
- ` int16_t &d`  

**Description**: get pid linear static  
**Usage**: constant  


---

#### get_pid_linear_dynamic
**Return**: void  
**Parameters**:  
- `int16_t &p`  
- ` int16_t &i`  
- ` int16_t &d`  

**Description**: get pid linear dynamic  
**Usage**: constant  


---

#### get_pid_angular_static
**Return**: void  
**Parameters**:  
- `int16_t &p`  
- ` int16_t &i`  
- ` int16_t &d`  

**Description**: get pid angular static  
**Usage**: constant  


---

#### get_pid_angular_dynamic
**Return**: void  
**Parameters**:  
- `int16_t &p`  
- ` int16_t &i`  
- ` int16_t &d`  

**Description**: get pid angular dynamic  
**Usage**: constant  


---

#### get_odometry_metric
**Return**: void  
**Parameters**:  
- `int16_t &sizeWheelLeft`  
- ` int16_t &sizeWheelRigth`  
- ` int16_t &spaceInterWheel`  

**Description**: get odometry metric  
**Usage**: constant  


---

## 7. CALIBRATION

#### start_calibration
**Return**: void  
**Parameters**: void  
**Description**: future (calculate odometrie metric)  


---

#### end_calibration
**Return**: void  
**Parameters**: void  
**Description**: future (calculate odometrie metric)  


---

#### get_status_calibration
**Return**: void  
**Parameters**: void  
**Description**: future (calculate odometrie metric)  


---

## 8. OPTIMIZATION

#### get_all_status
**Return**: void  
**Parameters**: void  
**Description**: future (get all informations in one command for more optimisation)  
**Usage**: to optimise the main code with a loop: get, compute, set  


---

#### get_all_error
**Return**: void  
**Parameters**: void  
**Description**: future (get all informations in one command for more optimisation)  
**Usage**: to optimise the main code with a loop: get, compute, set  


---

#### get_all_parameter
**Return**: void  
**Parameters**: void  
**Description**: future (get all informations in one command for more optimisation)  
**Usage**: to optimise the main code with a loop: get, compute, set  


---

#### set_all_parameter
**Return**: void  
**Parameters**: void  
**Description**: future (set all informations in one command for more optimisation)  
**Usage**: to optimise the main code with a loop: get, compute, set  


---

<!-- End auto generation CMD_DOC -->
<!--*********************************************** -->

## Notes
- All parameters with `&` are references and will be modified to store results or inputs.
- Ensure proper initialization and configuration of the robot before using these commands.


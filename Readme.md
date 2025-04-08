# Robot Command API Documentation

## Introduction
This document provides a comprehensive overview of the interface between the asservissement program in the STM32 and the robot's global program. This interface offers lot of functions to control the robot, which are grouped into different categories.

A significant portion of the interface is automatically generated from a CSV file, which also includes part of this documentation.

The beginning of this document explains general information about the interface, followed by detailed descriptions of each function with its purpose, parameters, and usage.

## Global information

### Categories

| Category      | usage      |
|------------|----------------|
| LED | Use to debug |
| COORDINATE | get or set coordinate |
| COMMANDE | Send all commands to move the robot from a point A to B. You can send until 1000 basic command in one time and the robot will execute all command successively. The get buffer size tells you how many commands the robot still has to execute. |
| STATUS | Give all robot status|
| MOTOR | Instante command apply to motor. Use only for emerengcy or at the beging or the end of the match  |
| PARAMETER | maximum static parameter (don't change during the match) |
| CALIBRATION | TODO use to calibrate the odometrie (don't change during the match) |
| OPTIMIZATION | TODO |

### exemple

This is a small example of a move with a collect and an avoid action in 2-step (wait 5 seconds if the opposing robot leaves, otherwise abandon the action)

```C++
robot.set_motor_state(true);        //enable the motor if not
robot.set_coordinates(0,0,90);      //set the coordinate if differente of 0
robot.go_to_point(500,500);
robot.go_to_point(1000,500);
robot.go_to_point(1000,1000);
robot.set_linear_max_speed(20);     //go slowly for the next action
robot.go_to_point(1000,1300);       //action like clolect something
robot.set_linear_max_speed(0);      //reset slowly speed with default value

while(robot.get_command_buffer_size() != 0) //wait end of all action above
{
    if(robot.get_direction_side() == Direction::FORWARD){
        if(robot.get_braking_distance() > lidar.collideDistanceFORWARD()){ //stop befor collide the opponent
            if(robotIsStall == false){ //to send only one time pause command
                robot.pause();
                robotIsStall = true;
            }
            if(WAIT_5S_BEFORE_TO_FIND_A_NEW_PATH_OR_AN_OTHER_ACTION){
                robot.stop(); //to reset the command buffer and delete all command not yet execute
                break;
            }
        }
        else{
            if(robotIsStall == true){ //to send only one time resume
                robot.resume();
                robotIsStall = false;
            }
        }
    }
    else if(robot.get_direction_side() == Direction::BACKWARD){
        if(robot.get_braking_distance > lidar.collideDistanceBACKWARD())
        // ....
    }
}

```
### Enum
list of enum type use in the interface
```C++
enum class Rotation {
    NONE = 0,
    SHORTEST = 1,
    ANTICLOCKWISE = 2,
    CLOCKWISE = 3
};
```
```C++
enum class Direction {
    NONE = 0,
    FORWARD = 1,
    BACKWARD = 2
};
```
### Units

| type      | unit      |
|------------|----------------|
| linear position    | mm    |
| angular position    | degres    |
| linear speed    | mm/s    |
| angular speed    | degres/s    |
| linear acceleration/decelaration   | mm/s²    |
| angular acceleration/decelaration   | degres/s²    |
| torque   | TODO    |
| current   | TODO    |

### Regernerate contente
Part of files are auto generate depending of the csv file commands.csv. Use autoGen.py to regenerate the content.
```bash
python3 autoGen.py
```

<!-- *********************************************** -->
<!-- Start auto generation CMD_DOC -->
<!-- Last generation 2025-04-08 18:43:32: python3 autoGen.py -->
<!-- DO NOT EDIT -->
## Table of focntions
1. [GLOBAL](#GLOBAL)
2. [LED](#LED)
3. [COORDINATE](#COORDINATE)
4. [COMMAND](#COMMAND)
5. [STATUS](#STATUS)
6. [MOTOR](#MOTOR)
7. [PARAMETER](#PARAMETER)
8. [CALIBRATION](#CALIBRATION)
9. [OPTIMIZATION](#OPTIMIZATION)
## 1. GLOBAL

#### get_version
**Return**: void  
**Parameters**:  
- `uint16_t &part1`  
- ` uint16_t &part2`  
- ` uint16_t &part3`  
- ` uint16_t &part4`  

**Description**: get version of the librairie-commune  


---

## 2. LED

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

## 3. COORDINATE

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

## 4. COMMAND

#### stop
**Return**: void  
**Parameters**: void  
**Description**: stop (a clean deceleration is provide and the command buffer is clean)  
**Usage**: ex: stop if you want change the path  


---

#### pause
**Return**: void  
**Parameters**: void  
**Description**: pause (a clean deceleration is provide and the current command and all next command is keep for a future resume)  
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
- ` Rotation rotationFirst = Rotation::SHORTEST`  
- ` Direction direction = Direction::FORWARD`  
- ` Rotation rotationSecond = Rotation::SHORTEST`  

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

#### set_linear_max_speed
**Return**: void  
**Parameters**:  
- `int16_t max_speed`  
- ` int16_t max_acceleration = 0`  
- ` int16_t max_deceleration = 0`  

**Description**: set max speed for nexts commands. Use a value of 0 to reset with the max value set in parameter  
**Usage**: limit speed for an action  


---

#### set_angular_max_speed
**Return**: void  
**Parameters**:  
- `int16_t max_speed`  
- ` int16_t max_acceleration = 0`  
- ` int16_t max_deceleration = 0`  

**Description**: set max speed for nexts commands. Use a value of 0 to reset with the max value set in parameter  
**Usage**: limit speed for an action  


---

## 5. STATUS

#### get_braking_distance
**Return**:  
- `int16_t`  

**Parameters**: void  
**Description**: give the distance to stop the robot when stop or pause is use (not applicable with brake)  
**Usage**: This allows you to determine the distance at which to start braking. Used with lidar, it allows you to determine when to start stopping the robot  


---

#### get_command_buffer_size
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
**Description**: give the direction (NONE when the robot don't move backward or forward). When the robot is paused, it continues to give the direction it should go when resuming  
**Usage**: usefull to dermine wich side of the lidar point is usefull to look when you want avoid the opponent robot  


---

#### get_rotation_side
**Return**:  
- `Rotation`  

**Parameters**: void  
**Description**: give the rotation. When the robot is paused, it continues to give the rotation it should go when resuming  


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
- `bool`  

**Parameters**: void  
**Description**: return true when the current consigne is finish (is equal to between get_running_is_finish or get_turning_is_finish)  
**Usage**: when you pause the robot, to know when the robot is stop because you can't use get_commande_buffer_size. Otherwise, prefere to use get_commande_buffer_size.  


---

#### get_running_is_done
**Return**:  
- `bool`  

**Parameters**: void  
**Description**: return true when the linear current consigne is finish  


---

#### get_turning_is_done
**Return**:  
- `bool`  

**Parameters**: void  
**Description**: return true when the angular current consigne is finish  


---

#### get_linear_error
**Return**:  
- `int16_t`  

**Parameters**: void  
**Description**: return the error between the dynamic consigne and the robot  


---

#### get_angular_error
**Return**:  
- `int16_t`  

**Parameters**: void  
**Description**: return the error between the dynamic consigne and the robot  


---

#### get_current
**Return**: void  
**Parameters**:  
- `int16_t &currentRight`  
- ` int16_t &currentLeft`  

**Description**: gives the current average since the last reading for each motor  


---

#### get_speed
**Return**: void  
**Parameters**:  
- `int16_t &speedRight`  
- ` int16_t &speedLeft`  

**Description**: gives the speed average since the last reading for each motor  


---

## 6. MOTOR

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

## 7. PARAMETER

#### set_max_torque
**Return**: void  
**Parameters**:  
- `int16_t max_torque`  

**Description**: set max torque  
**Usage**: constant  


---

#### set_linear_position_control
**Return**: void  
**Parameters**:  
- `int16_t max_speed_for`  
- ` int16_t max_speed_back`  
- ` int16_t max_acceleration_for`  
- ` int16_t max_acceleration_back`  
- ` int16_t max_deceleration_for`  
- ` int16_t max_deceleration_back`  

**Description**: set max speed forward  
**Usage**: constant  


---

#### set_angular_position_control
**Return**: void  
**Parameters**:  
- `int16_t max_speed_clock`  
- ` int16_t max_speed_anti`  
- ` int16_t max_acceleration_clock`  
- ` int16_t max_acceleration_anti`  
- ` int16_t max_deceleration_clock`  
- ` int16_t max_deceleration_anti`  

**Description**: set max speed forward  
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
- ` int16_t sizeWheelRight`  
- ` int16_t spaceInterWheel`  

**Description**: set odometry metric  
**Usage**: constant  


---

#### get_max_torque
**Return**:  
- `int16_t`  

**Parameters**: void  
**Description**: get max torque  
**Usage**: constant  


---

#### get_linear_position_control
**Return**: void  
**Parameters**:  
- `int16_t &max_speed_for`  
- ` int16_t &max_speed_back`  
- ` int16_t &max_acceleration_for`  
- ` int16_t &max_acceleration_back`  
- ` int16_t &max_deceleration_for`  
- ` int16_t &max_deceleration_back`  

**Description**: set max speed forward  
**Usage**: constant  


---

#### get_angular_position_control
**Return**: void  
**Parameters**:  
- `int16_t &max_speed_clock`  
- ` int16_t &max_speed_anti`  
- ` int16_t &max_acceleration_clock`  
- ` int16_t &max_acceleration_anti`  
- ` int16_t &max_deceleration_clock`  
- ` int16_t &max_deceleration_anti`  

**Description**: set max speed forward  
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
- ` int16_t &sizeWheelRight`  
- ` int16_t &spaceInterWheel`  

**Description**: get odometry metric  
**Usage**: constant  


---

## 8. CALIBRATION

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

## 9. OPTIMIZATION

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


---

#### interface_version_matches
**Return**: bool  
**Parameters**: void  
**Description**: return true if the compiled interface of the stm32 and the main program is identical (same commit)  


---

## Notes
- All parameters with `&` are references and will be modified to store results or inputs.
- Ensure proper initialization and configuration of the robot before using these commands.


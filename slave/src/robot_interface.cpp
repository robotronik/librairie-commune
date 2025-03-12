#include "robot_interface.h"
#include "uart.h"

//***********************************************
// Start auto generation CMD_ROBOT_FUNCTION_INTERFACE
// Last generation 2025-03-12 19:24:16: python3 autoGen.py
// DO NOT EDIT
void Robot_interface::I2CDataSwitch(uint8_t* data, int size){
    uint8_t dataPack[64];
    DataPacker packer(dataPack, 64);
    DataUnpacker unPacker(&data[1], size - 1);
    switch (data[0]){
        case 10:{
            bool status;
            status = (bool)unPacker.popUint16();
            set_led_1(status);
            break;
        }
        case 11:{
            bool status;
            status = (bool)unPacker.popUint16();
            set_led_2(status);
            break;
        }
        case 20:{
            int16_t x;
            int16_t y;
            int16_t theta;
            get_coordinates(x, y, theta);
            packer.addUint16((int16_t)x);
            packer.addUint16((int16_t)y);
            packer.addUint16((int16_t)theta);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 21:{
            int16_t x;
            int16_t y;
            int16_t theta;
            x = (int16_t)unPacker.popUint16();
            y = (int16_t)unPacker.popUint16();
            theta = (int16_t)unPacker.popUint16();
            set_coordinates(x, y, theta);
            break;
        }
        case 30:{
            stop();
            break;
        }
        case 31:{
            pause();
            break;
        }
        case 32:{
            resume();
            break;
        }
        case 33:{
            int16_t x;
            int16_t y;
            Rotation rotation;
            Direction direction;
            x = (int16_t)unPacker.popUint16();
            y = (int16_t)unPacker.popUint16();
            rotation = (Rotation)unPacker.popUint16();
            direction = (Direction)unPacker.popUint16();
            go_to_point(x, y, rotation, direction);
            break;
        }
        case 34:{
            int16_t x;
            int16_t y;
            int16_t theta;
            Rotation rotationFirst;
            Direction direction;
            Rotation rotationSecond;
            x = (int16_t)unPacker.popUint16();
            y = (int16_t)unPacker.popUint16();
            theta = (int16_t)unPacker.popUint16();
            rotationFirst = (Rotation)unPacker.popUint16();
            direction = (Direction)unPacker.popUint16();
            rotationSecond = (Rotation)unPacker.popUint16();
            go_to_point(x, y, theta, rotationFirst, direction, rotationSecond);
            break;
        }
        case 35:{
            int16_t angle;
            Rotation rotation;
            angle = (int16_t)unPacker.popUint16();
            rotation = (Rotation)unPacker.popUint16();
            consigne_angulaire(angle, rotation);
            break;
        }
        case 36:{
            int16_t x;
            int16_t y;
            Rotation rotation;
            Direction direction;
            x = (int16_t)unPacker.popUint16();
            y = (int16_t)unPacker.popUint16();
            rotation = (Rotation)unPacker.popUint16();
            direction = (Direction)unPacker.popUint16();
            consigne_angulaire(x, y, rotation, direction);
            break;
        }
        case 37:{
            int16_t max_speed;
            int16_t max_acceleration;
            int16_t max_deceleration;
            max_speed = (int16_t)unPacker.popUint16();
            max_acceleration = (int16_t)unPacker.popUint16();
            max_deceleration = (int16_t)unPacker.popUint16();
            set_linear_max_speed(max_speed, max_acceleration, max_deceleration);
            break;
        }
        case 38:{
            int16_t max_speed;
            int16_t max_acceleration;
            int16_t max_deceleration;
            max_speed = (int16_t)unPacker.popUint16();
            max_acceleration = (int16_t)unPacker.popUint16();
            max_deceleration = (int16_t)unPacker.popUint16();
            set_angular_max_speed(max_speed, max_acceleration, max_deceleration);
            break;
        }
        case 50:{
            int16_t retParam;
            retParam = get_braking_distance();
            packer.addUint16((int16_t)retParam);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 51:{
            int16_t retParam;
            retParam = get_command_buffer_size();
            packer.addUint16((int16_t)retParam);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 52:{
            Direction retParam;
            retParam = get_direction_side();
            packer.addUint16((int16_t)retParam);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 53:{
            Rotation retParam;
            retParam = get_rotation_side();
            packer.addUint16((int16_t)retParam);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 54:{
            int16_t x;
            int16_t y;
            int16_t theta;
            get_current_target(x, y, theta);
            packer.addUint16((int16_t)x);
            packer.addUint16((int16_t)y);
            packer.addUint16((int16_t)theta);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 55:{
            bool retParam;
            retParam = get_moving_is_done();
            packer.addUint16((int16_t)retParam);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 56:{
            bool retParam;
            retParam = get_running_is_done();
            packer.addUint16((int16_t)retParam);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 57:{
            bool retParam;
            retParam = get_turning_is_done();
            packer.addUint16((int16_t)retParam);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 58:{
            int16_t retParam;
            retParam = get_linear_error();
            packer.addUint16((int16_t)retParam);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 59:{
            int16_t retParam;
            retParam = get_angular_error();
            packer.addUint16((int16_t)retParam);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 60:{
            int16_t currentRight;
            int16_t currentLeft;
            get_current(currentRight, currentLeft);
            packer.addUint16((int16_t)currentRight);
            packer.addUint16((int16_t)currentLeft);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 61:{
            int16_t speedRight;
            int16_t speedLeft;
            get_speed(speedRight, speedLeft);
            packer.addUint16((int16_t)speedRight);
            packer.addUint16((int16_t)speedLeft);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 90:{
            bool motorEnable;
            motorEnable = (bool)unPacker.popUint16();
            set_motor_state(motorEnable);
            break;
        }
        case 91:{
            bool brakeEnable;
            brakeEnable = (bool)unPacker.popUint16();
            set_brake_state(brakeEnable);
            break;
        }
        case 100:{
            int16_t max_torque;
            max_torque = (int16_t)unPacker.popUint16();
            set_max_torque(max_torque);
            break;
        }
        case 101:{
            int16_t max_speed_for;
            int16_t max_speed_back;
            int16_t max_acceleration_for;
            int16_t max_acceleration_back;
            int16_t max_deceleration_for;
            int16_t max_deceleration_back;
            max_speed_for = (int16_t)unPacker.popUint16();
            max_speed_back = (int16_t)unPacker.popUint16();
            max_acceleration_for = (int16_t)unPacker.popUint16();
            max_acceleration_back = (int16_t)unPacker.popUint16();
            max_deceleration_for = (int16_t)unPacker.popUint16();
            max_deceleration_back = (int16_t)unPacker.popUint16();
            set_linear_position_control(max_speed_for, max_speed_back, max_acceleration_for, max_acceleration_back, max_deceleration_for, max_deceleration_back);
            break;
        }
        case 102:{
            int16_t max_speed_clock;
            int16_t max_speed_anti;
            int16_t max_acceleration_clock;
            int16_t max_acceleration_anti;
            int16_t max_deceleration_clock;
            int16_t max_deceleration_anti;
            max_speed_clock = (int16_t)unPacker.popUint16();
            max_speed_anti = (int16_t)unPacker.popUint16();
            max_acceleration_clock = (int16_t)unPacker.popUint16();
            max_acceleration_anti = (int16_t)unPacker.popUint16();
            max_deceleration_clock = (int16_t)unPacker.popUint16();
            max_deceleration_anti = (int16_t)unPacker.popUint16();
            set_angular_position_control(max_speed_clock, max_speed_anti, max_acceleration_clock, max_acceleration_anti, max_deceleration_clock, max_deceleration_anti);
            break;
        }
        case 103:{
            int16_t p;
            int16_t i;
            int16_t d;
            p = (int16_t)unPacker.popUint16();
            i = (int16_t)unPacker.popUint16();
            d = (int16_t)unPacker.popUint16();
            set_pid_linear_static(p, i, d);
            break;
        }
        case 104:{
            int16_t p;
            int16_t i;
            int16_t d;
            p = (int16_t)unPacker.popUint16();
            i = (int16_t)unPacker.popUint16();
            d = (int16_t)unPacker.popUint16();
            set_pid_linear_dynamic(p, i, d);
            break;
        }
        case 105:{
            int16_t p;
            int16_t i;
            int16_t d;
            p = (int16_t)unPacker.popUint16();
            i = (int16_t)unPacker.popUint16();
            d = (int16_t)unPacker.popUint16();
            set_pid_angular_static(p, i, d);
            break;
        }
        case 106:{
            int16_t p;
            int16_t i;
            int16_t d;
            p = (int16_t)unPacker.popUint16();
            i = (int16_t)unPacker.popUint16();
            d = (int16_t)unPacker.popUint16();
            set_pid_angular_dynamic(p, i, d);
            break;
        }
        case 107:{
            int16_t sizeWheelLeft;
            int16_t sizeWheelRight;
            int16_t spaceInterWheel;
            sizeWheelLeft = (int16_t)unPacker.popUint16();
            sizeWheelRight = (int16_t)unPacker.popUint16();
            spaceInterWheel = (int16_t)unPacker.popUint16();
            set_odometry_metric(sizeWheelLeft, sizeWheelRight, spaceInterWheel);
            break;
        }
        case 130:{
            int16_t retParam;
            retParam = get_max_torque();
            packer.addUint16((int16_t)retParam);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 131:{
            int16_t max_speed_for;
            int16_t max_speed_back;
            int16_t max_acceleration_for;
            int16_t max_acceleration_back;
            int16_t max_deceleration_for;
            int16_t max_deceleration_back;
            get_linear_position_control(max_speed_for, max_speed_back, max_acceleration_for, max_acceleration_back, max_deceleration_for, max_deceleration_back);
            packer.addUint16((int16_t)max_speed_for);
            packer.addUint16((int16_t)max_speed_back);
            packer.addUint16((int16_t)max_acceleration_for);
            packer.addUint16((int16_t)max_acceleration_back);
            packer.addUint16((int16_t)max_deceleration_for);
            packer.addUint16((int16_t)max_deceleration_back);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 132:{
            int16_t max_speed_clock;
            int16_t max_speed_anti;
            int16_t max_acceleration_clock;
            int16_t max_acceleration_anti;
            int16_t max_deceleration_clock;
            int16_t max_deceleration_anti;
            get_angular_position_control(max_speed_clock, max_speed_anti, max_acceleration_clock, max_acceleration_anti, max_deceleration_clock, max_deceleration_anti);
            packer.addUint16((int16_t)max_speed_clock);
            packer.addUint16((int16_t)max_speed_anti);
            packer.addUint16((int16_t)max_acceleration_clock);
            packer.addUint16((int16_t)max_acceleration_anti);
            packer.addUint16((int16_t)max_deceleration_clock);
            packer.addUint16((int16_t)max_deceleration_anti);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 133:{
            int16_t p;
            int16_t i;
            int16_t d;
            get_pid_linear_static(p, i, d);
            packer.addUint16((int16_t)p);
            packer.addUint16((int16_t)i);
            packer.addUint16((int16_t)d);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 134:{
            int16_t p;
            int16_t i;
            int16_t d;
            get_pid_linear_dynamic(p, i, d);
            packer.addUint16((int16_t)p);
            packer.addUint16((int16_t)i);
            packer.addUint16((int16_t)d);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 135:{
            int16_t p;
            int16_t i;
            int16_t d;
            get_pid_angular_static(p, i, d);
            packer.addUint16((int16_t)p);
            packer.addUint16((int16_t)i);
            packer.addUint16((int16_t)d);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 136:{
            int16_t p;
            int16_t i;
            int16_t d;
            get_pid_angular_dynamic(p, i, d);
            packer.addUint16((int16_t)p);
            packer.addUint16((int16_t)i);
            packer.addUint16((int16_t)d);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 137:{
            int16_t sizeWheelLeft;
            int16_t sizeWheelRight;
            int16_t spaceInterWheel;
            get_odometry_metric(sizeWheelLeft, sizeWheelRight, spaceInterWheel);
            packer.addUint16((int16_t)sizeWheelLeft);
            packer.addUint16((int16_t)sizeWheelRight);
            packer.addUint16((int16_t)spaceInterWheel);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 160:{
            start_calibration();
            break;
        }
        case 161:{
            end_calibration();
            break;
        }
        case 162:{
            get_status_calibration();
            break;
        }
        case 200:{
            get_all_status();
            break;
        }
        case 201:{
            get_all_error();
            break;
        }
        case 202:{
            get_all_parameter();
            break;
        }
        case 203:{
            set_all_parameter();
            break;
        }
        default:
            break;
    }
}
// End auto generation CMD_ROBOT_FUNCTION_INTERFACE
//***********************************************
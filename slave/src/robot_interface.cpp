#include "robot_interface.h"

//***********************************************
// Start auto generation CMD_ROBOT_FUNCTION_INTERFACE
// Last generation 2024-12-11 17:31:02: python3 autoGen.py
// DO NOT EDIT
void Robot_interface::I2CDataSwitch(uint8_t* data, int size){
    uint8_t dataPack[64];
    DataPacker packer(dataPack, 64);
    DataUnpacker unPacker(&data[1], size + 1);
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
        case 50:{
            get_braking_distance();
            break;
        }
        case 51:{
            get_commande_buffer_size();
            break;
        }
        case 52:{
            get_direction_side();
            break;
        }
        case 53:{
            get_rotation_side();
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
            get_moving_is_done();
            break;
        }
        case 56:{
            get_running_is_done();
            break;
        }
        case 57:{
            get_turning_is_done();
            break;
        }
        case 58:{
            int16_t error;
            get_linear_error(error);
            packer.addUint16((int16_t)error);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 59:{
            int16_t error;
            get_angular_error(error);
            packer.addUint16((int16_t)error);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 60:{
            int16_t currentRigth;
            int16_t currentLeft;
            get_current(currentRigth, currentLeft);
            packer.addUint16((int16_t)currentRigth);
            packer.addUint16((int16_t)currentLeft);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 61:{
            int16_t speedRigth;
            int16_t speedLeft;
            get_speed(speedRigth, speedLeft);
            packer.addUint16((int16_t)speedRigth);
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
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            set_max_speed_forward(speed);
            break;
        }
        case 102:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            set_max_speed_backward(speed);
            break;
        }
        case 103:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            set_max_speed_trigo(speed);
            break;
        }
        case 104:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            set_max_speed_horloge(speed);
            break;
        }
        case 105:{
            int16_t p;
            int16_t i;
            int16_t d;
            p = (int16_t)unPacker.popUint16();
            i = (int16_t)unPacker.popUint16();
            d = (int16_t)unPacker.popUint16();
            set_pid_linear_static(p, i, d);
            break;
        }
        case 106:{
            int16_t p;
            int16_t i;
            int16_t d;
            p = (int16_t)unPacker.popUint16();
            i = (int16_t)unPacker.popUint16();
            d = (int16_t)unPacker.popUint16();
            set_pid_linear_dynamic(p, i, d);
            break;
        }
        case 107:{
            int16_t p;
            int16_t i;
            int16_t d;
            p = (int16_t)unPacker.popUint16();
            i = (int16_t)unPacker.popUint16();
            d = (int16_t)unPacker.popUint16();
            set_pid_angular_static(p, i, d);
            break;
        }
        case 108:{
            int16_t p;
            int16_t i;
            int16_t d;
            p = (int16_t)unPacker.popUint16();
            i = (int16_t)unPacker.popUint16();
            d = (int16_t)unPacker.popUint16();
            set_pid_angular_dynamic(p, i, d);
            break;
        }
        case 109:{
            int16_t sizeWheelLeft;
            int16_t sizeWheelRigth;
            int16_t spaceInterWheel;
            sizeWheelLeft = (int16_t)unPacker.popUint16();
            sizeWheelRigth = (int16_t)unPacker.popUint16();
            spaceInterWheel = (int16_t)unPacker.popUint16();
            set_odometry_metric(sizeWheelLeft, sizeWheelRigth, spaceInterWheel);
            break;
        }
        case 130:{
            int16_t max_torque;
            max_torque = (int16_t)unPacker.popUint16();
            get_max_torque(max_torque);
            break;
        }
        case 131:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            get_max_speed_forward(speed);
            break;
        }
        case 132:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            get_max_speed_backward(speed);
            break;
        }
        case 133:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            get_max_speed_trigo(speed);
            break;
        }
        case 134:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            get_max_speed_horloge(speed);
            break;
        }
        case 135:{
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
        case 136:{
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
        case 137:{
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
        case 138:{
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
        case 139:{
            int16_t sizeWheelLeft;
            int16_t sizeWheelRigth;
            int16_t spaceInterWheel;
            get_odometry_metric(sizeWheelLeft, sizeWheelRigth, spaceInterWheel);
            packer.addUint16((int16_t)sizeWheelLeft);
            packer.addUint16((int16_t)sizeWheelRigth);
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
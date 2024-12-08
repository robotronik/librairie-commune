#include "robot_interface.h"

//***********************************************
// Start auto generation CMD_ROBOT_FUNCTION_INTERFACE
// Last generation 2024-12-08 16:19:33: python3 autoGen.py
// DO NOT EDIT
void Robot_interface::I2CDataSwitch(uint8_t* data, int size){
    uint8_t dataPack[64];
    DataPacker packer(dataPack, 64);
    DataUnpacker unPacker(&data[1], size + 1);
    switch (data[0]){
        case 10:{
            turn_on_LED_1();
            break;
        }
        case 11:{
            turn_off_LED_1();
            break;
        }
        case 12:{
            turn_on_LED_2();
            break;
        }
        case 13:{
            turn_off_LED_2();
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
            int16_t x;
            int16_t y;
            x = (int16_t)unPacker.popUint16();
            y = (int16_t)unPacker.popUint16();
            set_consigne_lineaire(x, y);
            break;
        }
        case 32:{
            int16_t angle;
            int16_t rotation;
            angle = (int16_t)unPacker.popUint16();
            rotation = (int16_t)unPacker.popUint16();
            set_consigne_angulaire(angle, rotation);
            break;
        }
        case 33:{
            int16_t x;
            int16_t y;
            int16_t rotation;
            x = (int16_t)unPacker.popUint16();
            y = (int16_t)unPacker.popUint16();
            rotation = (int16_t)unPacker.popUint16();
            set_consigne_lookAt_forward(x, y, rotation);
            break;
        }
        case 34:{
            int16_t x;
            int16_t y;
            int16_t rotation;
            x = (int16_t)unPacker.popUint16();
            y = (int16_t)unPacker.popUint16();
            rotation = (int16_t)unPacker.popUint16();
            set_consigne_lookAt_backward(x, y, rotation);
            break;
        }
        case 40:{
            int16_t resbool;
            robot_moving_is_finish(resbool);
            packer.addUint16((int16_t)resbool);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 41:{
            int16_t resbool;
            robot_running_is_finish(resbool);
            packer.addUint16((int16_t)resbool);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 42:{
            int16_t resbool;
            robot_turning_is_finish(resbool);
            packer.addUint16((int16_t)resbool);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 43:{
            int16_t error;
            get_linear_error(error);
            packer.addUint16((int16_t)error);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 44:{
            int16_t error;
            get_angular_error(error);
            packer.addUint16((int16_t)error);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 45:{
            int16_t distance;
            get_braking_distance(distance);
            packer.addUint16((int16_t)distance);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 46:{
            bool robot_runnning;
            get_robot_running(robot_runnning);
            packer.addUint16((int16_t)robot_runnning);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 47:{
            Direction direction_side;
            get_directio_side(direction_side);
            packer.addUint16((int16_t)direction_side);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 48:{
            Rotation rotation_side;
            get_rotation_side(rotation_side);
            packer.addUint16((int16_t)rotation_side);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 49:{
            int16_t x;
            int16_t y;
            int16_t theta;
            get_current_consigne(x, y, theta);
            packer.addUint16((int16_t)x);
            packer.addUint16((int16_t)y);
            packer.addUint16((int16_t)theta);
            setReponseBuffer(packer.getData(),packer.getSize());
            break;
        }
        case 50:{
            disable_motor();
            break;
        }
        case 51:{
            enable_motor();
            break;
        }
        case 52:{
            brake_on();
            break;
        }
        case 53:{
            brake_off();
            break;
        }
        case 54:{
            int16_t max_torque;
            max_torque = (int16_t)unPacker.popUint16();
            set_max_torque(max_torque);
            break;
        }
        case 60:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            set_max_speed_forward(speed);
            break;
        }
        case 61:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            set_max_speed_backward(speed);
            break;
        }
        case 62:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            set_max_speed_trigo(speed);
            break;
        }
        case 63:{
            int16_t speed;
            speed = (int16_t)unPacker.popUint16();
            set_max_speed_horloge(speed);
            break;
        }
        case 70:{
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
        case 71:{
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
        default:
            break;
    }
}
// End auto generation CMD_ROBOT_FUNCTION_INTERFACE
//***********************************************
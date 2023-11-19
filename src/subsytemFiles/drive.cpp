#include "main.h"

//helper function
void setDrive(int left, int right){
    left_front_motor = left;
    left_back_motor = left;
    right_front_motor = right;
    right_back_motor = right;

    //left_back_motor.move_velocity(600);
   // right_front_motor.move_velocity(600);
   // right_back_motor.move_velocity(600);

    //whih side, left right is the value it serts each side
}

//driver control functio n
void setDriveMotors(){

    pros::lcd::set_text(0, "slay, what yo uwanna slay");

    setDrive(0,0);
    //sets it to 0

    //setting up the joysticks

    //get joystsick value

    int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

    int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    //set motor velocities based on joystick values

    left_front_motor.move_velocity(leftJoystick + 1000);
    left_back_motor.move_velocity(leftJoystick + 1000);
    right_front_motor.move_velocity(rightJoystick + 1000);
    right_back_motor.move_velocity(rightJoystick + 1000);

    setDrive(leftJoystick, rightJoystick);

}


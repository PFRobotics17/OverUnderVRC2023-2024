#include "lemlib/api.hpp"
#include "main.h"


void initialize() {
    pros::lcd::initialize();
    pros::lcd::set_text(5, "WAWEHGFUAWE:UIOkl");

    //setting up brake settings ###
    //drivetrain on coast

    left_back_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    right_back_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    left_front_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    right_front_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

    // all subsystems on hold

    cataMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    wings1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    wings2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    intakespin.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    intake1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    intake2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);


}
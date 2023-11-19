#include "lemlib/api.hpp"
#include "main.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
    pros::lcd::initialize();
    pros::lcd::set_text(5, "initialize");

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
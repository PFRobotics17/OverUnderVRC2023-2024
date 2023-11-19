#include "main.h"

//motors ##

//drivetrain motors ###
	pros::Motor left_front_motor(12, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS); //port 1(The numbwr) #IF 36 its 100rpm
    //backwards means false, forwards = true
	pros::Motor right_front_motor(1, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS); //port 2 (sssThe numbwr)
	pros::Motor left_back_motor(20, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS); //port 3(The numbwr)
    pros::Motor right_back_motor(13, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS); //port 4 (number)

    


// subsytem motors ###
    //cata
    pros::Motor cataMotor(3, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS); 
    //chec k if its 100rpm cartridge or not 36 is cartridge, also add true/false
    //wings
    pros::Motor wings1(5, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS); ; 
    pros::Motor wings2(11, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS); ;
    //intake
    pros::Motor intakespin(9, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS); ;; //1 intake motor
    pros::Motor intake2(6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS); ;; //2 intake motor 
    pros::Motor intake1(16, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS); ;; //3 intake motor 

//CONTROLLR ###

pros::Controller controller(pros::E_CONTROLLER_MASTER);
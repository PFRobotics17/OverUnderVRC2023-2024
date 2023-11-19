#include "main.h"
#include "lemlib/api.hpp"

//organize by where robot go

//name this the corner wehrew e get tjhe triball from

void frontBar();
void throwTriball();
void Corner();
void getTriball();
void touchBar();


//drivetrain motor groups
	pros::MotorGroup left_side_motors({left_front_motor, left_back_motor});
	pros::MotorGroup right_side_motors({right_front_motor, right_back_motor});


	//drivetrain is here, setup later

	lemlib::Drivetrain_t drivetrain {
		&left_side_motors, //left motors
		&right_side_motors, //right motors
		//track width here
		//wheel diameter
		//wheel

	};

	// inertial sensor
	pros::Imu inertial_sensor(10); // intertial is port 10

//setting up tracking wheel, WE DONT HAVE INE RN :sob:
	// pros::ADIEncoder enc()
	// lemlib::TrackingWheel trackingwheel (&enc, wheel diameter, offset from tracking center, gear ratio)
// vertical tracking wheels should have a negative offset if on the left of the tracking center,
// and horizontal tracking wheels should have a negative offset if in front of the tracking center.

	//odometry struct

	lemlib::OdomSensors_t sensors {
		nullptr, //vertical tracking wehel 1
		nullptr,
		nullptr,
		nullptr,
		&inertial_sensor
    } ;

	
//change PID later ####
	// forward/backward PID
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

//setting up chassis#####
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors); 

void display(){
    while (true) {

        lemlib::Pose pose = chassis.getPose();
        pros::lcd::print(0, "x: %f", pose.x);
        pros::lcd::print(0, "x: %f", pose.y);

    }
}

//two different startng postions have to code for both

void autonomous(){
    printf("aurtijnomous");

    // chassis.calibrate();
    // chassis.setPose(0, 0, 0);
    // chassis.setPose(5, 5, 5);

    // chassis.turnTo (53, 53, 1000);

    //frontBar();
    //throwTriball();
    // Corner();
    // getTriball();
    //touchBar();
}

// DEFINING FUNCTIONS #####


// front bar

void frontBar(){



}


//throw triball wehn get to front bar, try and get into goal?
// maybe will chabnge to put it undr our goal, if is allowed

void throwTriball(){

}

// go to corner

void Corner(){

}

//get the triball from the corner


void getTriball(){
    
}

//touch bar

void touchBar(){

}
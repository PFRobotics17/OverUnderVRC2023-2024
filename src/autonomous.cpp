#include "main.h"
#include "lemlib/api.hpp"


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

//organize by where robot go

// create functions for the stuff robot sipposed to do

void matchLoadZone();
void intakeMatchLoad();
void touchBar();

void autonomous(){

    //drivetrain motor groups
	pros::MotorGroup left_side_motors({left_front_motor, left_back_motor});
	pros::MotorGroup right_side_motors({right_front_motor, right_back_motor});


	//drivetrain is here, setup later

	lemlib::Drivetrain_t drivetrain {
		&left_side_motors, //left motors
		&right_side_motors, //right motors
		13, // track width
		4,  //wheel diameter
		200, //wheel rpm

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
		nullptr, //we dont have a tracking wheel so it is a null pointer
		nullptr,
		nullptr,
		nullptr,
		&inertial_sensor
    } ;

	
//change PID later ####
	// forward/backward PID
lemlib::ChassisController_t lateralController {
    10, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
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

//two different startng postions have to code for both

    //testing
    printf("aurtijnomous");
    pros::lcd::set_text(6, "AAAAAAAAAAAAA (auto)");


 // put a braek statement so lemlib stops

    

    chassis.calibrate();
    chassis.setPose(-37, -57, -90);
    //go forward then turn to get ball
    
    chassis.moveTo(-45, -56, 1000, 50, true);
    chassis.turnTo(60, 0, 1000, true, 50, true);
    intake1 = 300;
    intake2 = 300;
    pros::delay(0.5);
    cataMotor = 127;

    //timeout is seconda rgument, lookahead distnce is third, true means backwards fa;lse easnf forwad

    //put intake otu to get ball

    //put ball out in alliance goal

    //put intake back in

    //go to bar to touch it

    //end 
    
    lemlib::Pose pose = chassis.getPose();
    //pros::lcd::print(0, "x: %f", pose.x);
    //pros::lcd::print(1, "y: %f", pose.y);
    //pros::lcd::print(2, "heading: %f", pose.theta);
    
    }

    


// DEFINING FUNCTIONS #####


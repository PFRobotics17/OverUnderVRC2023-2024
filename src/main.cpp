#include "lemlib/api.hpp"
#include "main.h"



/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
// void on_center_button() {
	// static bool pressed = false;
	// pressed = !pressed;
	// if (pressed) {
	// 	pros::lcd::set_text(2, "I was pressed!");
	// } else {
	// 	pros::lcd::clear_line(2);
	// }
// }



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

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    pros::lcd::set_text(6, "stopped");
	printf("stopped");
	setDrive(0,0);
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {

	pros::lcd::set_text(3, "intalize comp");

}

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

	lemlib::Drivetrain_t drivetrain {
		&left_side_motors, //left motors
		&right_side_motors, //right motors
		13, // track width
		4,  //wheel diameter
		200, //wheel rpm

	};

	// inertial sensor
	pros::Imu inertial_sensor(10);

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
    printf("auto");
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

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {

	pros::lcd::set_text (4, "opcomtrol (driving)");

	


	pros::Controller master(pros::E_CONTROLLER_MASTER); //add controller id
    //has to be a while loop because if not the code will only run once...
	pros::Motor left_front_motor(12, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);

	while (true) {
        
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);

		// pros::lcd::set_text(3, "Left %d\n", left);

		printf("left %d\n", left);

		left_front_motor = left;

        
        //code to control drive
        setDriveMotors();
        //control cata


        //control intake
		setIntakeButtons();

        //control intakespin
		setCataButtons();
        
        //control wings

		setWingButtons();

		//lift

		setLiftButtons();

        // have to add delay so motors can update their values

		pros::delay(20); 

        
	}
}


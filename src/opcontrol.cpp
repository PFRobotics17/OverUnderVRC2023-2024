#include "main.h"

void opcontrol() {


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
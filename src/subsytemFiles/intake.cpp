#include "main.h"

//
void setIntake(int spin, int out)
{
    intakespin = spin;
    intake2 = out;
    intake1 = out;
}

//button triggers intake

void setIntakeButtons(){

    //button
    //right intake
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
    
        pros::lcd::set_text(2, "AWEJHAGKWE");
        intakespin = -300;
    }
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        pros::lcd::set_text(4, "r2");
        intakespin = 300;
    }
    else {
        intakespin = 0;
    }

}

void setLiftButtons(){

    //button
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
    
        pros::lcd::set_text(2, "AWEJHAGKWE");
        intake1 = -300;
        intake2 = -300;

    }
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        pros::lcd::set_text(4, "l2");
        intake1 = 300;
        intake2 = 300;
    }
    else {
        intake1 = 0;
        intake2 = 0;
    }

}
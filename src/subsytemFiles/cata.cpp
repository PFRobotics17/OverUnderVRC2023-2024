#include "main.h"

//only need one button, cycle down

//up button


//helper function

void setCata(int move){
    cataMotor = move;
}

//sets the buttons and maeks it function
void setCataButtons(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){

        pros::lcd::set_text(2, "cata");
        cataMotor = 127;

    }
    else{
        cataMotor = 0;
    }
}
#include "main.h"

//side to side arrows, out = right, in = left

//helper function

void setWings(int wing){
//basically set motor value equal to varibale tgats  whats happebing
    wings1 = wing;
    wings2 = wing;

}

//sets the buttons and maeks it function
void setWingButtons(){

     if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
    
        pros::lcd::set_text(2, "AWEJHAGKWE");
        wings1 = -300;
        wings2 = -300;
    }
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
        pros::lcd::set_text(4, "ra");
        wings1 = 300;
        wings2 = 300;
    }
    else {
        wings1 = 0;
        wings2 = 0;
    }

}
#include "main.h"
#include "pros/misc.h"
#include "drivecode/objects.hpp"
#include "pros/rtos.hpp"
#include <cstdint>

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}


void disabled() {}


void competition_initialize() {}


void autonomous() {}

//Lift Code (currently incomplete)
bool l1pressed = false; //lift variables for toggle
int liftstate = 0; //lift variables for toggle

uint32_t timestamp; //lift needs to be on a timer so it can stop
void updatelift( ){ 
if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { 
	if(!l1pressed) {
		timestamp = pros::millis();
		l1pressed = true;
		if(liftstate == 0) {
			liftstate = 1;
			lift.move(127);
		}
		else if (liftstate == 1) { 
			liftstate = 0;
			lift.move(-127);
		}
	}
	if (pros::millis() - timestamp >= 500) { lift.move(0);}
} 
else { l1pressed = false; } 

}
//end of lift code

void opcontrol(
	
) { 

	while (true) { 
		//arcade drive controls
		int throttle = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		//throttle is stick going up for pos value and down for neg value
		int direction = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		//direction is stick going right for pos value and left for neg value
		int left = throttle + direction;
		int right = throttle - direction;
		leftmotors.move(left);
		rightmotors.move(right);
		pros::delay (10);
		//lift code called
		updatelift();
	}
}




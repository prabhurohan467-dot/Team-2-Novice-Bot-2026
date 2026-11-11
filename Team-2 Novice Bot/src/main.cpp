#include "main.h"
#include "pros/misc.h"
#include "objects.hpp"
#include "pros/rtos.hpp"

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

void opcontrol(

	
) { 

	while (true) { 
		int throttle = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int direction = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		int left = throttle + direction;
		int right = throttle - direction;
		leftmotors.move(left);
		rightmotors.move(right);
		pros::delay (2);
	}
}


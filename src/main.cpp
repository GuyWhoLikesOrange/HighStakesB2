#include "main.h"

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
	pros::lcd::set_text(1, "sigma!");

	pros::lcd::register_btn1_cb(on_center_button);
	inertial.reset();
	vertical.reset_position();
}


void disabled() {
} 


void competition_initialize() {}


void autonomous() {
	vertical.reset_position();
	turn(72,3000);
}

void opcontrol() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "austyn");
	while(true){
		driver();
		Intake();
		pistonControl();
	}
}
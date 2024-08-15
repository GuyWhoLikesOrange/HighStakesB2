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
	// move(100,24,2000);
	// move(100,24,2000);
	// move(100,-48,2000);
	// turn(-45,1000);
	// move(100,48,2000);
	// turn(-90,1000);
	// move(100,48,2000);
	// move(100,-48,2000);
	// turn(-45,1000);
	// move(100,-48,2000);
	// turn(0,1000);
	// move(100,-24,1500);
}

void opcontrol() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "austyn");
	// controller.print(0,0, "hello %f/n", 3);
	float vert;
	const float VTWc = -0.0175297195;
	vertical.reset_position();
	while(true){

		driver();
		Intake();
		pistonControl();
		vert = vertical.get_position() / 100;
		controller.print(0,0,"TW: %f", vert * VTWc);
	}
	
	// pros::Controller master(pros::E_CONTROLLER_MASTER);
	// pros::MotorGroup left_mg({1, -2, 3});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
	// pros::MotorGroup right_mg({-4, 5, -6});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6


	// while (true) {
	// 	pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
	// 	                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
	// 	                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen LCDs

	// 	// Arcade control scheme
	// 	int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
	// 	int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
	// 	left_mg.move(dir - turn);                      // Sets left motor voltage
	// 	right_mg.move(dir + turn);                     // Sets right motor voltage
	// 	pros::delay(20);                               // Run for 20 ms then update
	// }
}
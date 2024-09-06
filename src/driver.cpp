#include "main.h"

void driver(){
    // If joysticks are pushed far enough:
    if (abs(controller.get_analog(ANALOG_LEFT_Y)) > 7 || abs(controller.get_analog(ANALOG_RIGHT_X)) > 7){
        // Variables set to the output value of the joysticks (-127 to 127)
        int lY = controller.get_analog(ANALOG_LEFT_Y);
        int rX = controller.get_analog(ANALOG_RIGHT_X);
        // Calculation of speed of both drivetrain sides
        int lSpeed = lY + rX * 0.8;
        int rSpeed = lY - rX * 0.8 ;
        // Spin drivetrain motors accordingly
        lSide.move(lSpeed);
        rSide.move(rSpeed);
    }
    else{
        // Brake drivetrain
        lSide.set_brake_mode(MOTOR_BRAKE_BRAKE);   
        rSide.set_brake_mode(MOTOR_BRAKE_BRAKE);
        lSide.brake();
        rSide.brake();
    }
}

void Intake(){
  // R1 Intakes
  if (controller.get_digital(E_CONTROLLER_DIGITAL_R1)){
    if (lineTracker.get_value() >= 29){
    intake.move(-127);
    }
  }
  
  // Button X Outtakes
  else if (controller.get_digital(E_CONTROLLER_DIGITAL_X)){
    if (lineTracker.get_value() >= 29){
    intake.move(127);
    }
  }

  //Line tracker
  // Intakes stops if nothing is pressed

  
  else{
    intake.move(0);
  }
}
 




bool liftToggle = 0;
bool clampToggle = 0;
bool doinkerToggle = 0;
void pistonControl(){ 
if (controller.get_digital(DIGITAL_L2)){ 
    liftToggle = !liftToggle; 
    if (liftToggle == 1){
    lift.set_value(true);
    }
  else if(liftToggle == 0){
   lift.set_value(false);
  }
    delay(300);
}
  if (controller.get_digital(DIGITAL_L1)){ 
    clampToggle = !clampToggle; 
    if (clampToggle == 1){
    clamp.set_value(true);
  }
  else if(clampToggle == 0){
    clamp.set_value(false);
  }
    delay(300);
  }
  if (controller.get_digital(DIGITAL_UP)){ 
    doinkerToggle = !doinkerToggle; 
    if (doinkerToggle == 1){
    doinker.set_value(true);
  }
  else if(doinkerToggle == 0){
    doinker.set_value(false);
  }
    delay(300);
  }
}
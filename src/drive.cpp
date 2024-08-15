#include "main.h"

int turnSpeed = 0;
void driver(){
  int lSpeed;
  int rSpeed;
    if (abs(controller.get_analog(ANALOG_LEFT_Y)) > 7 || abs(controller.get_analog(ANALOG_RIGHT_X)) > 7){
        int lY = controller.get_analog(ANALOG_LEFT_Y);
        int rX = controller.get_analog(ANALOG_RIGHT_X);
        lSpeed = lY + rX * 0.8;
        rSpeed = lY /* 0.9*/ - rX * 0.8 ;
        lSide.move(lSpeed);
        rSide.move(rSpeed);
    }
    else{
        lSide.set_brake_mode(MOTOR_BRAKE_BRAKE);   
        rSide.set_brake_mode(MOTOR_BRAKE_BRAKE);
        lSide.brake();
        rSide.brake();
    }
}

void Intake(){
  if (controller.get_digital(E_CONTROLLER_DIGITAL_R1)){
    intake.move(-127);
  }
  else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2)){
    IntakeArm.move(-127);
  }
  else{
    // intake.set_brake_mode(MOTOR_BRAKE_COAST);
    // intake.brake();
    intake.move(0);
  }
}

bool liftToggle = 0;
bool clampToggle = 0;
bool intakeToggle = 0;
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
    intakeToggle = !intakeToggle; 
    if (intakeToggle == 1){
    intakeLift.set_value(true);
  }
  else if(intakeToggle == 0){
    intakeLift.set_value(false);
  }
    delay(300);
  }
}
#include "main.h"

int turnSpeed = 0;
void driver(){
  int lSpeed;
  int rSpeed;
    if (abs(controller.get_analog(ANALOG_LEFT_Y)) > 7 || abs(controller.get_analog(ANALOG_RIGHT_X)) > 7){
        // if (controller.get_analog(ANALOG_RIGHT_X) > 7){
        //     turnSpeed = 80;
        // }
        // else if (controller.get_analog(ANALOG_RIGHT_X) > -7){
        //     turnSpeed = -80;
        // }
        // else{
        //     turnSpeed = 0;
        // }
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

// void lift(){
//   if (controller.get_digital(DIGITAL_L1)){
//     lift.move(127);
//   }
//   else if (controller.get_digital(DIGITAL_L2)){
//     lift.move(-127);
//   }
//   else{
//     lift.set_brake_mode(MOTOR_BRAKE_HOLD);
//     lift.brake();
//   }
// }

bool liftToggle = 0;
bool clampToggle = 0;
bool intakeToggle = 0;
void pistonControl(){ 
if (controller.get_digital(DIGITAL_L2)){ 
  //detects when Button Right 1 is pressed
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
  //detects when Button Right 2 is pressed
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
  //detects when Button Right 2 is pressed
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
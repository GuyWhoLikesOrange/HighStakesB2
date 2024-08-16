#include "main.h"

void autoIntake(){
    intake.move(-127);
}

void autoIntakeArm(){
    IntakeArm.move(-127);
}

void autoOuttake(){
    intake.move(127);
}

void stopIntake(){
    intake.move(0);
}

void clampDown(){
    clamp.set_value(true);
}

void clampUp(){
    clamp.set_value(false);
}

void intakeUp(){
    intakeLift.set_value(true);
}

void intakeDown(){
    intakeLift.set_value(false);
}

void liftUp(){
    lift.set_value(true);
}

void liftDown(){
    lift.set_value(false);
}

void matchAuto1(){
    autoIntakeArm();
    move(127,20,1500);
}


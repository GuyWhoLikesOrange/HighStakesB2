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

void doinkerUp(){
    doinker.set_value(true);
}

void doinkerDown(){
    doinker.set_value(false);
}

void liftUp(){
    lift.set_value(true);
}

void liftDown(){
    lift.set_value(false);
}

void matchAutoLR(){
    autoIntakeArm();            // Start the intake arm only
    move(127,18,900);           // Move to get first ring
    IntakeArm.move(0);          // Stop intake when ring is in full possession
    turn(-90,1000);             // Turn back to mobile goal
    move(127,-12,1500);         // Go to mobile goal
    autoIntake();               // Intake into clamped goal
    clampDown();
    turn(-45,1000);
    move(127, 15, 900);         // Go to two rings at middle and score
    turn(-90,700);
    move(127,20,1000);
    delay(200);
    stopIntake();               // Save one ring
    turn(-45,900);
    move(127,-50,1200);         // Go to alliance stake
    turn(-90,900);
    move(127,-15,750);          // Push away rings in the way
    clampUp();                  // Unpossess current mobile goal
    move(127,5,500);
    turn(0,900);
    move(127,-12,800);
    autoIntake();
    liftUp();                   // Touch ladder
    move(100, 60, 2000);
}

void matchAutoRR(){
    move(127,-40,1200);
    turn(-45,900);
    move(90,-7,750);
    clampDown();                // Get mobile goal
    autoIntake();               // Score preload
    turn(10,900);
    move(127,10,750);           // Get nearest ring
    stopIntake();               // Pick it up
    turn(90,900);
    clampUp();                  // Let go of current mobile goal
    delay(500);
    move(127,7,900);
    turn(-90,1000);
    move(100,-24,800);
    clampDown();                // to pick up another one
    delay(250);
    autoIntake();               // score the ring
    turn(135,900);
    move(127,15,900);
    liftUp();                   // Touch the ladder
}

void matchAutoLB(){
    autoIntakeArm();            // Start the intake arm only
    move(127,18,900);           // Move to get first ring
    IntakeArm.move(0);          // Stop intake when ring is in full possession
    turn(90,1000);              // Turn back to mobile goal
    move(127,-12,1500);         // Go to mobile goal
    autoIntake();               // Intake into clamped goal
    clampDown();
    turn(45,1000);
    move(127, 15, 900);         // Go to two rings at middle and score
    turn(90,700);
    move(127,20,1000);
    delay(200);
    stopIntake();               // Save one ring
    turn(45,900);
    move(127,-50,1200);         // Go to alliance stake
    turn(90,900);
    move(127,-15,750);          // Push away rings in the way
    clampUp();                  // Unpossess current mobile goal
    move(127,5,500);
    turn(0,900);
    move(127,-12,800);
    autoIntake();
    liftUp();                   // Touch ladder
}

void matchAutoRB(){
    move(127,-40,1200);
    turn(45,900);
    move(90,-7,750);
    clampDown();                // Get mobile goal
    autoIntake();               // Score preload
    turn(-10,900);
    move(127,10,750);           // Get nearest ring
    stopIntake();               // Pick it up
    turn(-90,900);
    clampUp();                  // Let go of current mobile goal
    delay(500);
    move(127,7,900);
    turn(90,1000);
    move(100,-24,800);
    clampDown();                // to pick up another one
    delay(250);
    autoIntake();               // score the ring
    turn(-135,900);
    move(127,15,900);
    liftUp();                   // Touch the ladder
}

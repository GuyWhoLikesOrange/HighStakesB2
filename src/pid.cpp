#include "api.h"
#include "main.h"

void turn(float desired, float timeout) { 

    // pid
    double kP = 0.8715; //0.812
    double kD = 0; //0.125
    double kI = 0; //0.025
    double starti = 6;
    float error = 0;
    float preverror = 0;
    double derivative = 0;
    double integral = 0;
    float speed = 0;
    double time = 0;

    while (true) {
        float current = inertial.get_rotation();
        controller.print(0,0, "pid2 %f/n", inertial.get_rotation());
        error = desired - current;
        derivative = error - preverror;
        preverror = error;
        if (fabs(error) < starti){
            integral += error;
        }
        
        if ((error > 0 && preverror < 0) || (error < 0 && preverror > 0)){
            integral = 0;
        }

        if (error == 0){
            integral = 0;
        }
        speed = (kP * error + kD * derivative + kI * integral) * 1.27;
        lSide.move(speed); 
        rSide.move(-speed); 

        if (time > timeout) {
            break;
        }

        delay(10);
        time += 10;
    }

    lSide.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    rSide.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    lSide.brake();
    rSide.brake();
}



void move(float pct, float dist, float timeout) {
    float kP = 6.05; //7.5
    float kI = 0;
    float kD = 1;
    float integral = 0;
    float prevError = 0;
    float time = 0;
    const float IPT = -0.0175297105; // Converts the ticks from rotation sensor into inches

    vertical.reset_position();
    while (true) {
        float vert = (vertical.get_position() / 100) * IPT;
        float current = vert;
        float error = dist - current;


        integral += error;
        float derivative = error - prevError;
        prevError = error;
        float speed = kP * error + kI * integral + kD * derivative * 1.27;

        controller.print(0,0,"vert: %f", vert);
        lSide.move(speed);
        rSide.move(speed);

        delay(10);
        time += 10;
        if (time > timeout) {
            break;
        }
    }

    lSide.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    rSide.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    lSide.brake();
    rSide.brake();
}


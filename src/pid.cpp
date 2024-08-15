#include "api.h"
#include "main.h"

// void pidturn(float desired, float timeout){
// //values are constantly changing
// double kP = 0.555;
// double kD = 0.49;
// double error = 0;
// double preverror = 0;
// double derivative = 0;
// double speed = 0;
// double startTime = Brain.timer(sec);

// while (true){
// double current = Inertial.rotation(vex::degrees);
//  error = desired - current;
//  derivative = error - preverror;
//  preverror = error;

//  speed =  kP * error + kD * derivative;
//  leftdt.spin(fwd, speed, pct);
//  rightdt.spin(reverse, speed, pct);
//  if (error == 0 || Brain.timer(sec) - startTime > timeout) {
//       break;
//     }
//  if (fabs(error) < 0.1){

//  break;
//  }
// }
// }


// void pidturn(float desired, float timeout) { 

//     // pid
//     double kP = 0.6;
//     double kD = 0;
//     double error = 0;
//     double preverror = 0;
//     double derivative = 0;
//     double speed = 0;
//     double time = 0;

//     // auto startTime = std::chrono::steady_clock::now();

//     while (true) {
//         double current = inertial.get_heading();
//         error = desired - current;
//         derivative = error - preverror;
//         preverror = error;

//         speed = (kP * error + kD * derivative) * 1.26 ;
//         lSide.move(-speed); 
//         rSide.move(speed); 

//         // auto now = std::chrono::steady_clock::now();
//         // auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime).count();

//         if (fabs(error) < 0.1 || time > timeout) {
//             break;
//         }

//         delay(10);
//         time += 10;
//     }


//     lSide.move(0);
//     rSide.move(0);
// }

void turn(float desired, float timeout) { 

    // pid
    double kP = 0.7915; //0.812
    double kD = 0; //2.25
    double kI = 0;
    float error = 0;
    float preverror = 0;
    double derivative = 0;
    double integral = 0;
    float speed = 0;
    double time = 0;

    // auto startTime = std::chrono::steady_clock::now()
    while (true) {
        float current = inertial.get_rotation();
        controller.print(0,0, "pid2 %f/n", inertial.get_rotation());
        error = desired - current;
        derivative = error - preverror;
        preverror = error;
        // integral = error++;

        speed = (kP * error + kD * derivative + kI * integral) * 1.27;
        lSide.move(speed); 
        rSide.move(-speed); 
        // printf("speed: %f", speed);
        // controller.print(0,0,"speed: %f", speed);
        // auto now = std::chrono::steady_clock::now();
        // auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime).count();

        if (/*fabs(error) < 0.05 ||*/ time > timeout) {
            break;
        }

        delay(10);
        time += 10;
    }

    lSide.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    rSide.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    lSide.brake();
    rSide.brake();
    // lSide.move(0);
    // rSide.move(0);
}



void move(float pct, float dist, float timeout) {
    // 1/360 * 2pi 
    float kP = 6.05; //7.5
    float kI = 0;
    float kD = 1;
    float integral = 0;
    float prevError = 0;
    float time = 0;
//    const double wheelDiameter = (3.25 * 2) ; // in inches
//     const double wheelCircumference = wheelDiameter * 3.14159; // Circumference calculation
    const float IPT = -0.0175297105; // Converts the ticks from rotation sensor into inches

    // lSide.set_zero_position(0); 
    // rSide.set_zero_position(0); 

    // Correct targetDegrees calculation
    // float targetDegrees = dist;

    // float startTime = millis() / 1000.0;
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


        // std::cout << "Target: " << targetDegrees << std::endl;
        // std::cout << "Position: " << current << std::endl;
        // std::cout << "Error: " << error << std::endl;

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

// void pidtesting(){
//     if (controller.get_digital(E_CONTROLLER_DIGITAL_A)){
//         pidturn(90, 5);
// }
// }


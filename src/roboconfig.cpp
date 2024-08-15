#include "main.h"

using namespace pros;

Controller controller(E_CONTROLLER_MASTER);
MotorGroup lSide({-2, 5, -6});
// MotorGroup rSide({5, 7, -6});
MotorGroup rSide({14, 10, -7});
MotorGroup dt({12, -14, -15, 5, 7, -7});

MotorGroup intake({1, 3});
Motor IntakeArm({1});
IMU inertial(12);

 ADIAnalogIn encoder(4);
Rotation vertical(21);

#define liftPort 'A'
#define clampPort 'B'
#define intakePort 'C'
ADIDigitalOut lift(liftPort);
ADIDigitalOut clamp(clampPort);
ADIDigitalOut intakeLift(intakePort);
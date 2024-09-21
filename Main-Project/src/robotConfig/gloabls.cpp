#include "main.h"
#include "lemlib/api.hpp"
#include "usr/robot.h"
#include "robodash/api.h"
using namespace pros;
using namespace lemlib;

pros::Controller Robot::master (pros::E_CONTROLLER_MASTER);
rd::Console Robot::Auton::Tuning::AutonTuning ("PID Tuner");

lemlib::ControllerSettings Robot::Auton::Tuning::latController (10, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            3, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);
lemlib::ControllerSettings Robot::Auton::Tuning::angularController(2, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             10, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);
void MoveForward () {
    Robot::chassis.setPose(0, 0, 0);
    Robot::chassis.moveToPoint(0, 24, 2000);
}
void Turn90() {
    Robot::chassis.setPose(0, 0, 0);
    Robot::chassis.turnToHeading(270, 1000);
}
rd::Selector Robot::Auton::Tuning::Tuningselector (
    {
        {"Move Forwards 24''", MoveForward},
        {"Turn 90deg left", Turn90}
    }
);

const Motor Robot::Motors::Intake1st (0); // Not yet built
const Motor Robot::Motors::Intake2nd (0); // Not yet built

bool Robot::Motors::DTDirection = true; // Defualt direction is forwards

//* Left motors on ports 10, 9, 8; Rights on 1, 2, 3; Using blue cartridges
MotorGroup Robot::Motors::leftMotors (
    {-10, -9, -8},
    MotorGears::blue,
    MotorUnits::degrees
);
MotorGroup Robot::Motors::rightMotors (
    {1, 2, 3},
    MotorGears::blue,
    MotorUnits::degrees
);

//* Drivetrain with track width 13.1'', Geard (down) for 450rpm, using horizontal drift of 8 due to traction wheel usage
const Drivetrain Robot::Motors::drivetrain(
    &leftMotors,
    &rightMotors,
    13.1,
    Omniwheel::NEW_275,
    450,
    8
);

adi::DigitalOut Robot::Pneumatics::mogo ('C');
bool Robot::Pneumatics::mogoExtended = false;

Imu Robot::Sensors::imu (12); // IMU on port 9

adi::Encoder horiEncoder('E', 'F');
adi::Encoder vertEncoder('A', 'B');

TrackingWheel Robot::Sensors::verticalTracking (&vertEncoder, Omniwheel::NEW_275_HALF, 0);
TrackingWheel Robot::Sensors::horizontalTracking (&horiEncoder, Omniwheel::NEW_275_HALF, 0);

OdomSensors Robot::Sensors::sensors (&verticalTracking, nullptr, &horizontalTracking, nullptr, &imu);

lemlib::Chassis Robot::chassis (Motors::drivetrain, Auton::Tuning::latController, Auton::Tuning::angularController, Sensors::sensors);
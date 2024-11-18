#include "main.h"
#include "lemlib/api.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "usr/robot.h"
#include "robodash/api.h"
#include "usr/autons.h"
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
rd::Selector Robot::Auton::Tuning::Tuningselector (
    {
        {"Move Forwards 24''", Autons::Testers::forward24},
        {"Turn 90deg right", Autons::Testers::turn90},
        {"Boomerang 24 24 90", Autons::Testers::boomerang_24_24_90},
        {"Swing 90deg right", Autons::Testers::swing90},
        {"Cricle (exp.)", Autons::Testers::circle}
    }
);
rd::Selector Robot::Auton::autonSelectorMain (
    {
        {"GREEDY RED", Autons::greedyRed},
        {"GREEDY BLUE", Autons::greedyBlue},
        {"ELIM RED", Autons::elimRed},
        {"ELIM BLUE", Autons::elimBlue},
    }
);
Motor Robot::Motors::Intake (-1, v5::MotorGears::blue, v5::MotorUnits::rotations);

Motor Robot::Motors::LB_Motor (14, pros::v5::MotorGears::green, pros::v5::MotorUnits::deg);

adi::Button Robot::Sensors::LB_Bumper ('D');

bool Robot::Actions::LB::isRunningMacro = false;

const float Robot::maxLB = 120;

lemlib::PID Robot::Auton::LB_PID(5, 1, 9);

//* Left motors on ports 10, 9, 8; Rights on 1, 2, 3; Using blue cartridges
MotorGroup Robot::Motors::leftMotors (
    {-20, -12, -12},
    MotorGears::blue,
    MotorUnits::degrees
);
MotorGroup Robot::Motors::rightMotors (
    {4, 3, 2},
    MotorGears::blue,
    MotorUnits::degrees
);
ExpoDriveCurve Robot::Auton::Tuning::driveCurveLateral (15, 6, 1.004);
ExpoDriveCurve Robot::Auton::Tuning::driveCurveAngular (4, 6, 1.014);

//* Drivetrain with track width 13.1'', Geard (down) for 450rpm, using horizontal drift of 6 due to traction wheel usage
//TODO Measure dimensions
const Drivetrain Robot::Motors::drivetrain(
    &leftMotors,
    &rightMotors,
    13.1,
    Omniwheel::NEW_275,
    450,
    6
);

adi::Pneumatics Robot::Pneumatics::mogoMech {'H', false};
adi::Pneumatics Robot::Pneumatics::intakeLifter {'C', true}; // not built
adi::Pneumatics Robot::Pneumatics::doinker {'B', false}; // not built

Imu Robot::Sensors::imu (17); // IMU on port 12


OdomSensors Robot::Sensors::sensors (nullptr, nullptr, nullptr, nullptr, &imu);

lemlib::Chassis Robot::chassis (
    Motors::drivetrain,
    Auton::Tuning::latController,
    Auton::Tuning::angularController,
    Sensors::sensors
    //&Auton::Tuning::driveCurveLateral,
    //&Auton::Tuning::driveCurveAngular
);
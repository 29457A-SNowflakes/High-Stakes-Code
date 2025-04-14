#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motor_group.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"
#include "robodash/views/console.hpp"
#include "robodash/views/selector.hpp"
#include "usr/robot.h"
#include <cstddef>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include "usr/autons.h"

using namespace pros;
using namespace lemlib;
using namespace std;


Controller Robot::master (E_CONTROLLER_MASTER);

rd::Selector Robot::Screen::autonSelector ({
    {"Blue ring side", Autons::Match::Blue_Ring_Side},
    {"Red ring side", Autons::Match::Red_Ring_Side}
});
rd::Console Robot::Screen::printConsole ("Printing");

Rotation horiTrackingRotSens (-7);

TrackingWheel horiTrackingWheel (
	&horiTrackingRotSens,
	2,
	-1.75
);

Rotation vertTrackingSensor (15);
TrackingWheel vertTrackingWheel (
    &vertTrackingSensor,
    2,
    -0.75
);
Imu Robot::Sensors::imu (14);

OdomSensors Robot::Sensors::sensors (
    &vertTrackingWheel,
    nullptr,
    &horiTrackingWheel,
    nullptr,
    &imu
);

adi::Pneumatics Robot::Pneumatics::Mogo ('a', false, false);
adi::Pneumatics Robot::Pneumatics::primaryDoinker ('c', false, false);
adi::Pneumatics Robot::Pneumatics::secondaryDoinker ('d', false, true);

MotorGroup leftDrive ({19, -17, 18}, pros::MotorGears::blue, pros::v5::MotorEncoderUnits::deg);
MotorGroup rightDrive ({-18, 16, 5}, pros::MotorGears::blue, pros::v5::MotorEncoderUnits::deg);

Drivetrain Robot::Motors::dt (
    &leftDrive,
    &rightDrive,
    10.325, // measure
    3.25,  
    400,
    1
);

Motor Robot::Motors::hooksMotor (20, v5::MotorGears::blue, v5::MotorEncoderUnits::deg);
Motor Robot::Motors::preRollerMotor (4, v5::MotorGears::green, v5::MotorEncoderUnits::deg); // ?

Motor Robot::Motors::LBMotor (12, v5::MotorGears::green, v5::MotorEncoderUnits::degrees); // redo

// retune for worlds
ControllerSettings Robot::latSettings (
    8.5,
    0,
    20,
    3,
    1,
    100,
    2.5,
    500,
    15
);
ControllerSettings Robot::angSettings (
    2,
    0,
    30,
    3,
    1,
    180,
    2,
    700,
    3
);
Chassis Robot::chassis (
    Motors::dt,
    latSettings,
    angSettings,
    Sensors::sensors
);


Motor* LadyBrown::motor = &Robot::Motors::LBMotor;

Rotation Robot::Sensors::LBRotation (11);
adi::DigitalIn Robot::Sensors::LBLimiter ('H');
Rotation* LadyBrown::rotSens = &Robot::Sensors::LBRotation;

PID LadyBrown::lbPID {
    3.5,
    0,
    28
}; // TO BE TUNED
const float LadyBrown::minPos = -100; // not used
const float LadyBrown::maxPos = 900; // not used
const float LadyBrown::exitError = 30;
float LadyBrown::timeout = 2000;
const float LadyBrown::gearRatio = 1;

string LadyBrown::currentState = "REST";
std::map<string, float> LadyBrown::states = {
    std::pair<string, float> {"REST", 0},
    std::pair<string, float> {"LOAD", 600},
    std::pair<string, float> {"DESCORE", 15000}
};
std::vector<string> LadyBrown::stateList = {"REST", "LOAD"};
bool LadyBrown::cancel = false;
bool LadyBrown::hasFinished = true;
bool LadyBrown::manualControl = false;
int LadyBrown::currentStateNum = 0;

Optical Robot::Sensors::colourSens (13);
string Robot::playingColour = "RED";
bool Robot::Inits::isSorting = true;

bool Robot::Motors::intakeAutoControl = false;


rd::Selector Robot::Screen::TuningSelector ({
    {"Forward 24", Autons::Testers::Move24},
    {"Forward 72", Autons::Testers::Move72},
    {"Turning Test", Autons::Testers::TurnTest},
    {"Turn 180", Autons::Testers::Turn180},
    {"Square Movement", Autons::Testers::SqaureTest}
});
rd::Console Robot::Screen::Tuning ("PID Tuning");

int Robot::Actions::timesSorted = 0;
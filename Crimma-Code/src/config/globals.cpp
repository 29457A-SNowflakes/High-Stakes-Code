#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motor_group.hpp"
#include "robodash/views/console.hpp"
#include "usr/robot.h"
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace pros;
using namespace lemlib;
using namespace std;


Controller Robot::master (E_CONTROLLER_MASTER);

void test () {}

rd::Selector Robot::Screen::autonSelector ({
    {"...", test}
});
rd::Console Robot::Screen::printConsole ("Printing");

Rotation trackingRotSens (13);

TrackingWheel trackingWheel (
	&trackingRotSens,
	lemlib::Omniwheel::NEW_275,
	3.75
);
Imu Robot::Sensors::imu (5);

OdomSensors Robot::Sensors::sensors (
    nullptr,
    nullptr,
    &trackingWheel,
    nullptr,
    &imu
);

adi::Pneumatics Robot::Pneumatics::Mogo ('a', false, false);
adi::Pneumatics Robot::Pneumatics::doinker ('C', false, false);

MotorGroup leftDrive ({-19, -18, -17}, pros::MotorGears::blue, pros::v5::MotorEncoderUnits::deg);
MotorGroup rightDrive ({20, 16, 15}, pros::MotorGears::blue, pros::v5::MotorEncoderUnits::deg);

Drivetrain Robot::Motors::dt (
    &leftDrive,
    &rightDrive,
    11, // measure
    2.75,
    450,
    8
);

Motor Robot::Motors::intakeMotor (14, v5::MotorGears::blue, v5::MotorEncoderUnits::deg);

Motor Robot::Motors::LBMotor (-9, v5::MotorGears::green, v5::MotorEncoderUnits::degrees);

ControllerSettings Robot::latSettings (
    10,
    0,
    3,
    3,
    1,
    100,
    3,
    500,
    20
);
ControllerSettings Robot::angSettings (
    2,
    0,
    23,
    3,
    1,
    100,
    3,
    500,
    5
);
Chassis Robot::chassis (
    Motors::dt,
    latSettings,
    angSettings,
    Sensors::sensors
);


Motor* LadyBrown::motor = &Robot::Motors::LBMotor;

Rotation Robot::Sensors::LBRotation (12);
Rotation* LadyBrown::rotSens = &Robot::Sensors::LBRotation;

const float LadyBrown::P_Gain = 2.4f;
const float LadyBrown::minPos = -100;
const float LadyBrown::maxPos = 900;
const float LadyBrown::exitError = 300;
const float LadyBrown::timeout = 2500;

string LadyBrown::currentState = "REST";
std::map<string, float> LadyBrown::states = {
    std::pair<string, float> {"REST", 0},
    std::pair<string, float> {"LOAD", 3800},
    std::pair<string, float> {"FLIP", 10100}
};
std::vector<string> LadyBrown::stateList = {"REST", "LOAD", "FLIP"};
bool LadyBrown::cancel = false;
bool LadyBrown::hasFinished = true;
bool LadyBrown::manualControl = false;
int LadyBrown::currentStateNum = 0;

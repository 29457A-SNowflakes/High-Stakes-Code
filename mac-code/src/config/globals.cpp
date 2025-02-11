#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motor_group.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"
#include "robodash/views/console.hpp"
#include "usr/robot.h"
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
    {"solo awp red", Autons::Match::Solo_AWP_Red},
    {"solo awp BLUE", Autons::Match::Solo_AWP_Blue},
    {"mogo side elim RED",  Autons::Match::Mogo_Side_Elims_R},
    {"mogo side RED", Autons::Match::Mogo_Side_Elims_B},
    {"SKILLS", Autons::Skills::Skills}
});
rd::Console Robot::Screen::printConsole ("Printing");

Rotation trackingRotSens (13);

TrackingWheel horiTrackingWheel (
	&trackingRotSens,
	lemlib::Omniwheel::NEW_2,
	2.5
);

adi::Encoder trackingEncoder ('G', 'H', true);
TrackingWheel vertTrackingWheel (
    &trackingEncoder,
    Omniwheel::NEW_275,
    1 // ??
);
Imu Robot::Sensors::imu (5);

OdomSensors Robot::Sensors::sensors (
    &vertTrackingWheel,
    nullptr,
    &horiTrackingWheel,
    nullptr,
    &imu
);

adi::Pneumatics Robot::Pneumatics::Mogo ('a', true, false);
adi::Pneumatics Robot::Pneumatics::doinker ('b', false, false);
adi::Pneumatics Robot::Pneumatics::intakeLift ('c', false, true);

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

Motor Robot::Motors::LBMotor (9, v5::MotorGears::red, v5::MotorEncoderUnits::degrees);

ControllerSettings Robot::latSettings (
    14,
    0,
    11,
    3,
    1,
    100,
    2.5,
    500,
    20
);
ControllerSettings Robot::angSettings (
    5,
    0,
    28,
    3,
    1,
    180,
    3,
    700,
    4
);
Chassis Robot::chassis (
    Motors::dt,
    latSettings,
    angSettings,
    Sensors::sensors
);


Motor* LadyBrown::motor = &Robot::Motors::LBMotor;

Rotation Robot::Sensors::LBRotation (10);
adi::DigitalIn Robot::Sensors::LBLimiter ('E');
adi::DigitalIn* LadyBrown::limit = &Robot::Sensors::LBLimiter;
Rotation* LadyBrown::rotSens = &Robot::Sensors::LBRotation;

const float LadyBrown::P_Gain = 2.4f;
const float LadyBrown::minPos = -100;
const float LadyBrown::maxPos = 900;
const float LadyBrown::exitError = 140;
const float LadyBrown::timeout = 1100;

string LadyBrown::currentState = "REST";
std::map<string, float> LadyBrown::states = {
    std::pair<string, float> {"REST", 0},
    std::pair<string, float> {"LOAD", 3150},
    std::pair<string, float> {"FLIP", 15000}
};
std::vector<string> LadyBrown::stateList = {"REST", "LOAD"};
bool LadyBrown::cancel = false;
bool LadyBrown::hasFinished = true;
bool LadyBrown::manualControl = false;
int LadyBrown::currentStateNum = 0;

Optical Robot::Sensors::colourSens (3);
string Robot::playingColour = "BLUE";
bool Robot::Inits::isSorting = false;

bool Robot::Motors::intakeAutoControl = false;
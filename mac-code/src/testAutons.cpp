#include "lemlib/chassis/chassis.hpp"
#include "usr/robot.h"
#include "usr/autons.h"

using namespace lemlib;
using namespace pros;
using namespace Autons::Testers;
Chassis* chassis (&Robot::chassis);

void TurnTest() {
    chassis->calibrate();
    delay(1000);
    chassis->turnToHeading(90, 1000);
    chassis->turnToHeading(0, 1000);
    chassis->waitUntilDone();
    Robot::master.rumble("-");
}
void Turn180() {
    chassis->calibrate();
    delay(1000);
    chassis->turnToHeading(180, 1000);
    chassis->waitUntilDone();
    Robot::master.rumble("-");
}
void Move72() {
    chassis->calibrate();
    delay(1000);
    chassis->moveToPoint(0, 72, 1000);
    chassis->waitUntilDone();
    Robot::master.rumble("-");
}
void Move24() {
    chassis->calibrate();
    delay(1000);
    chassis->moveToPoint(0, 24, 1000);
    chassis->waitUntilDone();
    Robot::master.rumble("-");
}
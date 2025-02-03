#include "lemlib/chassis/chassis.hpp"
#include "usr/robot.h"
#include "usr/autons.h"

using namespace lemlib;
using namespace pros;
using namespace Autons;

void Testers::TurnTest() {
    Robot::chassis.calibrate();
    Robot::chassis.setPose(0, 0, 0);
    delay(1000);
    Robot::chassis.turnToHeading(90, 1000);
    Robot::chassis.turnToHeading(0, 1000);
    Robot::chassis.waitUntilDone();
    Robot::master.rumble("-");
}
void Testers::Turn180() {
    Robot::chassis.calibrate();
    delay(1000);
    Robot::chassis.turnToHeading(180, 1000);
    Robot::chassis.waitUntilDone();
    Robot::master.rumble("-");
}
void Testers::Move72() {
    Robot::chassis.calibrate();
    delay(1000);
    Robot::chassis.moveToPoint(0, 72, 1000);
    Robot::chassis.waitUntilDone();
    Robot::master.rumble("-");
}
void Testers::Move24() {
    Robot::chassis.calibrate();
    delay(1000);
    Robot::chassis.moveToPoint(0, 24, 1000);
    Robot::chassis.waitUntilDone();
    Robot::master.rumble("-");
}
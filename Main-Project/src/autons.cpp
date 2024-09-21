#include "lemlib/chassis/chassis.hpp"
#include "usr/robot.h"
#include "api.h"
#include "lemlib/api.hpp"
#include "usr/autons.h"
using namespace pros;

//* For Tuning
void calibrate () {
    Robot::chassis.calibrate();
    pros::delay(1000);
    Robot::chassis.setPose({0,0,0});
}
void Autons::Testers::forward24() {
    calibrate();
    Robot::chassis.moveToPoint(0, 24, 1000);
    Robot::chassis.waitUntilDone();
}
void Autons::Testers::turn90() {
    calibrate();
    Robot::chassis.turnToHeading(90, 1000);
    Robot::chassis.waitUntilDone();
}
void Autons::Testers::boomerang_24_24_90 () {
    calibrate();
    Robot::chassis.moveToPose(24, 24, 90, 1250, {.lead=0.81});
    Robot::chassis.waitUntilDone();
}
void Autons::Testers::swing90() {
    calibrate();
    Robot::chassis.swingToHeading(90, lemlib::DriveSide::RIGHT, 500);
    Robot::chassis.waitUntilDone();
}
void Autons::Testers::circle() {
    calibrate();
    Robot::chassis.moveToPose(0, 24, 270, 4000, {.lead=0.6});
    Robot::master.rumble(".");
    Robot::chassis.moveToPose(-24, 0, 180, 1000, {.lead=0.81});
    Robot::chassis.moveToPose(0, -24, 90, 1000, {.lead=0.81});
    Robot::chassis.moveToPose(24, 24, 0, 1000, {.lead=0.81});
    Robot::chassis.moveToPose(0, 24, 90, 1000, {.lead=0.81});
    Robot::chassis.waitUntilDone();
}
lemlib::Chassis* chassis = &Robot::chassis;
//* Game autons
void Autons::support() {
    chassis->setPose({-50, 41, 305});
    chassis->moveToPoint(-32, 28, 1000, {.forwards=false, .maxSpeed=110, .minSpeed=40});
    chassis->waitUntilDone();
    Robot::Pneumatics::mogoMech.set_value(true);
    delay(40);
    chassis->turnToPoint(-24, 48, 500);
    Robot::Actions::setIntake(1, Types::BOTH);
    chassis->moveToPoint(-26, 42, 1000, {.maxSpeed=80});
    chassis->waitUntilDone();
    delay(100);
    chassis->turnToPoint(-3, 50.5, 400);
    chassis->moveToPose(-3, 52, 90, 1000, {.lead=0.9, .maxSpeed=80});
    chassis->waitUntilDone();
    delay(100);
    chassis->moveToPose(-12, 55, 135, 800, {.forwards=false, .lead=0.5, .maxSpeed=70});
    chassis->moveToPoint(-7, 48, 1000, {.maxSpeed=90});
}
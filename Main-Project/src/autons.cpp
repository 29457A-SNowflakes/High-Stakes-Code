#include "usr/autons.h"
#include "api.h"
#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.h"
#include "robodash/views/selector.hpp"
#include "usr/robot.h"
using namespace pros;

//* For Tuning
void calibrate() {
  Robot::chassis.calibrate();
  pros::delay(1000);
  Robot::chassis.setPose({0, 0, 0});
}
void Autons::Testers::forward24() {
  calibrate();
  Robot::chassis.moveToPoint(0, 24, 1000);
  Robot::chassis.waitUntilDone();
}
void Autons::Testers::forward72() {
  calibrate();
  Robot::chassis.moveToPoint(0, 72, 1400);
  Robot::chassis.waitUntilDone();
}
void Autons::Testers::turn90() {
  calibrate();
  Robot::chassis.turnToHeading(90, 1000);
  Robot::chassis.waitUntilDone();
}
void Autons::Testers::boomerang_24_24_90() {
  calibrate();
  Robot::chassis.moveToPose(24, 24, 90, 2500, {.lead = 0.55});
  Robot::chassis.waitUntilDone();
}
void Autons::Testers::swing90() {
  calibrate();
  Robot::chassis.swingToHeading(90, lemlib::DriveSide::RIGHT, 1000);
  Robot::chassis.waitUntilDone();
}
void Autons::Testers::circle() {
  calibrate();
  Robot::chassis.moveToPose(0, 24, 270, 4000,
                            {
                                .lead = 0.4,
                            });
  Robot::master.rumble(".");
  Robot::chassis.moveToPose(-24, 0, 180, 1000, {.lead = 0.55});
  Robot::chassis.moveToPose(0, -24, 90, 1000, {.lead = 0.55});
  Robot::chassis.moveToPose(24, 24, 0, 1000, {.lead = 0.55});
  Robot::chassis.moveToPose(0, 24, 90, 1000, {.lead = 0.55});
  Robot::chassis.waitUntilDone();
}
lemlib::Chassis *chassis = &Robot::chassis;


void Autons::greedyRed() {
    Robot::Pneumatics::intakeLifter.retract();
    Robot::Pneumatics::mogoMech.retract();
    //calibrate();
    chassis->setPose(51, -49, 140);
    chassis->moveToPoint(28, -28, 3000, {.forwards=false, .maxSpeed=50});
    chassis->waitUntilDone();
    Robot::Pneumatics::mogoMech.extend();
    delay(500);
    Robot::Actions::setIntake(1);
    delay(500); 
    delay(400);
    chassis->moveToPoint(60, -10, 2000, {.maxSpeed=60});
    chassis->waitUntil(13);
    Robot::Pneumatics::intakeLifter.extend();
    chassis->waitUntilDone();
    chassis->moveToPoint(50, -30, 1000, {.forwards=false});
    chassis->waitUntil(3);
    Robot::Pneumatics::intakeLifter.retract();
    chassis->waitUntilDone();
    delay(600);
    //Robot::Pneumatics::mogoMech.retract();
    chassis->turnToPoint(40, 24, 600);
    chassis->moveToPoint(55, 0, 1000);
    chassis->waitUntil(13);
    Robot::Pneumatics::mogoMech.retract();
    chassis->waitUntilDone();

    chassis->turnToPoint(45, 24, 1000, {.forwards=false});
    chassis->moveToPoint(40, 20, 1000, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::mogoMech.extend();
    delay(400);
    delay(3000);
}
void Autons::greedyBlue() {
    Robot::Pneumatics::intakeLifter.retract();
    Robot::Pneumatics::mogoMech.retract();
    //calibrate();
    chassis->setPose(-51, -49, 220);
    chassis->moveToPoint(-28, -28, 3000, {.forwards=false, .maxSpeed=50});
    chassis->waitUntilDone();
    Robot::Pneumatics::mogoMech.extend();
    delay(500);
    Robot::Actions::setIntake(1);
    delay(500); 
    delay(400);
    chassis->moveToPoint(-60, -10, 2000, {.maxSpeed=60});
    chassis->waitUntil(13);
    Robot::Pneumatics::intakeLifter.extend();
    chassis->waitUntilDone();
    chassis->moveToPoint(-50, -30, 1000, {.forwards=false});
    chassis->waitUntil(3);
    Robot::Pneumatics::intakeLifter.retract();
    chassis->waitUntilDone();
    delay(600);
    //Robot::Pneumatics::mogoMech.retract();
    chassis->turnToPoint(-40, 24, 600);
    chassis->moveToPoint(-55, 0, 1000);
    chassis->waitUntil(13);
    Robot::Pneumatics::mogoMech.retract();
    chassis->waitUntilDone();

    chassis->turnToPoint(-45, 24, 1000, {.forwards=false});
    chassis->moveToPoint(-40, 20, 1000, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::mogoMech.extend();
    delay(400);
    delay(3000);
}

void Autons::elimRed() {
    Robot::Pneumatics::intakeLifter.retract();
    Robot::Pneumatics::mogoMech.retract();
    //calibrate();
    chassis->setPose(48, 36, 60);
    chassis->moveToPoint(26, 26, 1200, {.forwards=false, .maxSpeed=60});
    chassis->waitUntilDone();
    Robot::Pneumatics::mogoMech.extend();
    delay(700);
    Robot::Actions::setIntake(1);
    delay(800);
    chassis->turnToPoint(23, 48, 1000);
    chassis->moveToPoint(23, 48, 1200);
    chassis->waitUntilDone();
    delay(3000);
}
void Autons::elimBlue() {
    Robot::Pneumatics::intakeLifter.retract();
    Robot::Pneumatics::mogoMech.retract();
    //calibrate();
    chassis->setPose(-48, 36, 300);
    chassis->moveToPoint(-26, 26, 1200, {.forwards=false, .maxSpeed=60});
    chassis->waitUntilDone();
    Robot::Pneumatics::mogoMech.extend();
    delay(700);
    Robot::Actions::setIntake(1);
    delay(800);
    chassis->turnToPoint(-23, 48, 1000);
    chassis->moveToPoint(-23, 48, 1200);
    chassis->waitUntilDone();
    delay(3000);
}
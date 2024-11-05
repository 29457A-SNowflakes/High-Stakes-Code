#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.h"
#include "robodash/views/selector.hpp"
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
}void Autons::Testers::forward72(){
    calibrate();
    Robot::chassis.moveToPoint(0, 72, 1400);
    Robot::chassis.waitUntilDone();
}
void Autons::Testers::turn90() {
    calibrate();
    Robot::chassis.turnToHeading(90, 1000);
    Robot::chassis.waitUntilDone();
}
void Autons::Testers::boomerang_24_24_90 () {
    calibrate();
    Robot::chassis.moveToPose(24, 24, 90, 2500, {.lead=0.55});
    Robot::chassis.waitUntilDone();
}
void Autons::Testers::swing90() {
    calibrate();
    Robot::chassis.swingToHeading(90, lemlib::DriveSide::RIGHT, 1000);
    Robot::chassis.waitUntilDone();
}
void Autons::Testers::circle() {
    calibrate();
    Robot::chassis.moveToPose(0, 24, 270, 4000, {.lead=0.4,});
    Robot::master.rumble(".");
    Robot::chassis.moveToPose(-24, 0, 180, 1000, {.lead=0.55});
    Robot::chassis.moveToPose(0, -24, 90, 1000, {.lead=0.55});
    Robot::chassis.moveToPose(24, 24, 0, 1000, {.lead=0.55});
    Robot::chassis.moveToPose(0, 24, 90, 1000, {.lead=0.55});
    Robot::chassis.waitUntilDone();
}
lemlib::Chassis* chassis = &Robot::chassis;
//* Game autons
void Autons::support() {
    Robot::Pneumatics::mogoMech.retract(); // make sure mogo is not clamped.
    Robot::Pneumatics::intakeLifter.retract(); // make sure intake lifter is not lifted.
    Robot::Pneumatics::doinker.retract(); // make sure doinker is not out.
    if (!pros::competition::is_autonomous() && false) calibrate(); // calibrate if testing (not comp)

    chassis->setPose({-50, 41, 305}); // set initial pose
    // move to mogo and pick up
    chassis->moveToPoint(-32, 28, 1000, {.forwards=false, .maxSpeed=110, .minSpeed=40});
    chassis->waitUntilDone();
    Robot::Pneumatics::mogoMech.set_value(true);
    delay(200);
    // move towads ring while intaking
    chassis->turnToPoint(-24, 48, 500);
    Robot::Actions::setIntake(1, Types::BOTH);
    chassis->moveToPoint(-24.5, 46, 1000, {.maxSpeed=90, .minSpeed=40});
    // move back slightly to help with intaking
    chassis->moveToPoint(-23, 44, 750, {.forwards=false});
    chassis->waitUntilDone();
    delay(750);
    // turn to, and navigate towards rings on auton line
    chassis->turnToPoint(-3, 46.5, 800);
    delay(500);
    chassis->moveToPose(-2, 47.5, 117, 1000, {.lead=0.5, .maxSpeed=80});
    chassis->waitUntilDone();
    // wait to suck up first ring
    delay(750);
    // suck up second ring
    chassis->moveToPose(-24, 48, 140, 2000, {.forwards=false, .minSpeed=40});
    chassis->turnToPoint(0, 40, 750);
    chassis->moveToPoint(-9, 39, 1000, {.maxSpeed=65, .minSpeed=30});
    chassis->waitUntilDone();
    // wait to suck up
    delay(1000);
    // move away
    chassis->moveToPose(-10, 48, 180, 1000, {.forwards=false});
    // move towards ladder (helps w/ AWP)
    chassis->moveToPose(-24, 24, 170, 3000);
    Robot::Actions::runIntakeFor(1, BOTH, 2500, true);
    chassis->waitUntilDone();
    return;
}
void Autons::supportTouchLadder(){
    support();
    chassis->moveToPoint(-24, 0, 1000, {.maxSpeed=90});
    chassis->moveToPoint(-24, 0, 1000, {.maxSpeed=90});
    chassis->waitUntilDone();
    Robot::master.rumble("-");
}
void Autons::rush(){
    Robot::Pneumatics::mogoMech.retract(); // make sure mogo is not clamped.
    Robot::Pneumatics::intakeLifter.retract(); // make sure intake lifter is not lifted.
    Robot::Pneumatics::doinker.retract(); // make sure doinker is not out.

    if (!pros::competition::is_autonomous() && false && !Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) calibrate(); // calibrate (testing only)
    float start = millis();

    // set chassis pos
    chassis -> setPose({52.5, 60, 90}, false);

    // move towards mogo (fast)
    chassis->moveToPoint(30, 60, 1500, {.forwards=false, .minSpeed=70});
    chassis->waitUntilDone();
    // swing to face, then move to mogo
    chassis->swingToPoint(5, 48, lemlib::DriveSide::RIGHT, 750, {.forwards=false, .minSpeed=30});
    chassis->waitUntilDone();
    chassis->moveToPoint(8.67, 53, 1000, {.forwards=false, .maxSpeed=70});
    chassis->waitUntilDone();
    // extend mogo clamp, and wait for settle
    Robot::Pneumatics::mogoMech.extend();
    delay(200);
    // run intake from now to score rings (including preload)
    Robot::Actions::setIntake(1, BOTH);
    // turn to first ring and suck up
    chassis->turnToPoint(22, 47, 500);
    chassis->moveToPoint(25, 47, 900);
    delay(400);
    Robot::Pneumatics::mogoMech.retract();
    chassis->waitUntilDone();
    Robot::Actions::runIntakeFor(1, BOTH, 500, false);
    // drop mogo and move to next
    chassis->moveToPoint(24, 36, 2000);
    chassis->moveToPose(24, 26, 0, 2500, {.forwards=false});
    chassis->waitUntilDone();
    // grab next mogo
    Robot::Pneumatics::mogoMech.extend();
    delay(200);
    // turn to and move towards next ring with intake raised
    chassis->turnToPoint(48, 0, 1000, {.minSpeed=90});
    delay(100);
    Robot::Actions::setIntake(1, BOTH);
    chassis->waitUntilDone();
    delay(500);
    Robot::Pneumatics::intakeLifter.extend();
    chassis->moveToPoint(46, 0, 5000, {.maxSpeed=40,});
    chassis->waitUntilDone();
    // lower intake to finish sucking up
    Robot::Pneumatics::intakeLifter.retract();
    chassis->moveToPoint(36, 24, 1000, {.forwards=false, .maxSpeed=70});
    chassis->waitUntilDone();
    delay(750);
    chassis->moveToPoint(12, 3, 1000, {.maxSpeed=80});
    chassis->waitUntilDone();
    chassis->moveToPoint(12, 3, 1000, {.maxSpeed=60});
    chassis->waitUntilDone();
    Robot::master.print(1, 1, "%f", (millis()-start)/1000);
    Robot::Actions::runIntakeFor(1, BOTH, 10000, false);
    return;

}
void Autons::rushBlue(){
    Robot::Pneumatics::mogoMech.retract(); // make sure mogo is not clamped.
    Robot::Pneumatics::intakeLifter.retract(); // make sure intake lifter is not lifted.
    Robot::Pneumatics::doinker.retract(); // make sure doinker is not out.

    if (!pros::competition::is_autonomous() && !Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) calibrate(); // calibrate (testing only)
    float start = millis();

    // set chassis pos
    chassis -> setPose({-52.5, 60, 270}, false);

    // move towards mogo (fast)
    chassis->moveToPoint(-30, 60, 1500, {.forwards=false, .minSpeed=70});
    chassis->waitUntilDone();
    // swing to face, then move to mogo
    chassis->swingToPoint(-5, 48, lemlib::DriveSide::LEFT, 750, {.forwards=false, .minSpeed=30});
    chassis->waitUntilDone();
    chassis->moveToPoint(-8.67, 53, 1000, {.forwards=false, .maxSpeed=70});
    chassis->waitUntilDone();
    // extend mogo clamp, and wait for settle
    Robot::Pneumatics::mogoMech.extend();
    delay(200);
    // run intake from now to score rings (including preload)
    Robot::Actions::setIntake(1, BOTH);
    // turn to first ring and suck up
    chassis->turnToPoint(-22, 47, 500);
    chassis->moveToPoint(-25, 47, 900);
    delay(400);
    Robot::Pneumatics::mogoMech.retract();
    chassis->waitUntilDone();
    Robot::Actions::runIntakeFor(1, BOTH, 500, false);
    // drop mogo and move to next
    chassis->moveToPoint(-24, 36, 2000);
    chassis->moveToPose(-24, 26, 0, 2500, {.forwards=false});
    chassis->waitUntilDone();
    // grab next mogo
    Robot::Pneumatics::mogoMech.extend();
    delay(200);
    // turn to and move towards next ring with intake raised
    chassis->turnToPoint(-48, 0, 1000, {.minSpeed=90});
    delay(100);
    Robot::Actions::setIntake(1, BOTH);
    chassis->waitUntilDone();
    delay(500);
    Robot::Pneumatics::intakeLifter.extend();
    chassis->moveToPoint(-46, 0, 5000, {.maxSpeed=40,});
    chassis->waitUntilDone();
    // lower intake to finish sucking up
    Robot::Pneumatics::intakeLifter.retract();
    chassis->moveToPoint(-36, 24, 1000, {.forwards=false, .maxSpeed=70});
    chassis->waitUntilDone();
    delay(750);
    chassis->moveToPoint(-12, 3, 1000, {.maxSpeed=80});
    chassis->waitUntilDone();
    chassis->moveToPoint(-12, 3, 1000, {.maxSpeed=60});
    chassis->waitUntilDone();
    Robot::master.print(1, 1, "%f", (millis()-start)/1000);
    Robot::Actions::runIntakeFor(1, BOTH, 10000, false);
    return;

}
void Autons::supportBlue() {
    Robot::Pneumatics::mogoMech.retract(); // make sure mogo is not clamped.
    Robot::Pneumatics::intakeLifter.retract(); // make sure intake lifter is not lifted.
    Robot::Pneumatics::doinker.retract(); // make sure doinker is not out.
    if (!pros::competition::is_autonomous()) calibrate(); // calibrate if testing (not comp)

    chassis->setPose({50, 41, 47}); // set initial pose
    // move to mogo and pick up
    chassis->moveToPoint(32, 28, 1000, {.forwards=false, .maxSpeed=110, .minSpeed=40});
    chassis->waitUntilDone();
    Robot::Pneumatics::mogoMech.set_value(true);
    delay(200);
    // move towads ring while intaking
    chassis->turnToPoint(24, 48, 500);
    Robot::Actions::setIntake(1, Types::BOTH);
    chassis->moveToPoint(24.5, 46, 1000, {.maxSpeed=90, .minSpeed=40});
    // move back slightly to help with intaking
    chassis->moveToPoint(23, 44, 750, {.forwards=false});
    chassis->waitUntilDone();
    delay(750);
    // turn to, and navigate towards rings on auton line
    chassis->turnToPoint(3, 46.5, 800);
    delay(500);
    chassis->moveToPose(5, 47.5, 275, 1000, {.lead=0.5, .maxSpeed=80});
    chassis->waitUntilDone();
    // wait to suck up first ring
    delay(750);
    // suck up second ring
    chassis->moveToPose(24, 48, 260, 2000, {.forwards=false, .minSpeed=40});
    chassis->turnToPoint(0, 40, 750);
    chassis->moveToPoint(13, 39, 1000, {.maxSpeed=65, .minSpeed=30});
    chassis->waitUntilDone();
    // wait to suck up
    delay(1000);
    // move away
    chassis->moveToPose(10, 48, 180, 1000, {.forwards=false});
    // move towards ladder (helps w/ AWP)
    chassis->moveToPose(24, 24, 190, 3000);
    Robot::Actions::runIntakeFor(1, BOTH, 2500, true);
    chassis->waitUntilDone();
    return;
}
void Autons::supportTouchLadderBlue(){
    supportBlue();
    chassis->moveToPoint(24, 0, 1000, {.maxSpeed=90});
    chassis->moveToPoint(24, 0, 1000, {.maxSpeed=90});
    chassis->waitUntilDone();
    Robot::master.rumble("-");
}
void Autons::Skills::skillsRun() {
    if (!pros::competition::is_autonomous()) calibrate();
    chassis->setPose(-60, 0, 270);
    Robot::Actions::runIntakeFor(1, Types::BOTH, 1000, false);
    chassis->turnToPoint(-48, -24, 750, {.forwards=false});
    chassis->moveToPoint(-52, 50, 1000, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::mogoMech.extend();
    delay(350);
    Robot::Actions::setIntake(1, BOTH);
    chassis->moveToPoint(-24, -24, 1400);
    chassis->moveToPoint(-24, -48, 1000);
    
}
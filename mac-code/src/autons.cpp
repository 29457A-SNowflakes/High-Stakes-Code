#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "usr/robot.h"
#include "usr/autons.h"
#include "lemlib-tarball/api.hpp"

using namespace lemlib;
using namespace pros;


void Autons::Match::SAWP_Red() {
    Chassis* chassis = &Robot::chassis;
    Robot::playingColour="RED";
    LadyBrown::rotSens->reset_position();
    if (!pros::competition::is_connected()) {
        chassis->calibrate();
        delay(1500);
    }
    int start = millis();
    chassis->setPose(-50.5, -8.5, 296);

    // Alliance stake
    LadyBrown::moveTo("LOAD");
    delay(100);
    Robot::Actions::setIntakeFor(1, SECOND, 350, false);

    chassis->moveToPoint(-55.8, -6, 600, {.maxSpeed=110});

    int tmp = LadyBrown::timeout;
    LadyBrown::timeout=600;
    LadyBrown::moveToPoint(19000);
    LadyBrown::timeout=tmp;

    
    // 1st mogo grab
    chassis->moveToPoint(-28, -18.2, 1100, {.forwards=false});
    chassis->waitUntil(10);
    Robot::Actions::setIntakeFor(1, BOTH, 100, false);
    LadyBrown::moveTo("REST");
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();

    // middle ring stack
    chassis->turnToHeading(39.1, 600, {.direction=lemlib::AngularDirection::CW_CLOCKWISE}, false);
    chassis->moveToPose(-7, 0, 45, 1300, {.lead=0.1},false);
    //chassis->moveToPoint(-7, 0, 1000, {}, false);
    //chassis->turnToHeading(40, 300, {.minSpeed=50}, false);
    Robot::Pneumatics::primaryDoinker.extend(); delay(20);
    chassis->swingToHeading(88, lemlib::DriveSide::RIGHT, 800);
    chassis->waitUntilDone();
    Robot::Pneumatics::secondaryDoinker.extend(); delay(20);
    chassis->turnToPoint(-50, -85, 700, {.forwards=false});
    chassis->moveToPose(-40, -26, 95, 1800, {.forwards=false, .lead=0.5, .minSpeed=90});
    chassis->turnToHeading(90, 400);
    chassis->waitUntilDone();
    Robot::Pneumatics::primaryDoinker.retract();
    Robot::Pneumatics::secondaryDoinker.retract();
    chassis->turnToHeading(42, 800);
    Robot::Actions::setIntake(1, BOTH);
    chassis->moveToPoint(-19, -22, 800);
    chassis->turnToHeading(160, 1000);
    chassis->moveToPoint(-19, -40, 1000);
    chassis->turnToHeading(160, 1000);
    chassis->moveToPoint(-19, -45, 1000);
    chassis->waitUntilDone(); delay(850);
    chassis->moveToPoint(0, 0, 1000);
    LadyBrown::moveTo("DESCORE");
    chassis->waitUntilDone();
}
void Autons::Match::SAWP_Blue() {
    Robot::playingColour="BLUE";
    Chassis* chassis = &Robot::chassis;
    if (pros::competition::is_connected()) {
        chassis->calibrate();
        delay(1500);
    }

    
    int start = millis();
    chassis->setPose(50.5, -8.5, 64);

    // Alliance stake
    LadyBrown::moveTo("LOAD");
    delay(100);
    Robot::Actions::setIntakeFor(1, SECOND, 350, false);

    chassis->moveToPoint(55.8, -6, 600, {.maxSpeed=110});

    int tmp = LadyBrown::timeout;
    LadyBrown::timeout=600;
    LadyBrown::moveToPoint(19000);
    LadyBrown::timeout=tmp;

    
    // 1st mogo grab
    chassis->moveToPoint(28, -18.2, 1100, {.forwards=false});
    chassis->waitUntil(10);
    Robot::Actions::setIntakeFor(1, BOTH, 100, false);
    LadyBrown::moveTo("REST");
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();

    // middle ring stack
    chassis->turnToHeading(320.9, 600, {.direction=lemlib::AngularDirection::CW_CLOCKWISE}, false);
    chassis->moveToPose(7, 0, 135, 1300, {.lead=0.1},false);
    //chassis->moveToPoint(-7, 0, 1000, {}, false);
    //chassis->turnToHeading(40, 300, {.minSpeed=50}, false);
    Robot::Pneumatics::primaryDoinker.extend(); delay(20);
    chassis->swingToHeading(272, lemlib::DriveSide::RIGHT, 800);
    chassis->waitUntilDone();
    Robot::Pneumatics::secondaryDoinker.extend(); delay(20);
    chassis->turnToPoint(50, -85, 700, {.forwards=false});
    chassis->moveToPose(40, -26, 85, 1800, {.forwards=false, .lead=0.5, .minSpeed=90});
    chassis->turnToHeading(265, 400);
    chassis->waitUntilDone();
    Robot::Pneumatics::primaryDoinker.retract();
    Robot::Pneumatics::secondaryDoinker.retract();
    chassis->turnToHeading(355, 800);
    Robot::Actions::setIntake(1, BOTH);
    chassis->moveToPoint(19, -22, 800);
    chassis->turnToHeading(20, 1000);
    chassis->moveToPoint(19, -40, 1000);
    chassis->turnToHeading(200, 1000);
    chassis->moveToPoint(19, -45, 1000);
    chassis->waitUntilDone(); delay(850);
    chassis->moveToPoint(0, 0, 1000);
    LadyBrown::moveTo("DESCORE");
    chassis->waitUntilDone();
    
}
void Autons::Match::SPIN() {
    Robot::chassis.setPose(0, 0, 0);
    Robot::chassis.moveToPoint(0, 30, 1000);
    Robot::chassis.waitUntilDone();
    while (true) {
        delay(30);
        Robot::chassis.arcade(0, 127);
    }
}
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
    LadyBrown::rotSens->reset_position();
    if (pros::competition::is_connected()) {
        chassis->calibrate();
        delay(1500);
    }

    chassis->setPose(-58.5, -10.9, 270);

    // Alliance stake
    LadyBrown::moveTo("LOAD");
    delay(200);
    Robot::Actions::setIntakeFor(1, SECOND, 350, false);
    chassis->turnToHeading(320, 800, {}, false);
    chassis->moveToPoint(-72, 0, 100);
    Robot::Actions::setIntakeFor(-10.0/127.0, SECOND, 10, false);

    int tmp = LadyBrown::timeout;
    LadyBrown::timeout=800;
    LadyBrown::moveToPoint(19000);
    LadyBrown::timeout=tmp;
    
    // 1st mogo grab
    chassis->moveToPoint(-53, -11, 500, {.forwards=false, .minSpeed=60}, false);
    chassis->turnToHeading(277, 500);
    LadyBrown::moveTo("REST");
    chassis->moveToPoint(-22, -23, 1000, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();

    // middle ring stack
    chassis->turnToHeading(35, 800, {}, false);
    chassis->moveToPoint(-8, -5, 2000, {.maxSpeed=70});
    chassis->turnToHeading(35, 800, {});
    chassis->waitUntilDone();
    Robot::Pneumatics::primaryDoinker.extend();
    delay(500);

    chassis->turnToPoint(-40, -34, 500, {.forwards=false});
    chassis->moveToPoint(-40, -34, 2000, {.forwards=false}, false);
    Robot::Pneumatics::primaryDoinker.retract();
    delay(200);
    Robot::Actions::setIntake(1, BOTH);
    chassis->moveToPoint(-18, -47, 2000);
    chassis->turnToHeading(180, 800, {}, false);
    delay(1000);
    Robot::Pneumatics::Mogo.retract();
    chassis->moveToPoint(-18, -55, 1000, {}, false);
    chassis->turnToHeading(270, 600);
    return;
}
void Autons::Match::SAWP_Blue() {
    Chassis* chassis = &Robot::chassis;
    if (pros::competition::is_connected()) {
        chassis->calibrate();
        delay(1500);
    }

    
}
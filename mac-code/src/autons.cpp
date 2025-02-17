#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.h"
#include "usr/robot.h"
#include "usr/autons.h"
#include "lemlib-tarball/api.hpp"

using namespace lemlib;
using namespace pros;


void Autons::Match::Solo_AWP_Red(){
    Chassis* chassis = &Robot::chassis;
    LadyBrown::rotSens->set_position(LadyBrown::states["LOAD"]);
    Robot::Pneumatics::Mogo.retract();
    // 57.9, 13.1
    if (!competition::is_field_control()) {
        chassis->calibrate();
        delay(1000);
    }
    chassis->setPose(-58, 13, 225);

    chassis->moveToPoint(-72, 0, 1000, {.maxSpeed=50});
    chassis->waitUntil(1);
    chassis->cancelMotion();
    LadyBrown::timeout = 1000;
    LadyBrown::moveToPoint(19000);

    chassis->moveToPoint(-41, 36, 1000, {.forwards=false, .maxSpeed=80, .minSpeed=30});
    chassis->waitUntil(3);
    LadyBrown::moveTo("REST");
    chassis->turnToPoint(-20, 22.5, 800, {.forwards=false});
    chassis->moveToPoint(-20, 22.5, 1300, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    Robot::Actions::setIntake(1, BOTH);
    chassis->turnToPoint(-19, 46, 700);
    chassis->moveToPoint(-19, 46, 1000, {.minSpeed=40});
    chassis->waitUntilDone();
    chassis->turnToPoint(-4, 46, 700);
    chassis->moveToPoint(-10, 46, 1500, {.maxSpeed=50});
    chassis->moveToPoint(-44, 48, 1000,{.forwards=false});
    chassis->turnToPoint(-44, 30, 500);
    chassis->moveToPoint(-44, 30, 1800, {.minSpeed=40, .earlyExitRange=3});
    chassis->turnToPoint(-44, -10, 500);
    chassis->moveToPoint(-44, -10, 2000);
    chassis->waitUntilDone();
    delay(200);
    Robot::Actions::setIntake(-1, SECOND);
    Robot::Pneumatics::Mogo.retract();
    chassis->turnToPoint(-13, -12, 750, {.forwards=false, .minSpeed=80});
    chassis->moveToPoint(-13, -12, 1300, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    chassis->turnToPoint(-16, -45, 800,{.minSpeed=80});
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, SECOND);
    chassis->turnToPoint(-20, -45, 1000,{.minSpeed=80});
    chassis->moveToPoint(-20, -45, 1000,{.minSpeed=80});
    chassis->waitUntilDone();
    delay(200);
    chassis->moveToPoint(-25, -25, 1500, {.forwards=false,.minSpeed=80});
    chassis->waitUntilDone();
    LadyBrown::moveTo("FLIP");
    chassis->turnToHeading(45, 1000);
    chassis->moveToPoint(0, 0, 1500, {.minSpeed=100});
    chassis->waitUntilDone();
    delay(5000);

}
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
void Autons::Match::Red_Ring_Side() {
    Chassis* chassis = &Robot::chassis;
    LadyBrown::rotSens->set_position(LadyBrown::states["LOAD"]);
    Robot::Pneumatics::Mogo.retract();
    // 57.9, 13.1
    if (!competition::is_field_control()) {
        chassis->calibrate();
        delay(1000);
    }
    int startTime = millis();
    chassis->setPose(-58.5, 15.5, 180);
    
    chassis->turnToPoint(-72, -24, 300, {.minSpeed=90});
    chassis->moveToPoint(-72, -24, 180);
    chassis->waitUntilDone();
    chassis->turnToPoint(-72, -24, 500, {.maxSpeed=60});
    LadyBrown::timeout = 800;
    LadyBrown::moveToPoint(19000);
    chassis->moveToPoint(-55, 36, 700, {.forwards=false, .minSpeed=60});
    chassis->waitUntilDone();
    LadyBrown::moveTo("REST");
    chassis->turnToPoint(-24, 24, 450, {.forwards=false, .minSpeed=20});
    chassis->moveToPoint(-24, 42, 950, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    chassis->turnToPoint(-36, 48, 700,{.minSpeed=30});
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, BOTH);
    chassis->moveToPoint(-36, 56, 900);
    chassis->turnToPoint(0, 59, 800);
    chassis->moveToPoint(-18, 59, 1000,{.maxSpeed=90});
    chassis->moveToPoint(-58, 55, 900,{.forwards=false});
    chassis->waitUntilDone();
    delay(2000);
    return;
    chassis->turnToHeading(50, 500, {.minSpeed=60});
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, BOTH);
    chassis->moveToPoint(-13, 46, 1000);
    chassis->turnToHeading(350, 300,{.minSpeed=60});
    chassis->moveToPoint(-17, 74, 1100, {.maxSpeed=80});
    chassis->waitUntilDone();
    delay(500);
    chassis->turnToHeading(270, 1000, {.minSpeed=50});
    chassis->moveToPoint(-44, 45, 1000,{.minSpeed=60});
    chassis->waitUntilDone();
    delay(750);
    chassis->turnToPoint(-72, 72, 2000, {.minSpeed=50});
    chassis->moveToPoint(-60, 60, 2000);
    chassis->turnToHeading(300, 600);
    chassis->moveToPoint(-96, 81, 1500, {.minSpeed=127});
    chassis->waitUntilDone();
    delay(100);
    chassis->moveToPoint(-96, 81, 800, {.minSpeed=127});
    chassis->moveToPoint(-62, 62, 500,{.forwards=false});
    chassis->moveToPoint(-96, 81, 800, {.minSpeed=127});
    chassis->moveToPoint(-62, 62, 500,{.forwards=false});
    chassis->waitUntilDone();
    Robot::master.rumble("-");
    delay(2000);
    return;
}
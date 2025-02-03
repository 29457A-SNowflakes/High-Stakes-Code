#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.hpp"
#include "pros/rtos.h"
#include "usr/robot.h"
#include "usr/autons.h"
#include "lemlib-tarball/api.hpp"

using namespace lemlib;
using namespace pros;


void Mogo_Rush_Blue() {}
void Mogo_Rush_Red() {}

void Ring_Rush_Blue() {}
void Ring_Rush_Red() {}

void Autons::Match::Solo_AWP_Blue() {
    Chassis* chassis = &Robot::chassis;
    // calibrate if testing 
    if (!pros::competition::is_connected()) {
        chassis->calibrate();
        delay(500);
    }
    // Set positions
    chassis->setPose(55, 17, 135);
    Robot::Sensors::LBRotation.set_position(LadyBrown::states["LOAD"]-200);

    // move to alliance
    chassis->moveToPoint(72, 0, 500, {.maxSpeed=60});
    chassis->waitUntil(1.75);
    chassis->cancelMotion();
    chassis->turnToPoint(72, 0, 400, {.earlyExitRange=3}, false);
    // score on alliance
    LadyBrown::moveToPoint(21000);
    chassis->moveToPoint(41, 35, 1250, {.forwards=false});
    chassis->waitUntil(4);
    LadyBrown::moveTo("REST", true);
    // turn towards mogo
    chassis->turnToPoint(24, 24, 800, {.forwards=false});
    // move to mogo
    chassis->moveToPoint(24, 24, 2000, {.forwards=false, .maxSpeed=60}, false);
    
    // pick up mogo when arrived
    Robot::Pneumatics::Mogo.extend();
    delay(150);
    chassis->turnToPoint(31, 48, 500, {.maxSpeed=60}, false);
    chassis->moveToPoint(31, 44, 750, {.maxSpeed=90});
    chassis->waitUntil(5);
    Robot::Actions::setIntake(1);
    chassis->waitUntilDone();
    delay(1300);
    chassis->moveToPoint(0, -20, 1500);
    LadyBrown::moveTo("FLIP");
    chassis->waitUntilDone();
    delay(15000);
    return;
    chassis->moveToPoint(45, 55.75, 1500, {.forwards=false, .maxSpeed=70}, false);
    chassis->turnToHeading(265, 500, {.maxSpeed=65}, false);
    chassis->moveToPoint(23, 55, 2000, {.maxSpeed=35});
    chassis->waitUntil(5);
    Robot::Pneumatics::doinker.extend();
    chassis->waitUntilDone();
    delay(100);
    chassis->moveToPoint(48, 60, 1500, {.forwards=false}, false);
    Robot::Pneumatics::doinker.retract();
    chassis->moveToPoint(25, 45, 1000, {}, false);
    chassis->moveToPoint(48, 40, 1000, {.forwards=false}, false);
    chassis->moveToPoint(0, -20, 1500);
    LadyBrown::moveTo("FLIP");
    chassis->waitUntilDone();
    delay(5000);
    return;
}
void Autons::Match::Solo_AWP_Red() {
    Chassis* chassis = &Robot::chassis;
    // calibrate if testing 
    if (!pros::competition::is_connected()) {
        chassis->calibrate();
        delay(500);
    }
    // Set positions
    chassis->setPose(-55, 17, 225);
    Robot::Sensors::LBRotation.set_position(LadyBrown::states["LOAD"]-200);

    // move to alliance
    chassis->moveToPoint(-72, 0, 500, {.maxSpeed=60});
    chassis->waitUntil(1.75);
    chassis->cancelMotion();
    chassis->turnToPoint(-72, 0, 400, {.earlyExitRange=3}, false);
    // score on alliance
    LadyBrown::moveToPoint(21000);
    chassis->moveToPoint(-41, 35, 1250, {.forwards=false});
    chassis->waitUntil(4);
    LadyBrown::moveTo("REST", true);
    // turn towards mogo
    chassis->turnToPoint(-24, 24, 800, {.forwards=false});
    // move to mogo
    chassis->moveToPoint(-24, 24, 2000, {.forwards=false, .maxSpeed=60}, false);
    
    // pick up mogo when arrived
    Robot::Pneumatics::Mogo.extend();
    delay(1250);
    chassis->turnToPoint(-31, 48, 500, {.maxSpeed=60}, false);
    chassis->moveToPoint(-31, 44, 750, {.maxSpeed=90});
    chassis->waitUntil(5);
    Robot::Actions::setIntake(1);
    chassis->waitUntilDone();
    delay(750);
    delay(15000);
    return;
    chassis->moveToPoint(-45, 55.75, 1500, {.forwards=false, .maxSpeed=70}, false);
    chassis->turnToHeading(95, 500, {.maxSpeed=65}, false);
    chassis->moveToPoint(-23, 55, 2000, {.maxSpeed=35});
    chassis->waitUntil(5);
    Robot::Pneumatics::doinker.extend();
    chassis->waitUntilDone();
    delay(100);
    chassis->moveToPoint(-48, 60, 1500, {.forwards=false}, false);
    Robot::Pneumatics::doinker.retract();
    chassis->moveToPoint(-25, 45, 1000, {}, false);
    chassis->moveToPoint(-48, 40, 1000, {.forwards=false}, false);
    chassis->moveToPoint(0, -20, 1500);
    LadyBrown::moveTo("FLIP");
    chassis->waitUntilDone();
    delay(5000);
    return;
}
ASSET(skillsPath_txt);
lemlib_tarball::Decoder decoder (skillsPath_txt);
void Autons::Skills::Skills() {

    Chassis* chassis = &Robot::chassis;

    Robot::Sensors::LBRotation.set_position(LadyBrown::states["LOAD"]+250);
    if (!pros::competition::is_connected()) {
        chassis->calibrate();
        delay(500);
    }

    chassis->setPose(-55, -17, 315);
    // move to alliance

    chassis->moveToPoint(-72, 0, 500, {.maxSpeed=60});
    chassis->waitUntil(1.5);
    chassis->cancelMotion();
    chassis->turnToPoint(-72, 0, 400, {.earlyExitRange=3}, false);
    // score on alliance
    LadyBrown::moveToPoint(21000);

    /*
    * - move towards mogo
    * - while moving LB to rest
    * - extend mogo when finished
    */
    chassis->moveToPoint(-45, -27, 1250, {.forwards=false, .maxSpeed=60, .earlyExitRange=2});
    chassis->waitUntil(4);
    LadyBrown::moveTo("REST");
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();

    delay(200);
    Robot::master.rumble("-");

    // intake movement to ensure settled mogo
    delay(500);
    Robot::Actions::setIntake(1);
    delay(500);
    Robot::Actions::setIntake(-1);

    // move to first ring
    chassis->turnToPoint(-28, -20, 1000, {.maxSpeed=60});
    chassis->moveToPoint(-28, -20, 1500, {.maxSpeed=60});
    chassis->waitUntil(4);
    Robot::Actions::setIntake(1);
    chassis->waitUntilDone();
    delay(1000);
    // move to second ring
    chassis->moveToPose(-24, -55, 180, 1000);
    chassis->waitUntilDone();
    delay(1500);
    // move to second ring
    chassis->moveToPoint(1, -52, 1500);
    chassis->waitUntil(5);
    LadyBrown::moveTo("LOAD");
    chassis->waitUntilDone();
    delay(400);
    chassis->moveToPoint(-3, -52, 1000, {.forwards=false, .maxSpeed=40});
    chassis->turnToHeading(173, 1000, {.maxSpeed=60});
    chassis->moveToPoint(0, -80, 1250, {.maxSpeed=40});
    chassis->waitUntilDone();
    delay(500);
    Robot::Actions::FlingRing(false);
    LadyBrown::moveToPoint(15500);
    Robot::Actions::setIntake(-1);
    delay(250);
    chassis->moveToPoint(0, -40, 1000, {.forwards=false}, false);
    LadyBrown::moveToPoint(7000);
    chassis->turnToPoint(-48, -50, 600, {.maxSpeed=80});
    chassis->moveToPoint(-35, -50, 1500);
    chassis->moveToPoint(-48, -50, 2000, {.maxSpeed=70});
    chassis->waitUntil(5);
    Robot::Actions::setIntake(1);
    chassis->waitUntilDone();
    delay(5000);
    Robot::Actions::setIntake(0);
}
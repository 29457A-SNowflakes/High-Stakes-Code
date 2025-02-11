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
    chassis->waitUntil(1);
    chassis->cancelMotion();
    chassis->turnToPoint(72, 0, 400, {.earlyExitRange=3}, false);
    // score on alliance
    LadyBrown::moveToPoint(21000);
    chassis->moveToPoint(41, 33, 1250, {.forwards=false});
    chassis->waitUntil(4);
    LadyBrown::moveTo("REST", true);
    // turn towards mogo
    chassis->turnToPoint(22, 22, 800, {.forwards=false});
    // move to mogo
    chassis->moveToPoint(22, 22, 2000, {.forwards=false, .maxSpeed=60}, false);
    
    // pick up mogo when arrived
    Robot::Actions::setIntake(-1, Intake_Action::SECOND);
    Robot::Pneumatics::Mogo.extend();
    delay(1250);
    chassis->turnToPoint(18, 42, 1000);
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
    chassis->moveToPoint(18, 40, 1500, {.maxSpeed=60});
    chassis->turnToHeading(270, 750);
    chassis->moveToPose(9, 43, 270, 3000, {.maxSpeed=50});
    chassis->waitUntilDone();
    delay(500);
    chassis->moveToPoint(28, 48, 1000, {.forwards=false});
    chassis->moveToPose(12, 12, 225, 2000);
    LadyBrown::moveTo("FLIP");
    chassis->waitUntilDone();
    delay(10000);
    return;
    chassis->turnToPoint(31, 48, 500, {.maxSpeed=60}, false);

    chassis->moveToPose(18, 13, 320, 2000, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
    chassis->moveToPose(9.75, 47, 0, 3500, {.maxSpeed=65});
    chassis->waitUntil(3);
    chassis->cancelMotion();
    delay(1000);
    chassis->moveToPose(9.75, 49, 0, 3500, {.maxSpeed=100, .minSpeed=50});
    chassis->waitUntilDone();
    delay(750);
    chassis->moveToPose(15, 54, 60, 1000);
    chassis->turnToPoint(23, 40, 1000);
    chassis->moveToPoint(23, 40, 1000);
    chassis->waitUntilDone();
    delay(1400);
    chassis->moveToPose(24, 0, 225, 2000);
    LadyBrown::moveTo("FLIP");
    chassis->waitUntilDone();
    delay(10000);
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
    chassis->waitUntil(1);
    chassis->cancelMotion();
    chassis->turnToPoint(-72, 0, 400, {.earlyExitRange=3}, false);
    // score on alliance
    LadyBrown::moveToPoint(21000);
    chassis->moveToPoint(-41, 33, 1250, {.forwards=false});
    chassis->waitUntil(4);
    LadyBrown::moveTo("REST", true);
    // turn towards mogo
    chassis->turnToPoint(-24, 22, 800, {.forwards=false});
    // move to mogo
    chassis->moveToPoint(-24, 22, 2000, {.forwards=false, .maxSpeed=60}, false);
    
    // pick up mogo when arrived
    Robot::Actions::setIntake(-1, Intake_Action::SECOND);
    Robot::Pneumatics::Mogo.extend();
    delay(1250);
    chassis->turnToPoint(-22, 42, 1000, {.maxSpeed=80});
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
    chassis->moveToPoint(-22, 40, 1500, {.maxSpeed=60});
    chassis->turnToHeading(90, 750);
    chassis->moveToPose(-9, 43, 90, 3000, {.maxSpeed=50});
    chassis->waitUntilDone();
    delay(500);
    chassis->moveToPoint(-28, 48, 1000, {.forwards=false});
    chassis->moveToPose(-12.5, 12, 135, 2000);
    LadyBrown::moveTo("FLIP");
    chassis->waitUntilDone();
    delay(10000);
    return;

    chassis->moveToPose(-18, 13, 50, 2000, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
    chassis->moveToPose(-10.75, 47, 0, 3500, {.maxSpeed=65});
    chassis->waitUntil(3);
    chassis->cancelMotion();
    delay(750);
    chassis->moveToPose(-10.75, 51, 0, 3500, {.minSpeed=70});
    chassis->waitUntilDone();
    delay(750);
    chassis->moveToPose(-15, 54, 300, 1000);
    chassis->turnToPoint(-23, 40, 1000);
    chassis->moveToPoint(-23, 40, 1000);
    chassis->waitUntilDone();
    delay(750);
    chassis->moveToPose(-24, 0, 135, 2000);
    LadyBrown::moveTo("FLIP");
    chassis->waitUntilDone();
    delay(10000);
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
    chassis->waitUntil(2.75);
    LadyBrown::moveTo("REST");
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();

    delay(200);
    Robot::master.rumble("-");

    // intake movement to ensure settled mogo
    delay(500);
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
    delay(500);
    Robot::Actions::setIntake(-1, Intake_Action::SECOND);

    // move to first ring
    chassis->turnToPoint(-28, -20, 1000, {.maxSpeed=60});
    chassis->moveToPoint(-28, -20, 1500, {.maxSpeed=60});
    chassis->waitUntil(4);
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
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
    Robot::Actions::setIntake(-1, Intake_Action::SECOND);
    delay(250);
    chassis->moveToPoint(0, -40, 1000, {.forwards=false}, false);
    LadyBrown::moveToPoint(7000);
    chassis->turnToPoint(-48, -50, 600, {.maxSpeed=80}, false);
    chassis->moveToPoint(-35, -50, 1500);
    chassis->moveToPoint(-52, -50, 2000, {.maxSpeed=70});
    chassis->waitUntil(5);
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
    chassis->waitUntilDone();
    chassis->moveToPose(-72, -72, 10000, 45,{.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.retract();
    delay(500);
    chassis->moveToPoint(0, 24, 5000);
    chassis->moveToPoint(60, 60, 5000);
    chassis->moveToPoint(72, -72, 10000);
    chassis->waitUntilDone();
    delay(5000);
    Robot::Actions::setIntake(0, Intake_Action::BOTH);
}


void Autons::Match::Mogo_Side_Elims_R() {
    Chassis* chassis = &Robot::chassis;
    Robot::Pneumatics::Mogo.retract();

    // calibrate if testing 
    if (!pros::competition::is_connected()) {
        chassis->calibrate();
        delay(500);
    }

    // Set positions
    chassis->setPose(55, 17, 135);
    Robot::Sensors::LBRotation.set_position(LadyBrown::states["LOAD"]-200);
    // move to alliance
    chassis->moveToPoint(72, 0, 500, {.maxSpeed=40});
    chassis->waitUntil(1.5);
    chassis->cancelMotion();
    chassis->turnToPoint(72, 0, 1000, {}, false);

    // score on alliance
    LadyBrown::moveToPoint(21000);

    // move away from alliance
    chassis->moveToPoint(45, 30, 1250, {.forwards=false});
    chassis->waitUntil(7);

    // retract LB
    LadyBrown::moveTo("REST", true);

    // turn to and drive into mogo 1
    chassis->turnToPoint(21, 18.5, 1000, {.forwards=false, .maxSpeed=80});
    chassis->moveToPoint(21, 18.5, 1000, {.forwards=false, .maxSpeed=80});
    chassis->waitUntilDone();
    delay(200);
    Robot::Pneumatics::Mogo.extend();
    delay(500);

    // ensure good clamp
    Robot::Actions::setIntake(-1, Intake_Action::SECOND);
    delay(750);
    
    // drive into ring 1
    chassis->turnToPoint(24, 48, 500);
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
    chassis->moveToPoint(24, 40, 1000);
    chassis->waitUntilDone();
    delay(1000);

    // turn to corner stack
    chassis->turnToPoint(72, 72, 500);
    chassis->waitUntilDone();

    // extend doinker and move to corner
    Robot::Pneumatics::doinker.extend();;
    chassis->moveToPoint(72, 69, 700, {.maxSpeed=100, .minSpeed=20,});
    chassis->waitUntilDone();
    Robot::Actions::setIntake(0, Intake_Action::BOTH);
    chassis->turnToHeading(45, 250);
    chassis->waitUntilDone();

    // clear corner
    chassis->turnToHeading(340, 1500);
    chassis->waitUntilDone();
    Robot::Pneumatics::doinker.retract();
    chassis->turnToHeading(50, 750);
    chassis->waitUntilDone();
    Robot::Pneumatics::doinker.extend();
    chassis->turnToHeading(340, 1500);
    chassis->waitUntilDone();
    Robot::Pneumatics::doinker.retract();
    

    // move away from stack to get 3rd ring
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
    chassis->moveToPose(48, 40, 0, 1000, {.forwards=false});
    chassis->moveToPose(48, 90, 0, 1300);
    chassis->moveToPose(48, 40, 0, 800, {.forwards=false, .maxSpeed=60});
    chassis->waitUntilDone();

    // place mogo near corner
    delay(1000);
    chassis->turnToHeading(260, 750);
    chassis->moveToPose(72, 72, 225, 1500, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.retract();
    Robot::Actions::setIntakeFor(-1, Intake_Action::BOTH, 500, false);

    // move to 3rd mogo control
    chassis->moveToPose(28, 48, 90, 1300);
    chassis->waitUntilDone();
    chassis->turnToHeading(90, 400);

    chassis->waitUntilDone();
    Robot::master.rumble("-");
    delay(10000);
}
void Autons::Match::Mogo_Side_Elims_B() {
    Chassis* chassis = &Robot::chassis;
    Robot::Pneumatics::Mogo.retract();

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
    chassis->waitUntil(1);
    chassis->cancelMotion();
    chassis->turnToPoint(-72, 0, 400, {.earlyExitRange=3}, false);

    // score on alliance
    LadyBrown::moveToPoint(21000);

    // move away from alliance
    chassis->moveToPoint(-45, 30, 1250, {.forwards=false});
    chassis->waitUntil(4);

    // retract LB
    LadyBrown::moveTo("REST", true);

    // turn to and drive into mogo 1
    chassis->turnToPoint(-21, 18.5, 1000, {.forwards=false, .maxSpeed=50});
    chassis->moveToPoint(-21, 18.5, 1000, {.forwards=false, .maxSpeed=50});
    chassis->waitUntilDone();
    delay(200);
    Robot::Pneumatics::Mogo.extend();

    // ensure good clamp
    Robot::Actions::setIntake(-1, Intake_Action::SECOND);
    delay(750);
    
    // drive into ring 1
    chassis->turnToPoint(-24, 48, 500);
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
    chassis->moveToPoint(-24, 40, 1000);
    chassis->waitUntilDone();
    delay(500);

    // turn to corner stack
    chassis->turnToPoint(-72, 72, 500);
    chassis->waitUntilDone();

    // extend doinker and move to corner
    Robot::Pneumatics::doinker.extend();;
    chassis->moveToPoint(-72, 69, 700, {.maxSpeed=100, .minSpeed=20,});
    chassis->waitUntilDone();
    Robot::Actions::setIntake(0, Intake_Action::BOTH);
    chassis->turnToHeading(315, 250);
    chassis->waitUntilDone();

    // clear corner
    chassis->turnToHeading(265, 1500);
    chassis->waitUntilDone();
    Robot::Pneumatics::doinker.retract();
    chassis->turnToHeading(315, 750);
    chassis->waitUntilDone();
    Robot::Pneumatics::doinker.extend();
    chassis->turnToHeading(265, 1500);
    chassis->waitUntilDone();
    Robot::Pneumatics::doinker.retract();
    

    // move away from stack to get 3rd ring
    Robot::Actions::setIntake(1, Intake_Action::BOTH);
    chassis->moveToPose(-40, 52, 90, 1000, {.forwards=false});
    chassis->moveToPose(-90, 40, 90, 1300);
    chassis->moveToPose(-40, 52, 90, 800, {.forwards=false, .maxSpeed=60});
    chassis->waitUntilDone();

    // place mogo near corner
    delay(1500);
    chassis->turnToHeading(260, 750);
    chassis->moveToPose(-72, 72, 135, 1500, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.retract();
    Robot::Actions::setIntakeFor(-1, Intake_Action::BOTH, 500, false);

    // move to 3rd mogo control
    chassis->moveToPose(-28, 48, 270, 1300);
    chassis->waitUntilDone();
    chassis->turnToHeading(270, 400);

    chassis->waitUntilDone();
    Robot::master.rumble("-");
    delay(10000);
}
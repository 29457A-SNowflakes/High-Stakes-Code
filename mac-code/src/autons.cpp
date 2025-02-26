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
    int startTime = millis();
    chassis->setPose(-58.5, 15.5, 180);
    
    chassis->turnToPoint(-72, -24, 300, {.minSpeed=90});
    chassis->moveToPoint(-72, -24, 180);
    chassis->waitUntilDone();
    chassis->turnToPoint(-72, -24, 500, {.maxSpeed=60});
    LadyBrown::timeout = 800;
    LadyBrown::moveToPoint(19000);
    chassis->moveToPoint(-55, 30, 600, {.forwards=false, .minSpeed=60});
    chassis->waitUntilDone();
    LadyBrown::moveTo("REST");
    chassis->turnToPoint(-26, 39, 400, {.forwards=false, .minSpeed=20});
    chassis->moveToPoint(-26, 39, 700, {.forwards=false, .maxSpeed=100});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    chassis->turnToPoint(-37, 50, 600);
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, BOTH);
    chassis->moveToPoint(-37, 56, 800, {.minSpeed=30});
    chassis->waitUntilDone();
    delay(200);
    chassis->turnToHeading(270, 600);
    chassis->moveToPose(-67, 5, 180, 1500);
    chassis->turnToPoint(-67, -30, 700);
    chassis->moveToPoint(-67, -34, 700, {.maxSpeed=70});
    chassis->waitUntilDone();
    delay(2000);
    Robot::Pneumatics::Mogo.retract();
    Robot::Actions::setIntake(0, SECOND);
    chassis->moveToPoint(-67, -48, 500);
    chassis->turnToPoint(-43, -7, 500, {.forwards=false, .minSpeed=60});
    chassis->moveToPoint(-43, 0, 1200, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    delay(130);
    chassis->turnToPoint(-52, -30, 800);
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, SECOND);
    chassis->moveToPoint(-52, -36, 1000);
    chassis->waitUntilDone();
    delay(800);
    pros::Task t ([=] {
        LadyBrown::moveToPoint(9000);
    });
    chassis->moveToPose(-30, 25, 180+45, 4000,{.forwards=false});
    Robot::master.rumble("-");
    delay(2000);
}
void Autons::Match::Red_Ring_Side() {
    Chassis* chassis = &Robot::chassis;
    LadyBrown::rotSens->set_position(LadyBrown::states["LOAD"]);
    Robot::Pneumatics::Mogo.retract();
    // 57.9, 13.1
    if (!competition::is_field_control()) {
        chassis->calibrate();
        delay(2000);
    }
    int startTime = millis();
    chassis->setPose(-58.5, 15.5, 180);

    chassis->turnToPoint(-69, -5, 400, {.minSpeed=40}, false);
    chassis->moveToPoint(-69, -5, 400);
    chassis->waitUntil(0.7);
    chassis->cancelAllMotions();

    LadyBrown::timeout = 800;
    LadyBrown::moveToPoint(19000);
    LadyBrown::timeout = 2000;
    chassis->moveToPoint(-54, 22, 600, {.forwards=false, .minSpeed=60});
    delay(5);
    LadyBrown::moveTo("REST");

    chassis->turnToPoint(-20, 30, 400, {.forwards=false, .minSpeed=60});
    chassis->moveToPoint(-22, 30, 875, {.forwards=false, .minSpeed=20});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    
    chassis->turnToHeading(-20, 800, {}, false);
    chassis->moveToPoint(-15, 43, 2500, {.minSpeed=70});
    chassis->waitUntil(2);
    Robot::Actions::setIntake(1, BOTH);

    chassis->moveToPoint(-24, 31, 1000, {.forwards=false, .minSpeed=20});
    chassis->turnToPoint(-27, 48, 900);

    chassis->moveToPoint(-27, 51, 900, {.minSpeed=40});
    chassis->waitUntilDone();


    chassis->turnToHeading(70, 800, {.minSpeed=45});
    chassis->moveToPoint(-16, 60, 700);

    chassis->moveToPoint(-55, 50, 1000, {.forwards=false, .minSpeed=70});
    
    chassis->turnToPoint(-72, 72, 1000);
    chassis->moveToPoint(-72, 72, 1400, {.minSpeed=60});
    chassis->waitUntilDone();
    chassis->moveToPoint(-58, 58, 250, {.forwards=false, .minSpeed=100});
    chassis->waitUntilDone();
    delay(500);
    //chassis->turnToPoint(-72, 72, 1000);
    //chassis->moveToPoint(-72, 72, 1000);
    //chassis->moveToPoint(-58, 58, 250, {.forwards=false, .minSpeed=100});
    //chassis->turnToPoint(-72, 72, 1000);
    //chassis->moveToPoint(-72, 72, 1000);

    chassis->moveToPoint(-48, -80, 1500, {.forwards=false, .minSpeed=127});
    //chassis->turnToHeading(180, 800);
    
    chassis->waitUntilDone();
    Robot::master.rumble(".");
    float elasped = (millis()-startTime)/1000.0;
    delay(2000);
    Robot::Actions::setIntake(0, BOTH);
    Robot::Screen::printConsole.println("");
    Robot::Screen::printConsole.printf("%f", elasped);
    delay(10000);
    return;
}
ASSET(rushPathRed_txt)
void Autons::Match::Red_Mogo_RUSH() {
    Chassis* chassis = &Robot::chassis;
    Robot::Pneumatics::Mogo.retract();
    // 57.9, 13.1
    if (!competition::is_field_control()) {
        chassis->calibrate();
        delay(2000);
    }
    int startTime = millis();
    chassis->setPose(-51.975, -31.158, 99);
    chassis->moveToPoint(-13.3, -36.204, 1500, {.minSpeed=100, .earlyExitRange=0.1});
    chassis->waitUntil(5);
    Robot::Pneumatics::doinker.extend();
    chassis->waitUntilDone();
    Robot::Pneumatics::doinker.retract();
    delay(50);
    chassis->moveToPoint(-55, -36, 1000, {.forwards=false});
    chassis->waitUntil(15);
    Robot::Pneumatics::doinker.extend();
    chassis->waitUntilDone();
    chassis->turnToHeading(180, 1000, {.minSpeed=70});
    chassis->waitUntilDone();
    Robot::Pneumatics::doinker.retract();
    chassis->moveToPoint(-40, -7, 1700, {.forwards=false, .maxSpeed=70});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    delay(100);
    Robot::Actions::setIntake(1, BOTH);
    delay(400);
    chassis->turnToHeading(180, 900);
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.retract();
    Robot::Actions::setIntake(0, SECOND);
    chassis->moveToPoint(-26.5, -40, 1400, {.minSpeed=40});
    chassis->turnToHeading(270, 800);
    chassis->moveToPoint(-13, -35, 900, {.forwards=false, .maxSpeed=90});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    delay(100);
    Robot::Actions::setIntake(1, SECOND);
    delay(5000);
}
ASSET(skillsPaths_txt)
void Autons::Skills::Skills() {
    Chassis* chassis = &Robot::chassis;
    Robot::Pneumatics::Mogo.retract();

    if (!competition::is_field_control()) {
        chassis->calibrate();
        delay(2000);
    }
    LadyBrown::rotSens->set_position(LadyBrown::states["LOAD"]+650);
    chassis->setPose(-57, 0, 270);
    LadyBrown::timeout = 1000;
    LadyBrown::moveToPoint(18000);
    LadyBrown::timeout = 1500;
    LadyBrown::moveTo("REST");
    chassis->moveToPoint(-49, 0, 1000, {.forwards=false, .minSpeed=90});
    chassis->waitUntilDone();
    chassis->turnToPoint(-44, -25, 600, {.forwards=false});
    chassis->moveToPoint(-44, -26, 1000, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    chassis->turnToHeading(90, 800);
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, BOTH);
    chassis->moveToPoint(-24, -18, 1400, {.maxSpeed=100});
    chassis->waitUntilDone();
    delay(500);
    chassis->turnToHeading(125, 600);
    chassis->waitUntilDone();
    chassis->moveToPoint(2, -43, 1000);
    chassis->waitUntil(12);
    LadyBrown::moveTo("LOAD");
    chassis->turnToHeading(180, 800);
    chassis->moveToPoint(2, -55, 900, {.maxSpeed=50});
    chassis->waitUntilDone();
    delay(1400);
    Robot::Actions::setIntake(0, SECOND);
    chassis->turnToHeading(180, 300);
    chassis->waitUntilDone();
    LadyBrown::moveToPoint(18000);
    chassis->moveToPoint(5, -24, 1300, {.forwards=false});
    chassis->waitUntilDone();
    LadyBrown::moveTo("REST");
    return;
    Robot::Actions::setIntake(1, BOTH);
    chassis->turnToHeading(270, 1000);
    chassis->moveToPoint(-24, -24, 900);
    chassis->moveToPoint(-48, -40, 1000);
    chassis->waitUntilDone();
}
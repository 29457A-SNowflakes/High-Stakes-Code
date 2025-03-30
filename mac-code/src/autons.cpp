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


void Autons::Match::Red_Ring_Side(){
    Robot::playingColour="RED";
    Chassis* chassis = &Robot::chassis;
    LadyBrown::rotSens->set_position(LadyBrown::states["LOAD"]+630);
    Robot::Pneumatics::Mogo.retract();
    // 57.9, 13.1
    if (!competition::is_field_control()) {
        chassis->calibrate();
        delay(1000);
    }
    int startTime = millis();
    chassis->setPose(-52.7, 15.5, 180);
    chassis->turnToHeading(225, 600);
    chassis->moveToPoint(-59, 10, 500);
    chassis->waitUntilDone();

    LadyBrown::timeout=900;
    LadyBrown::moveToPoint(19000);

    chassis->moveToPoint(-43, 40, 1000, {.forwards=false});
    chassis->waitUntil(5);
    LadyBrown::moveTo("REST");
    chassis->waitUntilDone();

    chassis->turnToHeading(304, 800);
    chassis->moveToPoint(-18, 35, 1300, {.forwards=false, .minSpeed=80});
    chassis->waitUntilDone();

    Robot::Pneumatics::Mogo.extend();

    chassis->turnToHeading(0, 800);
    chassis->moveToPoint(-8.4, 42.2, 1000);
    chassis->waitUntilDone();
    chassis->moveToPoint(-3.5, 54, 1400, {.maxSpeed=90});
    chassis->waitUntil(5);
    Robot::Actions::setIntake(1, BOTH);
    chassis->waitUntilDone();
    delay(300);
    chassis->moveToPoint(-16.5, 35, 900, {.forwards=false});
    chassis->turnToHeading(0, 900);
    chassis->moveToPoint(-23, 62, 900);
    chassis->waitUntilDone();
    chassis->turnToHeading(55, 900);
    chassis->moveToPoint(-2.5, 67, 1200);
    chassis->moveToPoint(-20, 67, 1000, {.forwards=false});
    chassis->turnToHeading(180, 1000);
    chassis->moveToPoint(-40, 10, 1000);
    chassis->waitUntilDone();
    delay(5000);
    return;
    chassis->turnToHeading(260, 800);
    chassis->moveToPoint(-65, 84, 2000, {.minSpeed=20});
    chassis->moveToPoint(-30, 42, 2000, {.forwards=false, .minSpeed=80});
    chassis->turnToHeading(180, 1000);
    chassis->waitUntilDone();
    delay(3000);
    return;
    
}
void Autons::Match::Blue_Ring_Side(){
    Robot::playingColour="BLUE";
    Chassis* chassis = &Robot::chassis;
    LadyBrown::rotSens->set_position(LadyBrown::states["LOAD"]+630);
    Robot::Pneumatics::Mogo.retract();
    // 57.9, 13.1
    if (!competition::is_field_control() && false) {
        chassis->calibrate();
        delay(1000);
    }
    int startTime = millis();
    chassis->setPose(52.7, 15.5, 180);
    chassis->turnToHeading(138, 600);
    chassis->moveToPoint(58.5, 6.8, 350, {.maxSpeed=80});
    chassis->waitUntilDone();
    LadyBrown::timeout=900;
    LadyBrown::moveToPoint(19000);
    chassis->moveToPoint(39.5, 32, 1000, {.forwards=false}); 
    chassis->waitUntil(5);
    LadyBrown::moveTo("REST");
    chassis->waitUntilDone();
    chassis->turnToHeading(80, 800);
    chassis->moveToPoint(25.5, 28, 2000, {.forwards=false, .maxSpeed=80});
    chassis->waitUntilDone();

    Robot::Pneumatics::Mogo.extend();

    chassis->turnToHeading(0, 800);
    chassis->waitUntilDone();
    chassis->moveToPoint(11, 52.6, 1400, {.maxSpeed=90});
    chassis->waitUntil(5);
    Robot::Actions::setIntake(1, BOTH);
    chassis->waitUntilDone();
    chassis->moveToPoint(26, 37, 900, {.forwards=false});
    chassis->turnToHeading(0, 900);
    chassis->waitUntilDone();
    chassis->moveToPoint(29, 60, 900);
    chassis->waitUntilDone();
    delay(1000);
    chassis->turnToHeading(-66, 900);
    chassis->moveToPoint(11, 63, 1200);
    chassis->waitUntilDone(); return;
    chassis->moveToPoint(20, 67, 1000, {.forwards=false});
    chassis->turnToHeading(-260, 800);
    chassis->moveToPoint(65, 84, 2000, {.minSpeed=20});
    chassis->moveToPoint(30, 42, 2000, {.forwards=false, .minSpeed=80});
    chassis->turnToHeading(180, 1000);
    chassis->waitUntilDone();
    delay(3000);
    return;
}
void Autons::Match::Solo_AWP_Red() {
    Chassis* chassis = &Robot::chassis;
    LadyBrown::rotSens->set_position(LadyBrown::states["LOAD"]+650);
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
    chassis->waitUntil(1.2);
    chassis->cancelAllMotions();
    LadyBrown::timeout = 800;
    LadyBrown::moveToPoint(19000);
    LadyBrown::timeout = 2000;
    chassis->moveToPoint(-56, 19, 600, {.forwards=false, .minSpeed=60});
    delay(5);
    LadyBrown::moveTo("REST");

    chassis->turnToPoint(-20, 35, 400, {.forwards=false, .minSpeed=60});
    chassis->moveToPoint(-20, 35, 1200, {.forwards=false, .minSpeed=20});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    chassis->turnToHeading(-20, 800, {}, false);
    chassis->moveToPoint(-15, 43, 2500, {.minSpeed=70});
    chassis->waitUntil(2);
    Robot::Actions::setIntake(1, BOTH);
    chassis->waitUntilDone(); return;
    
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

    Robot::playingColour = "RED";

    if (!competition::is_field_control()) {
        chassis->calibrate();
        delay(2000);
    }
    LadyBrown::rotSens->set_position(LadyBrown::states["LOAD"]+900);
    chassis->setPose(-57, 0, 270);
    LadyBrown::timeout = 1000;
    LadyBrown::moveToPoint(18000);
    LadyBrown::timeout = 2500;
    LadyBrown::moveTo("REST");
    chassis->moveToPoint(-48, 0, 1000, {.forwards=false, .minSpeed=90});
    chassis->waitUntilDone();
    chassis->turnToHeading(0, 800);
    chassis->moveToPoint(-40, -24, 1000, {.forwards=false});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    chassis->turnToHeading(90, 800);
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, BOTH);
    chassis->moveToPoint(-10, -25, 1000);
    chassis->waitUntilDone();
    delay(300);
    chassis->turnToHeading(130, 600);
    chassis->moveToPoint(37, -50, 2500);
    chassis->waitUntilDone();
    Robot::Sensors::LBRotation.set_position(0);
    delay(100);
    chassis->moveToPoint(12, -45, 2000, {.forwards=false, .maxSpeed=90});
    chassis->waitUntilDone();
    LadyBrown::moveTo("LOAD");
    chassis->moveToPoint(11, -59, 1200, {.maxSpeed=90});
    delay(1500);
    chassis->turnToHeading(180, 1500, {.minSpeed=100});
    chassis->moveToPoint(10, -66, 1500, {.minSpeed=50});
    chassis->waitUntilDone();
    Robot::Actions::setIntake(0, BOTH);
    chassis->setPose(0, -61.2, chassis->getPose().theta);
    delay(100);
    LadyBrown::timeout = 1400;
    Robot::Actions::setIntake(-1, BOTH);
    delay(50);
    Robot::Actions::setIntake(0, BOTH);
    LadyBrown::moveToPoint(16500);
    chassis->moveToPoint(-0.5, -53, 900, {.forwards=false});
    chassis->waitUntilDone();
    LadyBrown::moveTo("REST");
    Robot::Actions::setIntake(1, BOTH);
    chassis->turnToPoint(-24, -48, 800);
    chassis->moveToPoint(-24, -48, 2000, {.maxSpeed=80});
    chassis->moveToPoint(-48, -52, 2000, {.maxSpeed=80});
    chassis->moveToPoint(-48, -52, 2000, {.maxSpeed=80});
    chassis->moveToPoint(-63, -52, 2000, {.maxSpeed=80});
    chassis->moveToPoint(-45, -52, 2000, {.forwards=false, .maxSpeed=80});
    chassis->waitUntilDone();
    delay(100);
    chassis->turnToHeading(190, 900);
    chassis->moveToPoint(-49, -68, 2000, {.maxSpeed=80});
    chassis->turnToHeading(56, 800);
    chassis->waitUntilDone();
    Robot::Actions::setIntake(-1, BOTH);
    chassis->moveToPoint(-53, -64, 500, {.forwards=false});
    chassis->waitUntil(5);
    Robot::Pneumatics::Mogo.retract();
    chassis->turnToHeading(0, 800, {.minSpeed=70});
    chassis->moveToPoint(-40, -10, 2000);
    chassis->turnToHeading(180, 800);
    chassis->moveToPoint(-39, 19, 2000, {.forwards=false, .maxSpeed=90});
    chassis->waitUntilDone();
    Robot::Pneumatics::Mogo.extend();
    chassis->turnToHeading(90, 600);
    chassis->waitUntilDone();
    Robot::Actions::setIntake(1, BOTH);
    chassis->moveToPoint(-9, 15.7, 1200);
    chassis->turnToHeading(57.5, 600);
    chassis->turnToPoint(40, 35, 1000);
    chassis->waitUntilDone();
}
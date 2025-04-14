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

    chassis->setPose(-51.5, -10.9, 270);

    // Alliance stake
    LadyBrown::moveTo("LOAD");
    delay(200);
    Robot::Actions::setIntakeFor(1, SECOND, 350, false);
    chassis->turnToHeading(300, 500, {}, false);
    Robot::Actions::FlingRing(true, 5, 20);
    LadyBrown::moveToPoint(19000);
}
void Autons::Match::SAWP_Blue() {
    Chassis* chassis = &Robot::chassis;
    if (pros::competition::is_connected()) {
        chassis->calibrate();
        delay(1500);
    }

    
}
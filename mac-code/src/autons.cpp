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
    if (pros::competition::is_connected()) {
        chassis->calibrate();
        delay(1500);
    }

    
}
void Autons::Match::SAWP_Blue() {
    Chassis* chassis = &Robot::chassis;
    if (pros::competition::is_connected()) {
        chassis->calibrate();
        delay(1500);
    }

    
}
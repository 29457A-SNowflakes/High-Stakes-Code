#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"
#include "usr/robot.h"
#include "usr/utils.h"

using namespace pros;
using namespace lemlib;
using namespace std;
using namespace utils;
void Robot::Inits::initAll() {
    chassis.calibrate();
    //initPIDs();
    delay(2000);
    Robot::Sensors::LBRotation.reset_position();

    Robot::Inits::colourSort();

    //! Deprecated
    pros::Task limitWatcher ([=]{
        return;
        while (true) {
            delay(30);
            if (Robot::Sensors::LBLimiter.get_new_press()) {
                while (Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
                    delay(20);
                }
                LadyBrown::rotSens->set_position(-200);
            }
        }
    });
}
/*
void Robot::Inits::initPIDs() {

	float LatP = load_value("latP");
	float LatI = load_value("latI");
	float LatD = load_value("latD");

	float AngularP = load_value("angP");
	float AngularI = load_value("angI");
	float AngularD = load_value("angD");

	Auton::Tuning::latController.kP = LatP;
    Auton::Tuning::latController.kI = LatI;
    Robot::Auton::Tuning::latController.kD = LatD;

    Auton::Tuning::angularController.kP = AngularP;
    Auton::Tuning::angularController.kI = AngularI;
    Auton::Tuning::angularController.kD = AngularD;
        
    chassis.changeAngularP(10);
    chassis.changeAngularI(0);
    chassis.changeAngularD(5);
	
	chassis.changeLatP(8);
	chassis.changeLatI(0);
	chassis.changeLatD(4);
}
*/
#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/rtos.hpp"
#include "usr/robot.h"
#include "usr/utils.h"
using namespace utils;



void Robot::Init::initPIDs() {

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
        
    chassis.changeAngularP(AngularP);
    chassis.changeAngularI(AngularI);
    chassis.changeAngularD(AngularD);
	
	chassis.changeLatP(LatP);
	chassis.changeLatI(LatI);
	chassis.changeLatD(LatD);
}
void Robot::Init::initDriveCurves() {};

void Robot::Init::initAll() {
    initPIDs();
    pros::delay(50);
    chassis.calibrate();
    Robot::Auton::autonSelectorMain.focus();
    pros::Task mogoWatcher ([=] {
        while (true) {
            pros::delay(250);
            Robot::master.clear_line(1);
            Robot::master.print(1, 1, "%s", Robot::Pneumatics::mogoMech.is_extended() ? "0":"1");
        }
    });
    pros::delay(1500);
}
#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/motors.h"
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
        
    chassis.changeAngularP(10);
    chassis.changeAngularI(0);
    chassis.changeAngularD(5);
	
	chassis.changeLatP(8);
	chassis.changeLatI(0);
	chassis.changeLatD(4);
}
void Robot::Init::initDriveCurves() {};

void Robot::Init::initAll() {
    initPIDs();
    Robot::Motors::LB_Motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
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
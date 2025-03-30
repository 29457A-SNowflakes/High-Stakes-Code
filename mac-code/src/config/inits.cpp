#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"
#include "usr/robot.h"
#include "usr/utils.h"
#include "pros/apix.h"
using namespace pros;
using namespace lemlib;
using namespace std;    
using namespace utils;
void Robot::Inits::initAll() {

    Robot::Sensors::LBRotation.reset_position();
    chassis.calibrate();
    initPIDs();
    TuningLogicLoop();
    delay(1000);

    Robot::Inits::colourSort();

}

void Robot::Inits::initPIDs() {

	float LatP = load_value("latP");
	float LatI = load_value("latI");
	float LatD = load_value("latD");

	float AngularP = load_value("angP");
	float AngularI = load_value("angI");
	float AngularD = load_value("angD");

	latSettings.kP = LatP;
    latSettings.kI = LatI;
    latSettings.kD = LatD;

    angSettings.kP = AngularP;
    angSettings.kI = AngularI;
    angSettings.kD = AngularD;
        
    chassis.changeAngularP(AngularP);
    chassis.changeAngularI(AngularI);
    chassis.changeAngularD(AngularD);
	
	chassis.changeLatP(LatP);
	chassis.changeLatI(LatI);
	chassis.changeLatD(LatD);
}

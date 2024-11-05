#include "lemlib/chassis/chassis.hpp"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "robodash/views/console.hpp"
#include "robodash/views/selector.hpp"
#include "usr/robot.h"
#include <cstdio>
#include <cstring>
#include <string>
#include "usr/utils.h"
using namespace utils;


const void Robot::Auton::Tuning::TuningLogicLoop() {
    AutonTuning.focus();
    std::cout << "here";
    float AngularP = angularController.kP;
    float AngularI = angularController.kI;
    float AngularD = angularController.kD;
    float LatP = latController.kP;
    float LatI = latController.kI;
    float LatD = latController.kD;
    float step = 0.1;
    int index = 0;
    int minIndex = 0;
    int maxIndex = 6;
    while (!master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
        pros::delay(20);
        AutonTuning.clear();

        latController.kP = LatP;
        latController.kI = LatI;
        latController.kD = LatD;

        angularController.kP = AngularP;
        angularController.kI = AngularI;
        angularController.kD = AngularD;
        
        chassis.changeAngularP(AngularP);
        chassis.changeAngularI(AngularI);
        chassis.changeAngularD(AngularD);

        chassis.changeLatP(LatP);
        chassis.changeLatI(LatI);
        chassis.changeLatD(LatD);

        AutonTuning.println("AUTON TUNING");
        AutonTuning.println("Press B to run Auton, R2 to quit, Arrows to navigate/change values, X to save values");

        AutonTuning.printf("Angular P: %f %s\n", AngularP, index==0 ? "<<" : "");
        AutonTuning.printf("Angular I: %f %s\n", AngularI, index==1 ? "<<" : "");
        AutonTuning.printf("Angular D: %f %s\n", AngularD, index==2 ? "<<" : "");
        AutonTuning.printf("Lateral P: %f %s\n", LatP, index==3 ? "<<" : "");
        AutonTuning.printf("Lateral I: %f %s\n", LatI, index==4 ? "<<" : "");
        AutonTuning.printf("Lateral D: %f %s\n", LatD, index==5 ? "<<" : "");
        AutonTuning.printf("Change step: %f %s\n", step, index==6 ? "<<" : "");

        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) index +=1;
        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) index -= 1;
        if (index > maxIndex) index = minIndex;
        if (index < minIndex) index = maxIndex;

        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            switch (index) {
                case 0:
                    AngularP -= step;
                    break;
                case 1:
                    AngularI -= step;
                    break;
                case 2:
                    AngularD -= step;
                    break;
                case 3:
                    LatP -= step;
                    break;
                case 4:
                    LatI -= step;
                    break;
                case 5:
                    LatD -= step;
                    break;
                case 6:
                    step -= 0.01;
                    break;
            }
        } else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            switch (index) {
                case 0:
                    AngularP += step;
                    break;
                case 1:
                    AngularI += step;
                    break;
                case 2:
                    AngularD += step;
                    break;
                case 3:
                    LatP += step;
                    break;
                case 4:
                    LatI += step;
                    break;
                case 5:
                    LatD += step;
                    break;
                case 6:
                    step += -0.01;
                    break;
            }
        }
        chassis.changeAngularP(AngularP);
        chassis.changeAngularI(AngularI);
        chassis.changeAngularD(AngularD);
        chassis.changeLatP(LatP);
        chassis.changeLatI(LatI);
        chassis.changeLatD(LatD);

        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
            master.clear_line(1);
            AutonTuning.printf("Running auton...");
            master.print(1, 1, "Running auton");
            Tuningselector.run_auton();
        }else {
            AutonTuning.printf("\n");
            master.clear_line(1);
            master.print(1, 1, "Done");
        }

        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
            AutonTuning.println("Saving");
            save_value("angP", AngularP);
            save_value("angI", AngularI);
            save_value("angD", AngularD);
            save_value("latP", LatP);
            save_value("latI", LatI);
            save_value("latD", LatD);
        }
    }
    Robot::Auton::autonSelectorMain.focus();
}
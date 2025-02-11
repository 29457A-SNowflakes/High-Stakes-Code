#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "usr/robot.h"


bool init;

void initialize() {
    bool hasChangedColour = false;
    init = true;
    Robot::Screen::printConsole.println(" -- Initialize --");
    Robot::Screen::printConsole.println("Initializing...");

    Robot::Inits::initAll();

    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println(" -- Initialize --");
    Robot::Motors::LBMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    pros::Task t ([=] {
        while (init) {
            if (Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
                break;
            }
            delay(2000);
            Robot::master.rumble(".");
        }
    });
    t.suspend();

    while (init && false) {
        delay(20);
        if (Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            hasChangedColour = true;
            if (Robot::playingColour == "BLUE") Robot::playingColour = "RED";
            else Robot::playingColour = "BLUE";
            Robot::master.print(1, 1, "COLOUR: %s", Robot::playingColour);
        }
    }
    
}

void autonomous() {

    Robot::Pneumatics::Mogo.retract();
    Robot::Screen::printConsole.focus();
    //Robot::Inits::colourSort(Robot::playingColour);
    init = false;
    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println(" -- Autonomous --");
    Robot::Screen::printConsole.println(" Running Auton...");

    Robot::Screen::autonSelector.run_auton();

    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println(" -- Autonomous --");
    
}

void opcontrol() {
    Robot::Screen::printConsole.focus();
    //Robot::Inits::colourSort(Robot::playingColour);
    init = false;
    pros::Controller* master = &Robot::master;
    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println("-- Driver Control --");
    
    
    bool waitingForLBReset = false;
    while (true) {
        
        int leftX = master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        int leftY = master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

        if (leftY >= 20) {

            Robot::chassis.arcade(leftY, leftX);

        } else {

            Robot::chassis.curvature(leftY, leftX);
            
        }

        if (master->get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {

            Robot::Pneumatics::Mogo.toggle();

        }
        if (master->get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
            Robot::Pneumatics::doinker.toggle();
        }
        if (master->get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {

            Robot::Pneumatics::intakeLift.toggle();

        }
        if (Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {

            autonomous();
             
        }
        if (master->get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !Robot::Motors::intakeAutoControl){

            Robot::Actions::setIntake(1);

        } else if (master->get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !Robot::Motors::intakeAutoControl) {

            Robot::Actions::setIntake(-1);

        } else Robot::Actions::setIntake(0);

        if (master->get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {

            LadyBrown::moveTo("LOAD");

        }
        if (master->get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            LadyBrown::manualMove(1);
        }else if (master->get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
            LadyBrown::manualMove(-1);
            waitingForLBReset = true;
        } else if (master->get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            LadyBrown::manualMove(-1);
            waitingForLBReset = false;
        } else {
            LadyBrown::manualMove(0);
            if (waitingForLBReset) {
                waitingForLBReset = false;
                pros::Task t ([=] {
                    delay(150);
                    Robot::Sensors::LBRotation.set_position(0);
                });
            }
        }

        Robot::Screen::printConsole.clear();
        Robot::Screen::printConsole.println("-- Driver Control --");
        Robot::Screen::printConsole.println("");
        Robot::Screen::printConsole.printf("%s\n", LadyBrown::currentState);


        delay(10);
    }
}


#include "main.h"
#include "pros/rtos.hpp"
#include "usr/robot.h"




void initialize() {
    Robot::Screen::printConsole.println(" -- Initialize --");
    Robot::Screen::printConsole.println("Initializing...");

    Robot::Inits::initAll();

    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println(" -- Initialize --");
}

void autonomous() {
    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println(" -- Autonomous --");
    Robot::Screen::printConsole.println(" Running Auton...");

    Robot::Screen::autonSelector.run_auton();

    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println(" -- Autonomous --");
    
}

void opcontrol() {
    pros::Controller* master = &Robot::master;
    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println("-- Driver Control --");
    
    bool waitingForLBReset = false;
    while (true) {
        
        int leftX = master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        int leftY = master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        Robot::chassis.curvature(leftY, leftX);

        if (master->get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {

            Robot::Pneumatics::Mogo.toggle();

        }
        if (master->get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

            Robot::Actions::setIntake(1);

        } else if (master->get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {

            Robot::Actions::setIntake(-1);

        } else Robot::Actions::setIntake(0);

        if (master->get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {

            LadyBrown::cycle();
            if (LadyBrown::currentState == "LOAD") Robot::Motors::LBMotor.set_brake_mode(E_MOTOR_BRAKE_HOLD);
            else Robot::Motors::LBMotor.set_brake_mode(E_MOTOR_BRAKE_COAST);

        }
        if (master->get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            LadyBrown::manualMove(1);
        }else if (master->get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
            LadyBrown::manualMove(-1);
            waitingForLBReset = true;
        } else {
            LadyBrown::manualMove(0);
            if (waitingForLBReset) {
                waitingForLBReset = false;
                pros::Task t ([=] {
                    delay(250);
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


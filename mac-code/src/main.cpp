#include "main.h"
#include "lemlib/pose.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "usr/robot.h"
#include "nlohmann/json.hpp"
#include "usr/autons.h"

bool init;

void initialize() {
    Robot::playingColour="BLUE";
    bool hasChangedColour = false;
    Robot::Inits::isSorting=false;
    init = true;
    Robot::Screen::printConsole.println(" -- Initialize --");
    Robot::Screen::printConsole.println("Initializing...");

    Robot::Inits::initAll();

    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println(" -- Initialize --");
    Robot::Motors::LBMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    //LadyBrown::rotSens->set_position(LadyBrown::states["LOAD"]);

    while (false && init && (!competition::is_field_control() && !Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT))) {
        delay(20);
        if (Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            hasChangedColour = true;
            if (Robot::playingColour == "BLUE") Robot::playingColour = "RED";
            else Robot::playingColour = "BLUE";
            Robot::master.print(1, 1, "COLOUR: %s ", Robot::playingColour);
        }
        if (Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
            Robot::chassis.calibrate();
            delay(1500);
        }
    }
    Robot::chassis.setPose(-58.5, -10.9, 270);
    //Robot::master.clear_line(1);


    pros::Task x ([=] {
        while (true) {
            delay(500);
            Pose p = Robot::chassis.getPose();
            nlohmann::json pkg {
                {"X", p.x},
                {"Y", p.y},
                {"T", p.theta},
            };
            std::cout << pkg.dump() << "\n";
        }
    });
    //Robot::Inits::TuningLogicLoop();
    //Robot::master.rumble(". - .");
}

void autonomous() {
    Robot::Inits::isSorting=true;
    int prevTimeout = LadyBrown::timeout;
    Robot::Pneumatics::Mogo.retract();
    Robot::Pneumatics::primaryDoinker.retract();
    Robot::Pneumatics::secondaryDoinker.retract();
    Robot::Screen::printConsole.focus();
    init = false;
    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println(" -- Autonomous --");
    Robot::Screen::printConsole.println(" Running Auton...");

    //Autons::Match::N_B();
    Robot::Screen::autonSelector.run_auton();

    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println(" -- Autonomous --");
    LadyBrown::timeout = prevTimeout;
    
}

void opcontrol() {
    Robot::Screen::printConsole.focus();
    //Robot::Inits::colourSort(Robot::playingColour);
    Robot::Sensors::LBRotation.set_position(0);
    init = false;
    pros::Controller* master = &Robot::master;
    Robot::Screen::printConsole.clear();
    Robot::Screen::printConsole.println("-- Driver Control --");
    
    bool waitingForLBReset = false;
    while (true) {
        
        int leftX = master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        int leftY = master->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

        if (leftY <= 15) {

            Robot::chassis.arcade(leftY, leftX);

        } else {

            Robot::chassis.curvature(leftY, leftX);
            
        }

        if (master->get_digital(pros::E_CONTROLLER_DIGITAL_B)) {

            Robot::Pneumatics::Mogo.retract();

        } else {
            Robot::Pneumatics::Mogo.extend();
        }
        if (master->get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
            Robot::Pneumatics::primaryDoinker.toggle();
        }
        if (master->get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {

            LadyBrown::moveTo("DESCORE");

        }
        if (false && Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {

            autonomous();
             
        }
        if (master->get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !Robot::Motors::intakeAutoControl){

            Robot::Actions::setIntake(1, Intake_Action::BOTH);

        } else if (master->get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !Robot::Motors::intakeAutoControl) {

            Robot::Actions::setIntake(-1, Intake_Action::BOTH);

        } else if (!Robot::Motors::intakeAutoControl) {
            Robot::Actions::setIntake(0, Intake_Action::BOTH);
        }

        if (master->get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {

            LadyBrown::moveTo("LOAD");

        }

        if(master->get_digital(E_CONTROLLER_DIGITAL_X)) {
            Robot::Inits::isSorting = false;
        } else {
            Robot::Inits::isSorting = true;
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


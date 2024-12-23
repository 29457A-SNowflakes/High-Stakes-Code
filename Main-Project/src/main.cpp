#include "main.h"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/rtos.hpp"
#include "usr/robot.h"
#include "usr/utils.h"
#include <charconv>
#include <cstdio>
using namespace utils;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
*/

#include "nlohmann/json.hpp"
#include "pros/apix.h"
void initialize() {
	/*
	pros::c::serctl(SERCTL_DISABLE_COBS, nullptr);
	pros::Task task ([=] {
		while (true) {
			nlohmann::json package = {
				{"odom/x", Robot::chassis.getPose().x},
				{"odom/y", Robot::chassis.getPose().y},
				{"odom/theta", Robot::chassis.getPose().theta},
			};
			std::cout << package.dump() << "\n";
			pros::delay(10);
		}
	});
	*/
	Robot::Init::initAll();
	Robot::Motors::LB_Motor.tare_position();
	//Robot::Auton::Tuning::TuningLogicLoop();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	Robot::Pneumatics::intakeLifter.retract();
	Robot::Pneumatics::doinker.retract();
	Robot::Auton::autonSelectorMain.run_auton();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

bool LBisOverLimit () {
	float ratio = (float)12/(float)72;
	return Robot::Motors::LB_Motor.get_position()*ratio >= Robot::maxLB;
}
void opcontrol() {
	Robot::Pneumatics::intakeLifter.set_value(false);
	while (true) {
		pros::delay(20);
		int leftX = Robot::master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
		int leftY = Robot::master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		Robot::chassis.curvature(leftY, leftX);

		if (Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
			Robot::Pneumatics::mogoMech.toggle();
		}
		if (Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			Robot::Motors::Intake.move(-127);
		} else if (Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			Robot::Motors::Intake.move(127);
		} else Robot::Motors::Intake.move(0);

		if (Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
			Robot::Pneumatics::intakeLifter.toggle();
		}

		if (Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
			Robot::Pneumatics::doinker.toggle();
		}

		if (
			Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) &&
			Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP) &&
			!pros::competition::is_connected() && false
		){
			autonomous();
		}
		if (Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !LBisOverLimit()) {
			Robot::Motors::LB_Motor.move_velocity(200);
		}
		else if (Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !Robot::Sensors::LB_Bumper.get_value()) {
			Robot::Motors::LB_Motor.move_velocity(-200);
		} else if (!Robot::Actions::LB::isRunningMacro) {
			Robot::Motors::LB_Motor.move_velocity(0);
		}

		if (Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN) && !Robot::Actions::LB::isRunningMacro) {
			Robot::Actions::LB::runMacro(LB_Macro (REST));
		}
		if (Robot::master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y) && !Robot::Actions::LB::isRunningMacro) {
			Robot::Actions::LB::runMacro(LB_Macro (LOAD));
		}

		if ((!Robot::Sensors::LB_Bumper.get_value() && !Robot::Actions::LB::isRunningMacro) || Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
			Robot::Motors::LB_Motor.tare_position();
		}
	}
}
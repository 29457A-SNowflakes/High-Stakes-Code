#include "lemlib/pose.hpp"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "usr/robot.h"
#include <algorithm>
#include <cstdio>
#include <string>

using namespace pros;
using namespace lemlib;

void Robot::Actions::setMogoFor(bool extended, float time, bool async) {
    if (async) {
        Task task ([=] {setMogoFor(extended, time, false);});
        delay(10);
        return;
    }
    Pneumatics::mogoMech.set_value(extended);
    delay(time);
    Pneumatics::mogoMech.toggle();
}
void Robot::Actions::setIntake(int direction) {
    Motors::Intake.move_velocity(600 * direction);
}
void Robot::Actions::runIntakeFor(int direction, float time, bool async) {
    if (async) {
        Task t ([=] {runIntakeFor(direction, time, false);});
        delay(10);
        return;
    }
    setIntake(direction);
    delay(time);
    setIntake(0);
}
void Robot::Actions::setIntakeLifterFor(bool extended, float time, bool async){
    if (async) {
        Task t ([=] {setIntakeLifterFor(extended, time, false);});
        delay(10);
        return;
    }
    Pneumatics::intakeLifter.set_value(extended);
    delay(time);
    Pneumatics::intakeLifter.toggle();
}
void Robot::Actions::jiggle(float time) {
    float start = millis();
    while (millis()-start < time) {
        Pose jigglePoint1 = Pose {chassis.getPose().x-(float)cos(chassis.getPose(true).theta)*2, chassis.getPose().y-(float)sin(chassis.getPose(true).theta)*2};
        Pose jigglePoint2 = Pose {chassis.getPose().x+(float)cos(chassis.getPose(true).theta)*2, chassis.getPose().y+(float)sin(chassis.getPose(true).theta)*2};
        Pose start = chassis.getPose();
        Robot::chassis.moveToPoint(jigglePoint1.x, jigglePoint1.y, 50, {.minSpeed=100});
        Robot::chassis.moveToPoint(jigglePoint2.x, jigglePoint2.y, 50, {.minSpeed=100});
        Robot::chassis.moveToPoint(start.x, start.y, 50, {.minSpeed=100});
        Robot::chassis.waitUntilDone();
        delay(200);
    }
}




void Robot::Actions::LB::runMacro(LB_Macro macro) {
    if (macro.async) {
        pros::Task t ([=] {runMacro(LB_Macro(macro.state, false, macro.timeout));});
        delay(10);
        return;
    }
    isRunningMacro = true;
    float t = millis();
    float ratio = (float)12/(float)72;
    float desired = 0;
    switch (macro.state) {
        case Types::REST:
            desired = 0;
            break;
        case Types::LOAD:
            desired = 13;
            break;
        case Types::SCORE:
            desired = 100;
            break;
        default:
            desired = 0;
            break;
    }
    pros::Motor* LB = &Robot::Motors::LB_Motor;
    lemlib::PID* pid = &Robot::Auton::LB_PID;
    
    if (macro.state == REST) {
        while (!Robot::Sensors::LB_Bumper.get_value()) {
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
                break;
            }
            LB->move_velocity(-175);
            delay(20);
        }
        LB->move_velocity(0);
        LB->brake();
        isRunningMacro = false;
        return;
    }
    float error = desired - (LB->get_position() * ratio);
    while (error > 3 && millis()-t < macro.timeout){

        delay(15);
        error = desired - (LB->get_position() * ratio);
        float cmd = pid->update(error);
            cmd = std::clamp<float>(cmd, -33, 33);
        LB->move_velocity(cmd/ratio);
    }
    LB->move_velocity(0);
    LB->brake();
    isRunningMacro = false;
}
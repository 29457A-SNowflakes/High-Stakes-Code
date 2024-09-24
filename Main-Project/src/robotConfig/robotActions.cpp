#include "lemlib/pose.hpp"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/rtos.hpp"
#include "usr/robot.h"

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
void Robot::Actions::setIntake(int direction, IntakeActionType stage) {
    int volts = 12000 * direction;
    if (stage==IntakeActionType::FIRST || stage == IntakeActionType::BOTH) {
        Motors::Intake1st.move_voltage(volts);
    }
    if (stage==IntakeActionType::SECOND || stage == IntakeActionType::BOTH) {
        Motors::Intake2nd.move_voltage(volts);
    }
}
void Robot::Actions::runIntakeFor(int direction, IntakeActionType stage, float time, bool async) {
    if (async) {
        Task t ([=] {runIntakeFor(direction, stage, time, false);});
        delay(10);
        return;
    }
    setIntake(direction, stage);
    delay(time);
    setIntake(0, stage);
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

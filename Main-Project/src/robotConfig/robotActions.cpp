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
void Robot::Actions::setIntake(int direction) {
    int move = 127 * direction;
    Motors::Intake.move_voltage(move);
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

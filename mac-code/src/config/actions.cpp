#include "usr/robot.h"


void Robot::Actions::setIntake(int dir) {
    Robot::Motors::intakeMotor.move_voltage(dir * 120000);
}

void Robot::Actions::setIntakeFor(int dir, int time, bool async) {
    if (async) {
        pros::Task([=] {setIntakeFor(dir, time);});
        delay(10);
    }
    setIntake(dir);
    delay(time);
    setIntake(0);
}
void Robot::Actions::setMogoFor(bool extended, int time, bool async) {
    if (async) {
        pros::Task([=] {setMogoFor(extended, time);});
        delay(10);
    }
    Robot::Pneumatics::Mogo.set_value(extended);
    delay(time);
    Robot::Pneumatics::Mogo.set_value(!extended);
}


void Robot::Actions::FlingRing(bool async) {
    if (async) {
        pros::Task t ([=] {
            FlingRing(false);
        });
        delay(10); return;
    }
    Motors::intakeAutoControl = true;
    Robot::Actions::setIntakeFor(-1, 50, false);
    Motors::intakeAutoControl = false;
}
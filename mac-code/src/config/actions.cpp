#include "usr/robot.h"


void Robot::Actions::setIntake(int dir, Intake_Action type) {
    if (type == Intake_Action::FIRST || type == Intake_Action::BOTH) {
        Robot::Motors::preRollerMotor.move_voltage(12000 * dir);
    }
    if (type == Intake_Action::SECOND || type == Intake_Action::BOTH) {
        Robot::Motors::hooksMotor.move_voltage(12000 * dir);
    }
}

void Robot::Actions::setIntakeFor(int dir, Intake_Action type, int time, bool async) {
    if (async) {
        pros::Task([=] {setIntakeFor(dir, type, time);});
        delay(10);
    }
    setIntake(dir, type);
    delay(time);
    setIntake(0, type);
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


void Robot::Actions::FlingRing(bool async, float for_) {
    if (async) {
        pros::Task t ([=] {
            FlingRing(false);
        });
        delay(10); return;
    }
    Motors::intakeAutoControl = true;
    Robot::Actions::setIntakeFor(-1, Intake_Action::SECOND, for_, false);
    Motors::intakeAutoControl = false;
}
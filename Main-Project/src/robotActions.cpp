#include "main.h"
#include "lemlib/api.hpp"
#include "pros/rtos.hpp"
#include "usr/robot.h"

using namespace pros;
using namespace lemlib;

void Robot::Actions::toggleMogo() {
    Pneumatics::mogoExtended = !Pneumatics::mogoExtended;
    Pneumatics::mogo.set_value(Pneumatics::mogoExtended);
}
void Robot::Actions::setMogo (bool extended) {
    Pneumatics::mogoExtended = extended;
    Pneumatics::mogo.set_value(extended);
}
void Robot::Actions::setMogoFor(bool extended, float time, bool async) {
    if (async) {
        Task task ([=] {setMogoFor(extended, time, false);});
        delay(10);
        return;
    }
    setMogo(extended);
    delay(time);
    setMogo(!extended);
}
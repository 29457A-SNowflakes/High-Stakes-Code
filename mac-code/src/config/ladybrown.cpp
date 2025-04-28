#include "pros/misc.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "usr/robot.h"
#include "usr/utils.h"
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <string>

using namespace pros;
using namespace lemlib;
using namespace std;



void LadyBrown::moveToPoint(float point, bool toRest) {
    hasFinished = false;
    float pos = rotSens->get_position() * gearRatio;
    float error = point - pos;

    float startTime = pros::millis();
    float elapsed = pros::millis()-startTime;
    //std::cout << exitError << "\n";

    while (elapsed < timeout && !cancel && abs(error) > exitError) {
       // std::cout << error << "\n";

        elapsed = millis()-startTime;

        pos = rotSens->get_position() * gearRatio;
        error = point-pos;

        float cmd = lbPID.update(error);
        cmd = clamp<float>(cmd, -12000, 12000);

        motor->move_voltage(cmd);


        delay(10);
    }

    lbPID.reset();
    hasFinished = true;
}
void LadyBrown::manualMove(int dir) {
    if (dir == 0) {
        manualControl = false;
        cancel = false;
        if (hasFinished) {
            motor->move(0);
        }
        return;
    }
    else if (!manualControl) {
        manualControl = true;
        cancelMotion();
        if (dir == 1) {
            //Robot::Actions::FlingRing(true, 5, 20);
        }
    }
    
    motor->move(127 * dir);
}

void LadyBrown::cancelMotion() {
    cancel = true;
    waitForFinish();
    cancel = false;
}
void LadyBrown::waitForFinish() {
    while (!hasFinished) {
        pros::delay(15);
    }
}
void LadyBrown::moveTo(const std::string action, bool async) {
    // Check if the action exists in the states map
    if (states.find(action) == states.end()) {
        std::cerr << "Invalid action: " << action << "\n";
        return;
    }

    // Update current state
    currentState = action;
    currentStateNum = utils::getIndex(stateList, currentState);
    float point = states[action];
    std::cout << "Current State: " << currentState << ", Point: " << point << "\n";

   cancelMotion();

    // Handle async or synchronous operation
    if (async) {
        Task t ([=] {
            moveToPoint(point, currentState == "REST");
            pros::delay(10);
        });
    } else {
        moveToPoint(point, currentState == "REST");
    }
}
void LadyBrown::cycle() {
    int newState = ++currentStateNum;
    if (newState == stateList.size()) newState=0;
    string state = stateList[newState];
    Robot::master.print(0, 0, "STATE: %s", state);
    moveTo(stateList[newState]);
}
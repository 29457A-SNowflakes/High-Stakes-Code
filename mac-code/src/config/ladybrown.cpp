#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "usr/robot.h"
#include "usr/utils.h"
#include <algorithm>
#include <map>
#include <queue>
#include <string>

using namespace pros;
using namespace lemlib;
using namespace std;

//* Deprecated
/*
void LadyBrown::LBLoop() {
    currentState = "REST";
    bool isOut;
    bool forceHold = false;
    float holdTarget = 0;
    float startedAction = millis();
    Task t ([=] {
        while (true) {
            delay(100);
            //std::cout << prevState << "\n";
        }
    });
    while (true) {
        delay (20);

        float target = States[currentState] * 100;
        float currentPoint = RotSens->get_position() * ratio;
        float error = target-currentPoint;

        //std::cout << hasReached << "\n";

        if (prevState != currentState) {
            std::cout << "HERE";
            startedAction = millis();
            hasReached = false;
        }
        prevState = currentState;
        float elapsed = 0; //millis()-startedAction;

        if (currentPoint >= maxRot*100) {

            target = (maxRot-acceptableError) * 100;
            forceHold = true;

        } else if (currentPoint <= minRot*100 && false) {

            target = (minRot+acceptableError) * 100;
            forceHold = true;

        } else {
            target = States[currentState] * 100;
            forceHold = false;
            isOut = false;
        }

        

        if (Robot::master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && currentPoint < maxRot*100 && hasReached) {
            LBMotor->move(127);
            holdTarget = currentPoint;
            continue;
        } else {
            LBMotor->move(0);
        }
        if (error <= acceptableError * 100) {
            if (!queuedActions.empty()) {
                currentState = queuedActions.front(); queuedActions.pop();
                hasReached = false;
            } else {
                hasReached = true;
                holdTarget = currentPoint;
            }
            continue;
        }

        //std::cout << currentState << "\n";

        if ((!hasReached && elapsed <= timeout) || hold || forceHold) {
            if (!hasReached || forceHold) {
                error = target-currentPoint;
                std::cout << error << "\n";
            } else if (hold) {
                error = holdTarget-currentPoint;
            }

            float cmd = pid.update(error) / 3;
            cmd = std::clamp<float>(cmd, -200, 200);
            LBMotor->move_velocity(cmd);
        }
        else LBMotor->move(0);
        

    }
}
*/

void LadyBrown::moveToPoint(float point, bool toRest) {
    hasFinished = false;
    float targ = point;
    float pos = rotSens->get_position() * 0.25;
    float error = targ - pos;

    float startTime = pros::millis();
    float elapsed = pros::millis()-startTime;
    if (toRest && false) {
        elapsed = pros::millis()-startTime;
        Robot::master.rumble("-");
        while (limit->get_value()  && !cancel && !manualControl && elapsed < timeout) {
            delay(20);
            motor->move(-127);
        }
        motor->move(0);
        rotSens->reset_position();
        hasFinished = true;
        return;
    }
    while (std::abs(error) > exitError && !manualControl && !cancel && elapsed < timeout) {
        elapsed = pros::millis()-startTime;
        pos = rotSens->get_position() * 0.75;
        error = targ-pos;
        float cmd = P_Gain * error;
        cmd = std::clamp<float>(cmd, -12000, 12000);
        motor->move_voltage(cmd);
        delay (20);
    }
    motor->move(0);
    hasFinished = true;
}
void LadyBrown::manualMove(int dir) {
    if (dir == 0) {
        manualControl = false;
        if (hasFinished) {
            motor->move(0);
            if (limit->get_value()) {
                currentState = "REST";
                rotSens->reset_position();
            }
        }
        return;
    }
    else if (!manualControl) {
        manualControl = true;
        while (!hasFinished) pros::delay(15);
        Robot::Actions::FlingRing(true);
    }
    
    motor->move(127 * dir);
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

    cancel = true;
    waitForFinish();
    cancel = false;

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
    std::cout << "here\n";
    int newState = ++currentStateNum;
    if (newState == stateList.size()) newState=0;
    string state = stateList[newState];
    Robot::master.print(0, 0, "STATE: %s", state);
    moveTo(stateList[newState]);
}
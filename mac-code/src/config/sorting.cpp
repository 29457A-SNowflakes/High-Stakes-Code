#include "pros/optical.hpp"
#include "usr/robot.h"
#include <cmath>

using namespace pros;

bool isColour(float colour, float seeing, float maxError=10) {
    float error = std::abs(colour-seeing);
    if (error <= maxError) return true;
    else return false;
}
int timeTillFling = 100;
int cooldown = 500;
void Robot::Inits::colourSort(string colour) {
    if (isSorting) return;
    isSorting = true;
    Optical* sens = &Robot::Sensors::colourSens;
    sens->set_led_pwm(100);

    float colourToSort;
    if (playingColour == "BLUE") colourToSort = 0;
    else if (playingColour == "RED") colourToSort = 200;

    pros::Task task ([=] {
        int cooldownStart;
        while (true) {
            delay(20);
            float seeing = sens->get_hue();
            bool shouldFling = isColour(colourToSort, seeing);
            if (shouldFling && millis()-cooldownStart >= cooldownStart) {
                delay(timeTillFling);
                Actions::FlingRing(false);
                shouldFling = false;
                cooldownStart = millis();
            }
        }
    });
}
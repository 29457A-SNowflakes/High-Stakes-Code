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
void Robot::Inits::colourSort() {
    if (isSorting) return;
    isSorting = true;
    Optical* sens = &Robot::Sensors::colourSens;
    sens->set_led_pwm(100);


    pros::Task task ([=] {
        float colourToSort;
        int cooldownStart;
        while (true) {
            if (Robot::playingColour == "BLUE") colourToSort = 0;
            else if (Robot::playingColour == "RED") colourToSort = 200;

            delay(20);
            float seeing = sens->get_hue();
            bool shouldFling = isColour(colourToSort, seeing);
            if (shouldFling && sens->get_proximity() <= 70) {
                delay(timeTillFling);
                Actions::FlingRing(false, 300);
                shouldFling = false;
                cooldownStart = millis();
            }
        }
    });
}
#include "pros/optical.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "usr/robot.h"
#include <cmath>

using namespace pros;

bool isColour(float colour, float seeing, float maxError=5) {
    float error = std::abs(colour-seeing);
    if (error <= maxError) return true;
    else return false;
}
int timeTillFling = 85;
int cooldown = 500;
void Robot::Inits::colourSort() {
    Optical* sens = &Robot::Sensors::colourSens;


    sens->set_integration_time(5);
    pros::Task task ([=] {
        float colourToSort;
        int cooldownStart;
        while (true) {
            sens->set_led_pwm(100);

            if (Robot::playingColour == "BLUE") colourToSort = 8;
            else if (Robot::playingColour == "RED") colourToSort = 225;

            delay(6);
            float seeing = sens->get_hue();
            bool shouldFling = isColour(colourToSort, seeing);
            if (shouldFling && sens->get_proximity() >= 200 && isSorting && (millis()-cooldownStart) >= cooldown) {
                std::cout << sens->get_proximity() << "\n";
                delay(timeTillFling);
                Actions::FlingRing(false, 150);
                shouldFling = false;
                cooldownStart = millis();
                Robot::master.rumble(". .");
            }
        }
    });
}
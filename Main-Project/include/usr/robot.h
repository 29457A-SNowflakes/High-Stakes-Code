#include "api.h"
#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "robodash/api.h"
#include "robodash/core.h"
#include "robodash/views/console.hpp"
#include "robodash/views/selector.hpp"




class Robot {
    public:
        class Auton {
            public:
                class Tuning {
                    public:
                        static rd::Console AutonTuning;
                        static const void TuningLogicLoop();
                        static lemlib::ControllerSettings latController;
                        static lemlib::ControllerSettings angularController;

                };
                static rd::Selector selector;
            // ...
        };
        class Motors {
            public:
                static const lemlib::Drivetrain drivetrain;
        };
        class Sensors {
            public:
                static const lemlib::OdomSensors sensors;
        };
        class Pneumatics {};
        class Actions {};
        class Logging {};
        static pros::Controller master;
        static lemlib::Chassis chassis;
};
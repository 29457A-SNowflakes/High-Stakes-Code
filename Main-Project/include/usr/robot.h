// includes ---
#include "api.h"
#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "lemlib/pid.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"
#include "robodash/api.h"
#include "robodash/core.h"
#include "robodash/views/console.hpp"
#include "robodash/views/selector.hpp"
// ---


namespace Types {
    // LB states
    enum LBStates {
        REST=0,
        LOAD =30,
        SCORE=100,
    };
    class LB_Macro {
        public:
            LBStates state;
            bool async;
            int timeout;
            float maxSpeed;
            float minSpeed;
            LB_Macro(LBStates toState, bool async_=true, float maxSpeed_ =200, float minSpeed_=0, int timeout_=1200){
                state = toState;
                async = async_;
                timeout = timeout_;
            }
    };
};
using namespace Types;

class Robot { 
    public:
        class Auton { // contains autons
            public:
                class Tuning {  // contains functions to tune autonomous (PID) values
                    public:
                        static rd::Console AutonTuning;
                        static const void TuningLogicLoop();
                        static lemlib::ControllerSettings latController;
                        static lemlib::ControllerSettings angularController;

                        //TODO (non-urgent)
                        static const void DriveCurveTuning();
                        static lemlib::ExpoDriveCurve driveCurveLateral;
                        static lemlib::ExpoDriveCurve driveCurveAngular;
                        //--

                        static rd::Selector Tuningselector; // selector for test autons

                };
                static lemlib::PID LB_PID;
            static rd::Selector autonSelectorMain; // selector for game autons
        };
        class Motors { // contains all motor-based variables
            public:
                static pros::Task intakeTask;
                static const lemlib::Drivetrain drivetrain;
                static pros::Motor Intake;
                static pros::Motor LB_Motor;
            protected:
                static pros::MotorGroup leftMotors;
                static pros::MotorGroup rightMotors;
        };
        class Sensors { // class for sensors
            public:
                static lemlib::OdomSensors sensors;
                static pros::IMU imu;
                static pros::adi::Button LB_Bumper;
        };
        class Pneumatics { // class for pneumatics
            public:
                static pros::adi::Pneumatics mogoMech;
                static pros::adi::Pneumatics intakeLifter;// not yet implemented
                static pros::adi::Pneumatics doinker;   // not yet implemented
        };
        class Actions { // contains macros/actions for robot
            public:
                static void setMogoFor (bool extended, float time, bool async=true);

                static void setIntake(int direction);
                static void runIntakeFor(int direction, float time, bool async = true);


                static void setIntakeLifterFor(bool extended, float time, bool async=true);

                static void jiggle(float time); // jiggles robot (may be useful?)

                class LB {
                    public:
                        static void runMacro(LB_Macro macro);
                        static void queueMacro(LB_Macro macro);
                        static bool isRunningMacro;
                };

        };
        class Init { // intializer functions
            public:
                static void initAll();
            protected:
                static void initPIDs();
                static void initDriveCurves();
        };
        class Logging {/* WIP */};
        static pros::Controller master; // controller
        static lemlib::Chassis chassis; // main chassis
        static const float maxLB;
};
// includes ---
#include "api.h"
#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
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
    // specifies how intake is actuated
    enum IntakeActionType {
        BOTH,
        FIRST,
        SECOND
    };
}
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
            static rd::Selector autonSelectorMain; // selector for game autons
        };
        class Motors { // contains all motor-based variables
            public:
                static pros::Task intakeTask;
                static const lemlib::Drivetrain drivetrain;
                static pros::Motor Intake1st;
                static pros::Motor Intake2nd;
                static pros::MotorGroup fullIntake;
                static bool DTDirection; // direction of 'forward' for drivetrain (not implemented)
            protected:
                static pros::MotorGroup leftMotors;
                static pros::MotorGroup rightMotors;
        };
        class Sensors { // class for sensors
            public:
                static lemlib::OdomSensors sensors;
                static pros::IMU imu;
            protected:
                static lemlib::TrackingWheel verticalTracking;
                static lemlib::TrackingWheel horizontalTracking;
        };
        class Pneumatics { // class for pneumatics
            public:
                static pros::adi::Pneumatics mogoMech;
                static pros::adi::Pneumatics intakeLifter;
                static pros::adi::Pneumatics doinker;   
        };
        class Actions { // contains macros/actions for robot
            public:
                static void setMogoFor (bool extended, float time, bool async=true);

                static void setIntake(int direction, IntakeActionType stage);
                static void runIntakeFor(int direction, IntakeActionType stage, float time, bool async = true);


                static void setIntakeLifterFor(bool extended, float time, bool async=true);

                static void jiggle(float time); // jiggles robot (may be useful?)

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
};
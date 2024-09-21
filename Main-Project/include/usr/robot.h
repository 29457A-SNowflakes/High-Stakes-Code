#include "api.h"
#include "lemlib/api.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "robodash/api.h"
#include "robodash/core.h"
#include "robodash/views/console.hpp"
#include "robodash/views/selector.hpp"



namespace Types {
    enum IntakeActionType {
        BOTH,
        FIRST,
        SECOND
    };
}
using namespace Types;
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

                        //TODO (non-urgent)
                        static const void DriveCurveTuning();
                        static lemlib::ExpoDriveCurve driveCurveLateral;
                        static lemlib::ExpoDriveCurve driveCurveAngular;
                        //--

                    static rd::Selector Tuningselector;
                };
            // ...
        };
        class Motors {
            public:
                static const lemlib::Drivetrain drivetrain;
                static pros::Motor Intake1st;
                static pros::Motor Intake2nd;
                static pros::MotorGroup fullIntake;
                static bool DTDirection;
            protected:
                static pros::MotorGroup leftMotors;
                static pros::MotorGroup rightMotors;
        };
        class Sensors {
            public:
                static lemlib::OdomSensors sensors;
                static pros::IMU imu;
            protected:
                static lemlib::TrackingWheel verticalTracking;
                static lemlib::TrackingWheel horizontalTracking;
        };
        class Pneumatics {
            public:
                static pros::adi::Pneumatics mogoMech;
                static pros::adi::Pneumatics intakeLifter;
                static pros::adi::Pneumatics doinker;   
        };
        class Actions {
            public:
                static void setMogoFor (bool extended, float time, bool async=true);

                static void setIntake(int direction, IntakeActionType stage);
                static void runIntakeFor(int direction, IntakeActionType stage, float time, bool async = true);


                static void setIntakeLifterFor(bool extended, float time, bool async=true);

                static void jiggle(float time);

        };
        class Init {
            public:
                static void initAll();
            protected:
                static void initPIDs();
                static void initDriveCurves();
        };
        class Logging {/* WIP */};
        static pros::Controller master;
        static lemlib::Chassis chassis;
};
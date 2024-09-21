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

                    static rd::Selector Tuningselector;
                };
            // ...
        };
        class Motors {
            public:
                static const lemlib::Drivetrain drivetrain;
                static const pros::Motor Intake1st;
                static const pros::Motor Intake2nd;
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
                static pros::adi::DigitalOut mogo;
                static bool mogoExtended;
                static pros::adi::DigitalOut intakeElevator; //TODO implement
                static bool intakeElevatorExtended; //TODO implement
        };
        class Actions {
            public:
                static void toggleMogo();
                static void setMogo(bool extended);
                static void setMogoFor (bool extended, float time, bool async=false);

                static void setIntake(int direction, IntakeActionType stage); //TODO implement
                static void runIntakeFor(int direction, IntakeActionType stage, float time, bool async = false); //TODO implement

                static void toggleIntakeElevator(); //TODO implement
                static void setIntakeElevator(bool extended); //TODO implement
                static void setIntakeElevatorFor(bool extended, float time, bool async=false); //TODO implement

        };
        class Init {
            public:
                static void initAll();
            protected:
                static void initPIDs();
                static void initDriveCurves();
        };
        class Logging {};
        static pros::Controller master;
        static lemlib::Chassis chassis;
};
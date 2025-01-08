#include "api.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "robodash/api.h"
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace pros;
using namespace lemlib;
using namespace std;


class LadyBrown {
    public:
        static void moveTo (string action, bool async=true);
        static void cycle ();
        static void manualMove(int dir);

        static string currentState;
        static std::map<string, float> states;
        static vector<string> stateList;

        static const float minPos;
        static const float maxPos;
        static const float exitError;

        static const float P_Gain;

        static const float timeout;

        static Rotation* rotSens;
        static Motor* motor;

    protected:
        static bool manualControl;
        static bool cancel;
        static bool hasFinished;
        static int currentStateNum;
        static void moveToPoint(float point);
        static void waitForFinish();


};

class Robot {
    public: 
        static Controller master;

        static Chassis chassis;

        static ControllerSettings latSettings;
        static ControllerSettings angSettings;
        class Screen {
            public:
                static rd::Selector autonSelector;
                static rd::Console printConsole;
        };

        class Actions {
            public:
                static void setIntake (int dir);
                static void setIntakeFor (int dir, int time, bool async=true);

                static void setMogoFor (bool extended, int time, bool async=true);
        };

        class Sensors {
            public:
                static OdomSensors sensors;
                static Imu imu;
                static Rotation LBRotation;
        };

        class Pneumatics {
            public:
                static adi::Pneumatics Mogo;
                static adi::Pneumatics doinker;
                // static adi::Pneumatics intakeLift; ??
        };

        class Motors {
            public:
                static Drivetrain dt;
                static Motor intakeMotor;
                static Motor LBMotor;
        };
        
        class Inits {
            public: 
                static void initAll();
            protected:
                static void initPIDs();
        };
};
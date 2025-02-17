#include "api.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "robodash/api.h"
#include "robodash/views/console.hpp"
#include "robodash/views/selector.hpp"
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

        static float timeout;

        static const float gearRatio;

        static Rotation* rotSens;
        static adi::DigitalIn* limit;
        static Motor* motor;

        static void moveToPoint(float point, bool toRest=false);

        static void waitForFinish();
        
    protected:
        static bool manualControl;
        static bool cancel;
        static bool hasFinished;
        static int currentStateNum;


};
enum Intake_Action {
    FIRST,
    SECOND,
    BOTH
};
class Robot {
    public: 
        static Controller master;

        static Chassis chassis;

        static ControllerSettings latSettings;
        static ControllerSettings angSettings;

        static string playingColour;

        class Screen {
            public:
                static rd::Selector autonSelector;
                static rd::Console printConsole;
                static rd::Console Tuning;
                static rd::Selector TuningSelector;
        };

        class Actions {
            public:
                static int timesSorted;
                static void setIntake (int dir, Intake_Action type);
                static void setIntakeFor (int dir, Intake_Action type, int time, bool async=true);

                static void FlingRing(bool async, float for_=100);

                static void setMogoFor (bool extended, int time, bool async=true);
        };

        class Sensors {
            public:
                static adi::DigitalIn LBLimiter;
                static OdomSensors sensors;
                static Imu imu;
                static Rotation LBRotation;
                static Optical colourSens;
        };

        class Pneumatics {
            public:
                static adi::Pneumatics Mogo;
                static adi::Pneumatics doinker;
                static adi::Pneumatics intakeLift;
        };

        class Motors {
            public:
                static Drivetrain dt;
                static Motor hooksMotor;
                static Motor preRollerMotor;
                static Motor LBMotor;
                static bool intakeAutoControl;
        };
        
        class Inits {
            public: 
                static void initAll();
                static void colourSort();
                static void TuningLogicLoop();
                static bool isSorting;
            protected:
                static void initPIDs();
        };
};
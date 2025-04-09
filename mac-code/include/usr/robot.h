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
        static void moveTo (string action, bool async=true); // Moves to a macor position, taking name as input
        static void cycle (); // cycles between available macros
        static void manualMove(int dir); // allows for overriding manual control

        static string currentState; // the current state of the wall stake
        static std::map<string, float> states; // the dictionary of states - contains name and rotational position of each
        static vector<string> stateList; // the iterable list of states used by cycle()

        static const float minPos; // minimum position allowed
        static const float maxPos; // maximum position allowed
        static const float exitError; // the maximum error the P controller will exit on

        static PID lbPID; // The lady brown PID

        static float timeout; // maximum time allowed for P controller

        static const float gearRatio; // gear ratio on rotation sensor

        static Rotation* rotSens; // Pointer to rotation sensor
        static Motor* motor; // pointer to the LB motor

        static void moveToPoint(float point, bool toRest=false); // generic function to move to rotational position (centidegrees)

        static void waitForFinish(); // wait for P controller to finish

        static void cancelMotion();
        
    protected:
        static bool manualControl; // is under overriding control
        static bool cancel; // should action be canceled
        static bool hasFinished; // has controller finished
        static int currentStateNum; // the index of the current state, in 'stateList'


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

                static void FlingRing(bool async, float for_=100, float speed=127);

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
                static adi::Pneumatics primaryDoinker;
                static adi::Pneumatics secondaryDoinker;
            protected:
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
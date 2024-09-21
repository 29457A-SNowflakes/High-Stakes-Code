#include "api.h"
#include "lemlib/api.hpp"
#include "nlohmann/json.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include <vector>


//* WIP DO NOT USE
namespace Logging {

    class MotorLogger {

        public:
            MotorLogger (pros::Motor* Motor, int loggingFrequency=-1, bool startImmediatly=true);
            MotorLogger (pros::MotorGroup* MotorGroup, int loggingFrequency=-1, bool startImmediatly=true);

            void changeLoggingFrequency(int newFrequency);
            void startLogging();
            void stopLogging();

            bool logTemp;
            int tempFreq;

            bool logPower;
            int PowerFreq;

            bool logVel;
            int velFreq;

            bool logTargPos;
            int targPosFreq;
            
            bool logPos;
            bool posFreq;
            
        protected:
            pros::Motor* motor;
            pros::MotorGroup* motorGroup;
            pros::Task LoggingTask;
            int globalloggingFreq;

            std::vector<nlohmann::json> getJsons();

    };

}
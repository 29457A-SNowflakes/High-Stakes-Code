#include "api.h"
#include "lemlib/api.hpp"

// TODO: Overhall autons -- new bot
namespace Autons {
    class Testers {
        public:
            static void forward24();
            static void forward72();
            static void turn90();
            static void swing90();
            static void boomerang_24_24_90();
            static void circle();
    };
    void supportTouchLadder();
    void support();
    void rush();
    void supportBlue();
    void supportTouchLadderBlue();
    void rushBlue();
    class Skills {
        public:
            static void skillsRun();
    };
    // TODO: more?
}
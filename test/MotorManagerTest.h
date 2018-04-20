#ifndef MARKOS_MAIN_MOTORMANAGERTEST_H
#define MARKOS_MAIN_MOTORMANAGERTEST_H


#include <gtest/gtest.h>
#include "MotorManager.h"
#include "MockMotor.h"
#include "MockThrottleControl.h"

using namespace testing;
using namespace mark2;

class MotorManagerTest : public testing::Test {
protected:
    MockThrottleControl mockThrottleControl1;
    MockThrottleControl mockThrottleControl2;
    MockThrottleControl mockThrottleControl3;
    MockThrottleControl mockThrottleControl4;

    GenericMotor<MockThrottleControl> motor1{mockThrottleControl1};
    GenericMotor<MockThrottleControl> motor2{mockThrottleControl2};
    GenericMotor<MockThrottleControl> motor3{mockThrottleControl3};
    GenericMotor<MockThrottleControl> motor4{mockThrottleControl4};

    MotorManager<MockThrottleControl> motorManager{motor1, motor2, motor3, motor4};
};


#endif //MARKOS_MAIN_MOTORMANAGERTEST_H

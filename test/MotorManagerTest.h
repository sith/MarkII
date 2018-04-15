#ifndef MARKOS_MAIN_MOTORMANAGERTEST_H
#define MARKOS_MAIN_MOTORMANAGERTEST_H


#include <gtest/gtest.h>
#include "MotorManager.h"
#include "MockMotor.h"

using namespace testing;
using namespace mark2;

class MotorManagerTest : public testing::Test {
protected:
    MockMotor motor1;
    MockMotor motor2;
    MockMotor motor3;
    MockMotor motor4;

    MotorManager<MockMotor> motorManager{motor1, motor2, motor3, motor4};

};


#endif //MARKOS_MAIN_MOTORMANAGERTEST_H

#ifndef MARKOS_MAIN_MOTORMANAGERTEST_H
#define MARKOS_MAIN_MOTORMANAGERTEST_H


#include <gtest/gtest.h>
#include "../src/MotorManager.h"
#include "MockMotor.h"

using namespace testing;

class MotorManagerTest : public testing::Test {
protected:
    void SetUp() override;

    MockMotor motor1;
    MockMotor motor2;
    MockMotor motor3;
    MockMotor motor4;

    MotorManager<MockMotor> motorManager{motor1, motor2, motor3, motor4};

};


#endif //MARKOS_MAIN_MOTORMANAGERTEST_H

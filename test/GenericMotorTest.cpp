//
// Created by Oleksandra Baukh on 4/19/18.
//

#include "GenericMotorTest.h"

using namespace testing;

TEST_F(GenericMotorTest, throttleUpAndDown) {
    EXPECT_CALL(mockThrottleControl, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl, throttle(0)).Times(Exactly(1));
    genericMotor.throttle(10);
    genericMotor.throttle(-10);
}

TEST_F(GenericMotorTest, throttleUpAndStop) {
    EXPECT_CALL(mockThrottleControl, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl, throttle(0)).Times(Exactly(1));
    genericMotor.throttle(10);
    genericMotor.stop();
}

TEST_F(GenericMotorTest, throttleUpOverTheLimit) {
    EXPECT_CALL(mockThrottleControl, throttle(250)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl, throttle(255)).Times(Exactly(1));
    genericMotor.throttle(250);
    genericMotor.throttle(100);
}

TEST_F(GenericMotorTest, throttleDpwnAndBelowTheLimit) {
    EXPECT_CALL(mockThrottleControl, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl, throttle(0)).Times(Exactly(1));
    genericMotor.throttle(10);
    genericMotor.throttle(-10);
}

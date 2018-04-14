//
// Created by Oleksandra Baukh on 4/14/18.
//

#include "MotorManagerTest.h"

TEST_F(MotorManagerTest, testStartMotors) {
    EXPECT_CALL(motor1, throttle(1)).Times(Exactly(1));
    EXPECT_CALL(motor2, throttle(1)).Times(Exactly(1));
    EXPECT_CALL(motor3, throttle(1)).Times(Exactly(1));
    EXPECT_CALL(motor4, throttle(1)).Times(Exactly(1));

    motorManager.start();
}

TEST_F(MotorManagerTest, testStopMotors) {
    EXPECT_CALL(motor1, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(motor2, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(motor3, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(motor4, throttle(0)).Times(Exactly(1));

    motorManager.stop();
}

void MotorManagerTest::SetUp() {
}

//
// Created by Oleksandra Baukh on 4/14/18.
//

#include "MotorManagerTest.h"

TEST_F(MotorManagerTest, startMotors) {
    EXPECT_CALL(motor1, throttle(1)).Times(Exactly(1));
    EXPECT_CALL(motor2, throttle(1)).Times(Exactly(1));
    EXPECT_CALL(motor3, throttle(1)).Times(Exactly(1));
    EXPECT_CALL(motor4, throttle(1)).Times(Exactly(1));

    motorManager.start();
}

TEST_F(MotorManagerTest, stopMotors) {
    EXPECT_CALL(motor1, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(motor2, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(motor3, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(motor4, throttle(0)).Times(Exactly(1));

    motorManager.stop();
}

TEST_F(MotorManagerTest, startMotorsOnControllerEvent) {
    EXPECT_CALL(motor1, throttle(1)).Times(Exactly(1));
    EXPECT_CALL(motor2, throttle(1)).Times(Exactly(1));
    EXPECT_CALL(motor3, throttle(1)).Times(Exactly(1));
    EXPECT_CALL(motor4, throttle(1)).Times(Exactly(1));

    ControllerState controllerState;
    controllerState.controllerCommand = ControllerCommand::START_MOTORS;
    motorManager.onEvent(controllerState);
}

TEST_F(MotorManagerTest, stopMotorsOnControllerEvent) {
    EXPECT_CALL(motor1, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(motor2, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(motor3, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(motor4, throttle(0)).Times(Exactly(1));

    ControllerState controllerState;
    controllerState.controllerCommand = ControllerCommand::STOP_MOTORS;
    motorManager.onEvent(controllerState);
}
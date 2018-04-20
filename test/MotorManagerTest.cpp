//
// Created by Oleksandra Baukh on 4/14/18.
//

#include "MotorManagerTest.h"

TEST_F(MotorManagerTest, startMotors) {
    EXPECT_CALL(mockThrottleControl1, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl2, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl3, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl4, throttle(10)).Times(Exactly(1));

    motorManager.start();
}

TEST_F(MotorManagerTest, stopMotors) {
    EXPECT_CALL(mockThrottleControl1, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl2, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl3, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl4, throttle(0)).Times(Exactly(1));

    motorManager.stop();
}

TEST_F(MotorManagerTest, startMotorsOnControllerEvent) {
    EXPECT_CALL(mockThrottleControl1, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl2, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl3, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl4, throttle(10)).Times(Exactly(1));

    ControllerState controllerState;
    controllerState.controllerCommand = ControllerCommand::START_MOTORS;
    motorManager.onEvent(controllerState);
}

TEST_F(MotorManagerTest, stopMotorsOnControllerEvent) {
    EXPECT_CALL(mockThrottleControl1, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl2, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl3, throttle(0)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl4, throttle(0)).Times(Exactly(1));

    ControllerState controllerState;
    controllerState.controllerCommand = ControllerCommand::STOP_MOTORS;
    motorManager.onEvent(controllerState);
}

TEST_F(MotorManagerTest, thrustUp) {
    EXPECT_CALL(mockThrottleControl1, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl2, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl3, throttle(10)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl4, throttle(10)).Times(Exactly(1));

    ControllerState controllerState;
    controllerState.controllerCommand = ControllerCommand::THRUST_UP;
    motorManager.onEvent(controllerState);
}

TEST_F(MotorManagerTest, thrustDown) {

    EXPECT_CALL(mockThrottleControl1, throttle(20)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl2, throttle(20)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl3, throttle(20)).Times(Exactly(1));
    EXPECT_CALL(mockThrottleControl4, throttle(20)).Times(Exactly(1));

    EXPECT_CALL(mockThrottleControl1, throttle(10)).Times(Exactly(2));
    EXPECT_CALL(mockThrottleControl2, throttle(10)).Times(Exactly(2));
    EXPECT_CALL(mockThrottleControl3, throttle(10)).Times(Exactly(2));
    EXPECT_CALL(mockThrottleControl4, throttle(10)).Times(Exactly(2));

    ControllerState controllerStateForThrustUp;
    controllerStateForThrustUp.controllerCommand = ControllerCommand::THRUST_UP;
    motorManager.onEvent(controllerStateForThrustUp);
    motorManager.onEvent(controllerStateForThrustUp);

    ControllerState controllerStateForThrustDown;
    controllerStateForThrustDown.controllerCommand = ControllerCommand::THRUST_DOWN;
    motorManager.onEvent(controllerStateForThrustDown);
}


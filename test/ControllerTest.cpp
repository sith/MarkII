#include "ControllerTest.h"

using namespace testing;

TEST_F(ControllerTest, testStartMotors) {

    mark_os::controller::ControllerState controllerState;
    controllerState.a = true;
    mockControllerState(controllerState);
    auto expectedState = mark2::ControllerState{};
    expectedState.controllerCommand = mark2::ControllerCommand::START_MOTORS;
    EXPECT_CALL(mockControllerListener, onEvent(expectedState)).Times(Exactly(1));

    controller.onEvent(0);
}

TEST_F(ControllerTest, testStopMotors) {
    mark_os::controller::ControllerState controllerState;
    controllerState.b = true;
    mockControllerState(controllerState);
    auto expectedState = mark2::ControllerState{};
    expectedState.controllerCommand = mark2::ControllerCommand::STOP_MOTORS;
    EXPECT_CALL(mockControllerListener, onEvent(expectedState)).Times(Exactly(1));

    controller.onEvent(0);
}

TEST_F(ControllerTest, thrustUp) {
    mark_os::controller::ControllerState controllerState;
    controllerState.x = true;
    mockControllerState(controllerState);
    auto expectedState = mark2::ControllerState{};
    expectedState.controllerCommand = mark2::ControllerCommand::THRUST_UP;
    EXPECT_CALL(mockControllerListener, onEvent(expectedState)).Times(Exactly(1));

    controller.onEvent(0);
}

TEST_F(ControllerTest, thrustDown) {
    mark_os::controller::ControllerState controllerState;
    controllerState.y = true;
    mockControllerState(controllerState);
    auto expectedState = mark2::ControllerState{};
    expectedState.controllerCommand = mark2::ControllerCommand::THRUST_DOWN;
    EXPECT_CALL(mockControllerListener, onEvent(expectedState)).Times(Exactly(1));

    controller.onEvent(0);
}

void ControllerTest::SetUp() {
    controller.addListener(mockControllerListener);
}

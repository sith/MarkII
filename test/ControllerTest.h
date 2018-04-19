//
// Created by Oleksandra Baukh on 4/14/18.
//

#ifndef MARKOS_MAIN_CONTROLLERTEST_H
#define MARKOS_MAIN_CONTROLLERTEST_H


#include <gtest/gtest.h>
#include <Controller.h>
#include "../../controller/test/MockReceiver.h"
#include "MockControllerListener.h"

using namespace testing;

class ControllerTest : public testing::Test {
protected:
    mark_os::communication::MockReceiver<mark_os::controller::ControllerState> mockReceiver;
    mark_os::controller::ControllerStateReceiver controllerStateReceiver{mockReceiver};
    mark2::Controller controller{controllerStateReceiver};
    mark2::MockControllerListener mockControllerListener;

    void SetUp() override;

    void mockControllerState(mark_os::controller::ControllerState controllerState) {
        mark_os::commons::Optional<Message<mark_os::controller::ControllerState>> message = mark_os::commons::optional(
                Message<mark_os::controller::ControllerState>{controllerState});
        EXPECT_CALL(mockReceiver, receive()).WillOnce(Return(message));
    }

};


#endif //MARKOS_MAIN_CONTROLLERTEST_H

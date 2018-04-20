//
// Created by Oleksandra Baukh on 4/19/18.
//

#ifndef MARKOS_MAIN_GENERICMOTORTEST_H
#define MARKOS_MAIN_GENERICMOTORTEST_H

#include <gtest/gtest.h>
#include <GenericMotor.h>
#include "MockThrottleControl.h"

class GenericMotorTest : public testing::Test {
protected:
    MockThrottleControl mockThrottleControl;
    mark2::GenericMotor<MockThrottleControl> genericMotor{mockThrottleControl};
};


#endif //MARKOS_MAIN_GENERICMOTORTEST_H

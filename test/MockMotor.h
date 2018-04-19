//
// Created by Oleksandra Baukh on 4/14/18.
//

#ifndef MARKOS_MAIN_MOCKMOTOR_H
#define MARKOS_MAIN_MOCKMOTOR_H

#include "gmock/gmock.h"
#include <types.h>

class MockMotor {
public:
    MOCK_METHOD1(throttle,
                 void(uint8
                         throttleValue));

    MOCK_METHOD0(stop,
                 void());
};

#endif //MARKOS_MAIN_MOCKMOTOR_H

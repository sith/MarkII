//
// Created by Oleksandra Baukh on 4/19/18.
//

#ifndef MARKOS_MAIN_MOCKTHROTTLECONTROL_H
#define MARKOS_MAIN_MOCKTHROTTLECONTROL_H

#include "gmock/gmock.h"
#include <types.h>

class MockThrottleControl {
public:
    MOCK_METHOD1(throttle,
                 void(uint8
                         throttleValue));

    void operator()(uint8 throttleValue) {
        throttle(throttleValue);
    }
};

#endif //MARKOS_MAIN_MOCKTHROTTLECONTROL_H

//
// Created by Oleksandra Baukh on 4/19/18.
//

#ifndef MARKOS_MAIN_GENERICMOTOR_H
#define MARKOS_MAIN_GENERICMOTOR_H

#include <types.h>

namespace mark2 {
    template<typename ThrottleControl>
    class GenericMotor {
        uint8 currentThrottleValue = 0;
        static const uint8 minThrottleValue = 0;
        static const uint8 maxThrottleValue = 255;
        ThrottleControl &throttleControl;
    public:

        GenericMotor(ThrottleControl &throttleControl) : throttleControl(throttleControl) {}

        void throttle(int16 throttleDelta) {

            if (maxThrottleValue - currentThrottleValue < throttleDelta) {
                currentThrottleValue = maxThrottleValue;
            } else if (minThrottleValue - currentThrottleValue > throttleDelta) {
                currentThrottleValue = minThrottleValue;
            } else {
                currentThrottleValue += throttleDelta;
            }

            throttleControl(currentThrottleValue);
        }

        void stop() {
            currentThrottleValue = 0;
            throttleControl(currentThrottleValue);
        }
    };
}

#endif //MARKOS_MAIN_GENERICMOTOR_H

//
// Created by Oleksandra Baukh on 4/14/18.
//

#ifndef MARKOS_MAIN_MOTORMANAGER_H
#define MARKOS_MAIN_MOTORMANAGER_H

#include "Controller.h"

namespace mark2 {
    template<typename Motor>
    class MotorManager : public ControllerListener {
        Motor &motor1;
        Motor &motor2;
        Motor &motor3;
        Motor &motor4;
    public:
        MotorManager(Motor &motor1, Motor &motor2, Motor &motor3, Motor &motor4) : motor1(
                motor1), motor2(motor2),
                                                                                   motor3(motor3),
                                                                                   motor4(motor4) {}

        void start();

        void stop();

        void onEvent(ControllerState &controllerState) override;
    };

    template<typename Motor>
    void MotorManager<Motor>::start() {
        motor1.throttle(1);
        motor2.throttle(1);
        motor3.throttle(1);
        motor4.throttle(1);
    }

    template<typename Motor>
    void MotorManager<Motor>::stop() {
        motor1.throttle(0);
        motor2.throttle(0);
        motor3.throttle(0);
        motor4.throttle(0);

    }

    template<typename Motor>
    void MotorManager<Motor>::onEvent(ControllerState &controllerState) {
        switch (controllerState.controllerCommand) {
            case ControllerCommand::START_MOTORS:
                start();
                break;
            case ControllerCommand::STOP_MOTORS:
                stop();
                break;
        }
    }
}
#endif //MARKOS_MAIN_MOTORMANAGER_H

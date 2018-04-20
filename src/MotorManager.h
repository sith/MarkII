//
// Created by Oleksandra Baukh on 4/14/18.
//

#ifndef MARKOS_MAIN_MOTORMANAGER_H
#define MARKOS_MAIN_MOTORMANAGER_H

#include "Controller.h"
#include "GenericMotor.h"

namespace mark2 {
    template<typename Motor>
    class MotorManager : public ControllerListener {

        static const uint8 throttleStep = 10;

        GenericMotor<Motor> &motor1;
        GenericMotor<Motor> &motor2;
        GenericMotor<Motor> &motor3;
        GenericMotor<Motor> &motor4;
    public:
        MotorManager(GenericMotor<Motor> &motor1, GenericMotor<Motor> &motor2, GenericMotor<Motor> &motor3,
                     GenericMotor<Motor> &motor4);

        void start();

        void stop();

        void onEvent(ControllerState &controllerState) override;
    };

    template<typename Motor>
    void MotorManager<Motor>::start() {
        motor1.throttle(throttleStep);
        motor2.throttle(throttleStep);
        motor3.throttle(throttleStep);
        motor4.throttle(throttleStep);
    }

    template<typename Motor>
    void MotorManager<Motor>::stop() {
        motor1.stop();
        motor2.stop();
        motor3.stop();
        motor4.stop();

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
            case ControllerCommand::THRUST_UP:
                motor1.throttle(throttleStep);
                motor2.throttle(throttleStep);
                motor3.throttle(throttleStep);
                motor4.throttle(throttleStep);
                break;
            case ControllerCommand::THRUST_DOWN:
                motor1.throttle(-throttleStep);
                motor2.throttle(-throttleStep);
                motor3.throttle(-throttleStep);
                motor4.throttle(-throttleStep);
                break;
        }
    }

    template<typename Motor>
    MotorManager<Motor>::MotorManager(GenericMotor<Motor> &motor1, GenericMotor<Motor> &motor2,
                                      GenericMotor<Motor> &motor3, GenericMotor<Motor> &motor4):motor1(motor1),
                                                                                                motor2(motor2),
                                                                                                motor3(motor3),
                                                                                                motor4(motor4) {}
}
#endif //MARKOS_MAIN_MOTORMANAGER_H

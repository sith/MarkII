//
// Created by Oleksandra Baukh on 4/14/18.
//

#ifndef MARKOS_MAIN_MOTORMANAGER_H
#define MARKOS_MAIN_MOTORMANAGER_H

template<typename Motor>
class MotorManager {
    Motor &motor1;
    Motor &motor2;
    Motor &motor3;
    Motor &motor4;
public:
    MotorManager(Motor &motor1, Motor &motor2, Motor &motor3, Motor &motor4) : motor1(motor1), motor2(motor2),
                                                                               motor3(motor3), motor4(motor4) {}
    void start();

    void stop();
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


#endif //MARKOS_MAIN_MOTORMANAGER_H

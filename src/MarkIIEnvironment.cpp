//
// Created by Oleksandra Baukh on 4/14/18.
//

#include "MarkIIEnvironment.h"

template<typename Motor>
void mark2::MarkIIEnvironment<Motor>::init() {
    getCycle().getListeners()->add(&getController());
    getController().addListener(getMotorManager());
}

template<typename Motor>
void mark2::MarkIIEnvironment<Motor>::loop() {
    getCycle().next();
}

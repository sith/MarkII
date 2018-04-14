//
// Created by Oleksandra Baukh on 4/14/18.
//

#include "MarkIIEnvironment.h"


void mark2::MarkIIEnvironment::init() {
    cycle().getListeners()->add(&controller());
}

void mark2::MarkIIEnvironment::loop() {
    cycle().next();
}

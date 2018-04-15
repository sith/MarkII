//
// Created by Oleksandra Baukh on 4/14/18.
//

#ifndef MARKOS_MAIN_MARKIIENVIRONMENT_H
#define MARKOS_MAIN_MARKIIENVIRONMENT_H


#include <Cycle.h>
#include "Controller.h"
#include "MotorManager.h"

namespace mark2 {
    template<typename Motor>
    class MarkIIEnvironment {
    public:
        void init();

        void loop();

        virtual mark_os::cycle::Cycle &getCycle()= 0;

        virtual Controller &getController()= 0;

        virtual MotorManager<Motor> &getMotorManager()= 0;
    };
}

#endif //MARKOS_MAIN_MARKIIENVIRONMENT_H

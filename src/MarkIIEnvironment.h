//
// Created by Oleksandra Baukh on 4/14/18.
//

#ifndef MARKOS_MAIN_MARKIIENVIRONMENT_H
#define MARKOS_MAIN_MARKIIENVIRONMENT_H


#include <Cycle.h>
#include "Controller.h"

namespace mark2 {
    class MarkIIEnvironment {
    public:
        void init();

        void loop();

        virtual mark_os::cycle::Cycle &cycle()= 0;

        virtual Controller &controller()= 0;


    };
}

#endif //MARKOS_MAIN_MARKIIENVIRONMENT_H

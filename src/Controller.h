//
// Created by Oleksandra Baukh on 4/14/18.
//

#ifndef MARKOS_MAIN_CONTROLLER_H
#define MARKOS_MAIN_CONTROLLER_H

#include <CycleListener.h>
#include <Controller.h>
#include "Controller.h"

namespace mark2 {

    enum class ControllerCommand {
        NONE,
        START,
        STOP,

    };

    class Controller : public mark_os::cycle::CycleListener {
    public:
        void onEvent(unsigned long cycleNumber) override;

        virtual ControllerCommand read()= 0;
    };
}

#endif //MARKOS_MAIN_CONTROLLER_H

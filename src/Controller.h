//
// Created by Oleksandra Baukh on 4/14/18.
//

#ifndef MARKII_MAIN_CONTROLLER_H
#define MARKII_MAIN_CONTROLLER_H

#include <CycleListener.h>
#include "Controller.h"
#include <collections/List.h>
#include <collections/LinkedList.h>
#include <ControllerStateReceiver.h>
#include "Controller.h"

namespace mark2 {

    enum class ControllerCommand {
        NONE,
        START_MOTORS,
        STOP_MOTORS,
    };

    struct ControllerState {
        ControllerCommand controllerCommand;
    };

    class ControllerListener {
    public:
        virtual void onEvent(ControllerState &controllerState)= 0;
    };

    class Controller : public mark_os::cycle::CycleListener {
        mark_os::commons::List<ControllerListener> *listeners = new mark_os::commons::LinkedList<ControllerListener>;

        mark_os::controller::ControllerStateReceiver &controllerStateReceiver;
    public:

        Controller(mark_os::controller::ControllerStateReceiver &controllerStateReceiver);

        void onEvent(unsigned long cycleNumber) override;

        virtual ~Controller();

        void addListener(ControllerListener &listener);

        void removeListener(ControllerListener &listener);
    };
}

#endif //MARKII_MAIN_CONTROLLER_H

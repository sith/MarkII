//
// Created by Oleksandra Baukh on 4/14/18.
//

#include "Controller.h"

void mark2::Controller::onEvent(unsigned long cycleNumber) {
    auto controllerState = controllerStateReceiver.readControllerState();

    if (controllerState) {
        mark2::ControllerState internalControllerState{};
        if (controllerState().a) {
            internalControllerState.controllerCommand = ControllerCommand::START_MOTORS;
        }
        if (controllerState().b) {
            internalControllerState.controllerCommand = ControllerCommand::STOP_MOTORS;
        }

        if (controllerState().x) {
            internalControllerState.controllerCommand = ControllerCommand::THRUST_UP;
        }

        if (controllerState().y) {
            internalControllerState.controllerCommand = ControllerCommand::THRUST_DOWN;
        }

        auto iteratorPointer = listeners->iterator();
        auto iterator = iteratorPointer.get();
        while (iterator->hasNext()) {
            auto listener = iterator->next();
            listener->onEvent(internalControllerState);
        }
    }
}

mark2::Controller::~Controller() {
    delete listeners;
}

void mark2::Controller::addListener(mark2::ControllerListener &listener) {
    listeners->add(&listener);
}

void mark2::Controller::removeListener(mark2::ControllerListener &listener) {
    listeners->removeByPointer(&listener);
}

mark2::Controller::Controller(mark_os::controller::ControllerStateReceiver &controllerStateReceiver)
        : controllerStateReceiver(controllerStateReceiver) {}

bool mark2::ControllerState::operator==(const mark2::ControllerState &rhs) const {
    return controllerCommand == rhs.controllerCommand;
}

bool mark2::ControllerState::operator!=(const mark2::ControllerState &rhs) const {
    return !(rhs == *this);
}

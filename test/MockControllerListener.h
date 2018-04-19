//
// Created by Oleksandra Baukh on 4/18/18.
//

#ifndef MARKOS_MAIN_MOCKCONTROLLERLISTENER_H
#define MARKOS_MAIN_MOCKCONTROLLERLISTENER_H

#include <gmock/gmock.h>
#include <Controller.h>

namespace mark2 {

    class MockControllerListener : public ControllerListener {
    public:
        MOCK_METHOD1(onEvent,
                     void(ControllerState
                             &controllerState));
    };

}  // namespace mark2

#endif //MARKOS_MAIN_MOCKCONTROLLERLISTENER_H

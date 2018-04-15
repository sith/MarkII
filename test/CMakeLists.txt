cmake_minimum_required(VERSION 3.10)
project(MarkII_tests)

add_executable(${PROJECT_NAME}
        main.cpp
        ControllerTest.cpp
        ControllerTest.h
        MockMotor.h
        MotorManagerTest.cpp
        MotorManagerTest.h)

target_link_libraries(${PROJECT_NAME} gtest gtest_main)
target_link_libraries(${PROJECT_NAME} gmock gmock_main)
target_link_libraries(${PROJECT_NAME} MarkOS_time)
target_link_libraries(${PROJECT_NAME} MarkII)
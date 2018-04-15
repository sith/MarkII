cmake_minimum_required(VERSION 3.10)
project(MarkII)

add_library(${PROJECT_NAME}
        src/MarkIIEnvironment.cpp src/MarkIIEnvironment.h src/Controller.cpp src/Controller.h src/MotorManager.h)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_commons)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_cycle)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_controller)

add_subdirectory(test)

install(DIRECTORY "src/"
        DESTINATION "/Users/oleksandrabaukh/workspace/libs/MarkOS/MarkII")
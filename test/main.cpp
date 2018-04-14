//
// Created by Oleksandra Baukh on 3/19/18.
//

#include <gmock/gmock.h>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}

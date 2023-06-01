/*
** front-communication, 2023
** GoodLoading.cpp by 0xMemoryGrinder
*/

#include <gtest/gtest.h>
#include <filesystem>
#include "osmium/module-tester/Tester.hpp"

TEST(CorrectBehavior, CorrectBehavior)
{
    EXPECT_NO_THROW({
        std::shared_ptr<osmium::moduleTester::Tester> tester = osmium::moduleTester::Tester::create();
#ifdef _WIN32
        tester->loadModule("./backend-frontCommunication.dll");
#else
        tester->loadModule("./backend-frontCommunication.so");
#endif
    });
}
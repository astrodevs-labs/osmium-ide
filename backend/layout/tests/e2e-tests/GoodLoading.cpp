/*
** editing, 2023
** GoodLoading.cpp by 0xMemoryGrinder
*/

#include <gtest/gtest.h>
#include <filesystem>
#include "osmium/module-tester/Tester.hpp"

TEST(CorrectBehavior, CorrectBehavior)
{
#if _WIN32
    std::string path = "./backend-layout.dll";
#else
    std::string path = "./backend-layout.so";
#endif
    EXPECT_NO_THROW({
        std::shared_ptr<osmium::moduleTester::Tester> tester = osmium::moduleTester::Tester::create();
        tester->loadModule(path);
    });
}
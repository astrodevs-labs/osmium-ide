/*
** backend, 2023
** Core.cpp by 0xMemoryGrinder
*/

#include <gtest/gtest.h>
#include "CoreTester.hpp"

TEST(Core, AddHandler)
{
    core::tests::CoreTester core;
    core::handler_id id = core.registerHandler<int>(1000, [](std::shared_ptr<int>, std::string){});
    EXPECT_TRUE(core.hasHandler(id));
}

TEST(Core, AddHandlerWithPriority)
{
    core::tests::CoreTester core;
    core::handler_id id = core.registerHandler<int>(1000, [](std::shared_ptr<int>, std::string){});
    EXPECT_TRUE(core.hasHandler(1000, id));
}

TEST(Core, AddHandlerWithPriorityAndType)
{
    core::tests::CoreTester core;
    core::handler_id id = core.registerHandler<int>(1000, [](std::shared_ptr<int>, std::string){});
    EXPECT_TRUE(core.hasHandler<int>(1000, id));
}

TEST(Core, RemoveHandler)
{
    core::tests::CoreTester core;
    core::handler_id id = core.registerHandler<int>(1000, [](std::shared_ptr<int>, std::string){});
    core.removeHandler(id);
    EXPECT_FALSE(core.hasHandler(id));
}
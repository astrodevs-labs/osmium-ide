/*
** backend, 2023
** GoodDispatch.cpp by 0xMemoryGrinder
*/

#include <gtest/gtest.h>
#include "ModulesMediator.hpp"
#include "Core.hpp"

TEST(GoodDispatch, SimpleString)
{
    core::tests::ModulesMediator::setType(core::tests::ModulesMediator::Type::STRING);
    auto core = std::make_shared<core::Core>();

    core->loadSoFile("core/tests/libbackend-core-tests-input-module.so");
}
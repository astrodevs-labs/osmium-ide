/*
** backend, 2023
** GoodDispatch.cpp by 0xMemoryGrinder
*/

#include <gtest/gtest.h>
#include "ModulesMediator.hpp"
#include "Core.hpp"

core::tests::ModulesMediator::Type type;

TEST(GoodDispatch, SimpleString)
{
    core::tests::ModulesMediator::setType(core::tests::ModulesMediator::Type::STRING);
    core::tests::ModulesMediator::setup();
    auto core = std::make_shared<core::Core>();

    core->loadSoFile("core/tests/backend-core-tests-input-module-string.so");
    core->emitMessage(std::make_shared<std::string>("Hello World!"), "test").wait();
    core::tests::ModulesMediator::parseReceived();
    auto received = core::tests::ModulesMediator::getReceived("InputModule");
    ASSERT_EQ(received.size(), 1);
    ASSERT_STREQ(std::any_cast<std::string>(received[0]).c_str(), "Hello World!");
    core::tests::ModulesMediator::readerTeardown();
}

TEST(GoodDispatch, SimpleInt)
{
    core::tests::ModulesMediator::setType(core::tests::ModulesMediator::Type::INT);
    core::tests::ModulesMediator::setup();
    auto core = std::make_shared<core::Core>();

    core->loadSoFile("core/tests/backend-core-tests-input-module-int.so");
    core->emitMessage(std::make_shared<int>(42), "test").wait();
    core::tests::ModulesMediator::parseReceived();
    auto received = core::tests::ModulesMediator::getReceived("InputModule");
    ASSERT_EQ(received.size(), 1);
    ASSERT_EQ(std::any_cast<int>(received[0]), 42);
    core::tests::ModulesMediator::readerTeardown();
}

TEST(GoodDispatch, SimpleFloat)
{
    core::tests::ModulesMediator::setType(core::tests::ModulesMediator::Type::FLOAT);
    core::tests::ModulesMediator::setup();
    auto core = std::make_shared<core::Core>();

    core->loadSoFile("core/tests/backend-core-tests-input-module-float.so");
    core->emitMessage(std::make_shared<float>(42.42), "test").wait();
    core::tests::ModulesMediator::parseReceived();
    auto received = core::tests::ModulesMediator::getReceived("InputModule");
    ASSERT_EQ(received.size(), 1);
    ASSERT_FLOAT_EQ(std::any_cast<float>(received[0]), 42.42);
    core::tests::ModulesMediator::readerTeardown();
}

TEST(GoodDispatch, SimpleDouble)
{
    core::tests::ModulesMediator::setType(core::tests::ModulesMediator::Type::DOUBLE);
    core::tests::ModulesMediator::setup();
    auto core = std::make_shared<core::Core>();

    core->loadSoFile("core/tests/backend-core-tests-input-module-double.so");
    core->emitMessage(std::make_shared<double>(42.42), "test").wait();
    core::tests::ModulesMediator::parseReceived();
    auto received = core::tests::ModulesMediator::getReceived("InputModule");
    ASSERT_EQ(received.size(), 1);
    ASSERT_DOUBLE_EQ(std::any_cast<double>(received[0]), 42.42);
    core::tests::ModulesMediator::readerTeardown();
}

TEST(GoodDispatch, SimpleChar)
{
    core::tests::ModulesMediator::setType(core::tests::ModulesMediator::Type::CHAR);
    core::tests::ModulesMediator::setup();
    auto core = std::make_shared<core::Core>();

    core->loadSoFile("core/tests/backend-core-tests-input-module-char.so");
    core->emitMessage(std::make_shared<char>('a'), "test").wait();
    core::tests::ModulesMediator::parseReceived();
    auto received = core::tests::ModulesMediator::getReceived("InputModule");
    ASSERT_EQ(received.size(), 1);
    ASSERT_EQ(std::any_cast<char>(received[0]), 'a');
    core::tests::ModulesMediator::readerTeardown();
}

TEST(GoodDispatch, SimpleBool)
{
    core::tests::ModulesMediator::setType(core::tests::ModulesMediator::Type::BOOL);
    core::tests::ModulesMediator::setup();
    auto core = std::make_shared<core::Core>();

    core->loadSoFile("core/tests/backend-core-tests-input-module-bool.so");
    core->emitMessage(std::make_shared<bool>(true), "test").wait();
    core::tests::ModulesMediator::parseReceived();
    auto received = core::tests::ModulesMediator::getReceived("InputModule");
    ASSERT_EQ(received.size(), 1);
    ASSERT_EQ(std::any_cast<bool>(received[0]), true);
    core::tests::ModulesMediator::readerTeardown();
}

TEST(GoodDispatch, SimpleNull)
{
    core::tests::ModulesMediator::setType(core::tests::ModulesMediator::Type::BOOL);
    core::tests::ModulesMediator::setup();
    auto core = std::make_shared<core::Core>();

    core->loadSoFile("core/tests/backend-core-tests-input-module-bool.so");
    core->emitMessage(std::make_shared<bool>(nullptr), "test").wait();
    core::tests::ModulesMediator::parseReceived();
    auto received = core::tests::ModulesMediator::getReceived("InputModule");
    ASSERT_EQ(received.size(), 1);
    ASSERT_EQ(std::any_cast<bool>(received[0]), 0);
    core::tests::ModulesMediator::readerTeardown();
}
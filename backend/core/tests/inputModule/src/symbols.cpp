/*
** backend, 2023
** symbols.cpp by 0xMemoryGrinder
*/

#include <string>
#include <memory>
#include "InputModule.hpp"
#include "../../e2e-tests/ModulesMediator.hpp"

extern "C" {
    const char *getModuleName() {
        return "inputModule";
    }

    void *createModule(std::shared_ptr<core::MessagingInterface> msg) {
        switch (core::tests::ModulesMediator::getType()) {
            case core::tests::ModulesMediator::Type::STRING:
                return new core::tests::input::InputModule<std::string>(msg);
            case core::tests::ModulesMediator::Type::INT:
                return new core::tests::input::InputModule<int>(msg);
            case core::tests::ModulesMediator::Type::FLOAT:
                return new core::tests::input::InputModule<float>(msg);
            case core::tests::ModulesMediator::Type::DOUBLE:
                return new core::tests::input::InputModule<double>(msg);
            case core::tests::ModulesMediator::Type::CHAR:
                return new core::tests::input::InputModule<char>(msg);
            case core::tests::ModulesMediator::Type::BOOL:
                return new core::tests::input::InputModule<bool>(msg);
            case core::tests::ModulesMediator::Type::EMPTY:
                return new core::tests::input::InputModule<void>(msg);
            // TODO: add custom type
            default:
                return new core::tests::input::InputModule<void>(msg);
        }
    }
}
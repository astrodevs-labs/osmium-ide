/*
** backend, 2023
** symbols.cpp by Leon
*/

#include <string>
#include <memory>
#include "ProjectModule.hpp"
#include "../../e2e-tests/ModulesMediator.hpp"

extern "C"
{
    const char *getModuleName() { return "projectModule"; }

    void *createModule(std::shared_ptr<core::MessagingInterface> msg)
    {
        core::tests::ModulesMediator::Type type;
#ifdef TYPE_STRING
        type = core::tests::ModulesMediator::Type::STRING;
#elif defined(TYPE_INT)
        type = core::tests::ModulesMediator::Type::INT;
#elif defined(TYPE_FLOAT)
        type = core::tests::ModulesMediator::Type::FLOAT;
#elif defined(TYPE_DOUBLE)
        type = core::tests::ModulesMediator::Type::DOUBLE;
#elif defined(TYPE_CHAR)
        type = core::tests::ModulesMediator::Type::CHAR;
#elif defined(TYPE_BOOL)
        type = core::tests::ModulesMediator::Type::BOOL;
#elif defined(TYPE_EMPTY)
        type = core::tests::ModulesMediator::Type::EMPTY;
#else
        type = core::tests::ModulesMediator::Type::CUSTOM;
#endif

        switch (type) {
            case core::tests::ModulesMediator::Type::STRING:
                return new core::tests::project::ProjectModule<std::string>(msg);
            case core::tests::ModulesMediator::Type::INT:
                std::cerr << "INT" << std::endl;
                return new core::tests::project::ProjectModule<int>(msg);
            case core::tests::ModulesMediator::Type::FLOAT:
                return new core::tests::project::ProjectModule<float>(msg);
            case core::tests::ModulesMediator::Type::DOUBLE:
                return new core::tests::project::ProjectModule<double>(msg);
            case core::tests::ModulesMediator::Type::CHAR:
                return new core::tests::project::ProjectModule<char>(msg);
            case core::tests::ModulesMediator::Type::BOOL:
                return new core::tests::project::ProjectModule<bool>(msg);
                //            case core::tests::ModulesMediator::Type::EMPTY:
                //                return new core::tests::project::ProjectModule<void>(msg);
                // TODO: add custom type
            default:
                //                return new core::tests::project::ProjectModule<void>(msg);
                return nullptr;
        }
    }
}

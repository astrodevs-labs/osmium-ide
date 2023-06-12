/*
** backend, 2023
** symbols.cpp by Leon
*/

#include <string>
#include <memory>
#include "../../core/include/MessagingInterface.hpp"
#include "../include/ProjectModule.hpp"

extern "C"
{
    const char *getModuleName() { return "projectModule"; }

    void *createModule(std::shared_ptr<core::MessagingInterface> msg) { return new project::ProjectModule(msg); }
}

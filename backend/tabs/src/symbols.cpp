/*
** backend, 2023
** symbols.cpp by Leon
*/

#include <string>
#include <memory>
#include "../../core/include/MessagingInterface.hpp"
#include "../include/TabsModule.hpp"

extern "C"
{
    const char *getModuleName() { return "tabsModule"; }

    void *createModule(std::shared_ptr<core::MessagingInterface> msg) { return new tabs::TabsModule(msg); }
}
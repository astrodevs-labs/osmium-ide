/*
** backend, 2023
** symbols.cpp by Leon
*/

#include <string>
#include <memory>
#include "../../core/include/MessagingInterface.hpp"
#include "../include/EditingModule.hpp"

extern "C"
{
    const char *getModuleName() { return "editingModule"; }

    void *createModule(std::shared_ptr<core::MessagingInterface> msg) { return new editing::EditingModule(msg); }
}
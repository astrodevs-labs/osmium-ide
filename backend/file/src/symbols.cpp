/*
** backend, 2023
** symbols.cpp by Leon
*/

#include <string>
#include <memory>
#include "../../core/include/MessagingInterface.hpp"
#include "FileModule.hpp"

extern "C"
{
const char *getModuleName() { return "fileModule"; }

void *createModule(std::shared_ptr<core::MessagingInterface> msg) { return new file::FileModule(msg); }
}
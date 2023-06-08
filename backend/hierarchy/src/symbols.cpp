#include <string>
#include <memory>
#include "../../core/include/MessagingInterface.hpp"
#include "../include/HierarchyModule.hpp"

extern "C"
{
const char *getModuleName() { return "hierarchyModule"; }

void *createModule(std::shared_ptr<core::MessagingInterface> msg) { return new hierarchy::HierarchyModule(msg); }
}
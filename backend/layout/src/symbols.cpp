#include <string>
#include <memory>
#include "../../core/include/MessagingInterface.hpp"
#include "../include/LayoutModule.hpp"

extern "C"
{
    const char *getModuleName() { return "layoutModule"; }

    void *createModule(std::shared_ptr<core::MessagingInterface> msg) { return new layout::LayoutModule(msg); }
}
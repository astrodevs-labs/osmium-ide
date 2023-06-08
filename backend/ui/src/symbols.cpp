#include <string>
#include <memory>
#include "../../core/include/MessagingInterface.hpp"
#include "../include/UiModule.hpp"

extern "C"
{
    const char *getModuleName() { return "uiModule"; }

    void *createModule(std::shared_ptr<core::MessagingInterface> msg) { return new ui::UiModule(msg); }
}
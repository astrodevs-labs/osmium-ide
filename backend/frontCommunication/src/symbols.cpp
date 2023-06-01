/*
** backend, 2023
** symbols.cpp by 0xMemoryGrinder
*/

#include <string>
#include <memory>
#include "../../core/include/MessagingInterface.hpp"
#include "FrontCommunicationModule.hpp"

extern "C" {
    const char *getModuleName() {
        return "inputModule";
    }

    void *createModule(std::shared_ptr<core::MessagingInterface> msg) {
        return new front_communication::FrontCommunicationModule(msg);
    }
}
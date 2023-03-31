/*
** backend, 2022
** MessagingInterface.cpp by 0xMemoryGrinder
*/


#include "MessagingInterface.hpp"

core::MessagingInterface::MessagingInterface(std::shared_ptr<Core> core,
                                             std::string moduleName)
    : _core(std::move(core)), _moduleName(std::move(moduleName))
{}

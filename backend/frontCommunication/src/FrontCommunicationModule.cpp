/*
** front-communication, 2022
** FrontCommunicationModule.cpp by 0xMemoryGrinder
*/


#include "FrontCommunicationModule.hpp"

front_communication::FrontCommunicationModule::FrontCommunicationModule(
        std::shared_ptr<core::MessagingInterface> msg) : _msg(msg)
{

}

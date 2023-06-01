/*
** front-communication, 2023
** FrontCommunicationModule.hpp by 0xMemoryGrinder
*/

#pragma once

#include "../../core/include/MessagingInterface.hpp"

namespace front_communication
{
    class FrontCommunicationModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            FrontCommunicationModule(
                    std::shared_ptr<core::MessagingInterface> msg);

            ~FrontCommunicationModule() = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            std::shared_ptr<core::MessagingInterface> _msg;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:


        private:


//////////////////////--------------------------/////////////////////////

    };
}
/*
** backend, 2023
** InputModule.hpp by 0xMemoryGrinder
*/

#pragma once

#include <memory>
#include "MessagingInterface.hpp"
#include "../../e2e-tests/ModulesMediator.hpp"

namespace core::tests::input
{

    template<class T>
    class InputModule : public core::IModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            InputModule(std::shared_ptr<MessagingInterface> msg)
            {
                ModulesMediator::setup();
                this->msg = msg;

                this->msg->registerHandler<T>(1000, [](std::shared_ptr<T> received, std::string from) {
                    ModulesMediator::addReceived("InputModule", received);
                });
            }

            ~InputModule() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            static inline std::shared_ptr<MessagingInterface> msg;


        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:


        private:


//////////////////////--------------------------/////////////////////////

    };
}

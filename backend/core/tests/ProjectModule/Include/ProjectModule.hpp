/*
** backend, 2023
** ProjectModule.hpp by Leon
*/

#pragma once

#include <memory>
#include "MessagingInterface.hpp"
#include "../../e2e-tests/ModulesMediator.hpp"

namespace core::tests::project
{

    template <class T> class ProjectModule : public core::IModule
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            ProjectModule(std::shared_ptr<MessagingInterface> msg)
            {
                ModulesMediator::setup();
                this->msg = msg;

                this->msg->registerHandler<T>(
                    1000, [](std::shared_ptr<T> received, std::string from) { ModulesMediator::addReceived("ProjectModule", received); });
            }

            ~ProjectModule() override = default;

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
} // namespace core::tests::project

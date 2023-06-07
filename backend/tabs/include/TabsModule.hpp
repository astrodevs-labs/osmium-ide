/*
** Tabs, 2023
** TabsModule.hpp by Léon
*/

#pragma once

#include "../../core/include/MessagingInterface.hpp"

namespace tabs
{
    class TabsModule
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            TabsModule(std::shared_ptr<core::MessagingInterface> msg);

            ~TabsModule() = default;

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
} // namespace tabs

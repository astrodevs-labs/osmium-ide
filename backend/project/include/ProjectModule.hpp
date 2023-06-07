/*
** Project, 2023
** ProjectModule.hpp by Léon
*/

#pragma once

#include "../../core/include/MessagingInterface.hpp"

namespace project
{
    class ProjectModule
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            ProjectModule(std::shared_ptr<core::MessagingInterface> msg);

            ~ProjectModule() = default;

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
} // namespace project

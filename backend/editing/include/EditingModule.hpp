/*
** Editing, 2023
** EditingModule.hpp by Léon
*/

#pragma once

#include "../../core/include/MessagingInterface.hpp"

namespace editing
{
    class EditingModule
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            EditingModule(std::shared_ptr<core::MessagingInterface> msg);

            ~EditingModule() = default;

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
} // namespace editing

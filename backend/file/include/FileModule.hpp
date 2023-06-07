/*
** File, 2023
** FileModule.hpp by Léon
*/

#pragma once

#include "../../core/include/MessagingInterface.hpp"

namespace file
{
    class FileModule
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            FileModule(std::shared_ptr<core::MessagingInterface> msg);

            ~FileModule() = default;

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

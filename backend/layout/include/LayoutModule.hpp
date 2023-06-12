#pragma once

#include "../../core/include/MessagingInterface.hpp"

namespace layout
{
    class LayoutModule
    {

            ////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            LayoutModule(std::shared_ptr<core::MessagingInterface> msg);

            ~LayoutModule() = default;

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
} // namespace layout

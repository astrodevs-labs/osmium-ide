/*
** backend, 2022
** DynamicLibraryLoadingException.hpp by 0xMemoryGrinder
*/

#pragma once

#include <iostream>
#include <exception>

namespace core {
    class DynamicLibraryLoadingException : public std::exception
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            DynamicLibraryLoadingException(std::string message) : _message(message) {}

            ~DynamicLibraryLoadingException() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            std::string _message;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            const char *what() const noexcept override {
                return this->_message.c_str();
            }

        private:


//////////////////////--------------------------/////////////////////////

    };

}

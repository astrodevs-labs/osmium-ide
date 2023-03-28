/*
** backend, 2022
** DynamicLibraryLoadingException.hpp by 0xMemoryGrinder
*/

#pragma once

#include <iostream>
#include <exception>

namespace core {
    class DynamicLibraryException : public std::exception
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            DynamicLibraryException(std::string reason, std::string libPath, std::string error);

            ~DynamicLibraryException() override = default;


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        private:
            std::string _libPath;
            std::string _formattedMessage;

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            const char *what() const noexcept override;

        private:


//////////////////////--------------------------/////////////////////////

    };

}

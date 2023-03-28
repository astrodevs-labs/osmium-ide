/*
** backend, 2022
** MissingDynamicLibraryException.hpp by 0xMemoryGrinder
*/

#pragma once
#include <exception>
#include <string>
#include <utility>
#include "DynamicLibraryException.hpp"

namespace core
{
    class MissingDynamicLibraryException : public DynamicLibraryException
    {
        public:
            MissingDynamicLibraryException(std::string libPath);

            ~MissingDynamicLibraryException() override = default;
    };
}
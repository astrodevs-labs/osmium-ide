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
    class CorruptedDynamicLibraryException : public DynamicLibraryException
    {
        public:
            CorruptedDynamicLibraryException(std::string libPath, std::string message);

            ~CorruptedDynamicLibraryException() override = default;
    };
}
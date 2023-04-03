/*
** backend, 2022
** CorruptedDynamicLibraryException.cpp by ByFish
*/

#include <gtest/gtest.h>
#include "exceptions/CorruptedDynamicLibraryException.hpp"

TEST(CorruptedDynamicLibraryException, WhatReturnsFormattedMessage) {
    const std::string libPath = "mylib.dll";
    const std::string message = "corrupted library";
    core::CorruptedDynamicLibraryException exception(libPath, message);

    const char* what = exception.what();
    const std::string expectedMessage = "[DynamicLibraryException] Corrupted dynamic library while interacting with dynamic library at path " + libPath + ": corrupted library";

    ASSERT_STREQ(what, expectedMessage.c_str());
}
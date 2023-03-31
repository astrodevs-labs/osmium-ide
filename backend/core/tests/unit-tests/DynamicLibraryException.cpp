/*
** backend, 2022
** DynamicLibraryException.cpp by ByFish
*/

#include <gtest/gtest.h>
#include "exceptions/DynamicLibraryException.hpp"

TEST(DynamicLibraryException, WhatReturnsFormattedMessage) {
    const std::string reason = "Failed to load library";
    const std::string libPath = "mylib.dll";
    const std::string error = "library not found";
    core::DynamicLibraryException exception(reason, libPath, error);

    const char* what = exception.what();
    const std::string expectedMessage = "[DynamicLibraryException] " + reason + " while interacting with dynamic library at path " + libPath + ": " + error;

    ASSERT_STREQ(what, expectedMessage.c_str());
}
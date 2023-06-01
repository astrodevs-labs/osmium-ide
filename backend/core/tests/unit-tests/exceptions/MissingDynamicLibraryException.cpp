/*
** backend, 2022
** MissingDynamicLibraryException.cpp by ByFish
*/

#include <gtest/gtest.h>
#include "exceptions/MissingDynamicLibraryException.hpp"

TEST(MissingDynamicLibraryException, WhatReturnsFormattedMessage) {
    const std::string libPath = "mylib.dll";
    core::MissingDynamicLibraryException exception(libPath);

    const char* what = exception.what();
    const std::string expectedMessage = "[DynamicLibraryException] Missing dynamic library while interacting with dynamic library at path " + libPath + ": No such file or directory";

    ASSERT_STREQ(what, expectedMessage.c_str());
}
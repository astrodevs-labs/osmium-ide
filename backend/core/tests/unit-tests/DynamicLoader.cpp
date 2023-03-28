/*
** backend, 2022
** DynamicLoader.cpp by 0xMemoryGrinder
*/

#include <gtest/gtest.h>
#include "utils/DynamicLoader.hpp"

TEST(DynamicLoader, SimpleLoadFailure)
{
    core::DynamicLoader loader;
    EXPECT_ANY_THROW(loader.loadHandler("dontExist.so"));
}
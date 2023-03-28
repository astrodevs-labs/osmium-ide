/*
** backend, 2022
** DynamicLoader.cpp by 0xMemoryGrinder
*/

#include <gtest/gtest.h>
#include "utils/DynamicLoader.hpp"

TEST(DynamicLoader, SimpleLoadFailure)
{
    EXPECT_ANY_THROW(core::DynamicLoader loader("invalid_path"));
}
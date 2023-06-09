cmake_minimum_required(VERSION 3.17)

include(FetchContent)
message(STATUS "Fetching zlib")
FetchContent_Declare(
        z
        GIT_REPOSITORY https://github.com/madler/zlib.git
        GIT_TAG v1.2.13
        OVERRIDE_FIND_PACKAGE
)
FetchContent_MakeAvailable(z)
message(STATUS "Fetched zlib")

add_library(z INTERFACE)
target_include_directories(z INTERFACE ${z_SOURCE_DIR} ${z_BINARY_DIR})

add_library(zlib::zlib ALIAS z)


cmake_minimum_required(VERSION 3.17)
project(backend-core)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE ICLS include/*.hpp)

add_library(backend-core ${SRCS} ${ICLS})
target_include_directories(backend-core PUBLIC include)

option(OSMIUM_TESTS_ENABLED "Enable tests" OFF)
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR} OR ${OSMIUM_TESTS_ENABLED})
    include(tests/cmake/FindGoogleTest.cmake)
    enable_testing()

    add_subdirectory(tests)
endif ()

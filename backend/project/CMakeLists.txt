cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE ICLS include/*.hpp)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(TEST_PROJECT_NO_SSL ON)

add_library(backend-project SHARED ${SRCS} ${ICLS} ${uWebSockets_SOURCES_FILES})
target_include_directories(backend-project PUBLIC include)

option(OSMIUM_TESTS_ENABLED "Enable tests" OFF)
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR} OR ${OSMIUM_TESTS_ENABLED})
    message(STATUS "Tests enabled")
    include(tests/cmake/FindGoogleTest.cmake)
    enable_testing()

    add_subdirectory(tests)
endif ()
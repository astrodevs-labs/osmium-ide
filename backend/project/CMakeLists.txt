cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE ICLS include/*.hpp)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(TEST_PROJECT_NO_SSL ON)

if (MSVC)
    foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
        string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
        set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR} )
        set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR} )
        set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR} )
    endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )
else()
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
endif()


add_library(backend-project SHARED ${SRCS} ${ICLS} ${uWebSockets_SOURCES_FILES})
target_include_directories(backend-project PUBLIC include)

option(OSMIUM_TESTS_ENABLED "Enable tests" OFF)
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR} OR ${OSMIUM_TESTS_ENABLED})
    message(STATUS "Tests enabled")
    include(tests/cmake/FindGoogleTest.cmake)
    enable_testing()

    add_subdirectory(tests)
endif ()
cmake_minimum_required(VERSION 3.17)
project(front-communication)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE ICLS include/*.hpp)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(TEST_FRONT_COMMUNICATION_NO_SSL ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

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
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#include(cmake/FindZlib.cmake)
include(cmake/FindIXWebSocket.cmake)

add_library(backend-frontCommunication SHARED ${SRCS} ${ICLS})
target_include_directories(backend-frontCommunication PUBLIC include ${ixwebsocket_INCLUDE_DIR})
target_link_libraries(backend-frontCommunication ixwebsocket)

option(OSMIUM_TESTS_ENABLED "Enable tests" OFF)
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR} OR ${OSMIUM_TESTS_ENABLED})
    message(STATUS "Tests enabled")
    include(tests/cmake/FindGoogleTest.cmake)
    enable_testing()

    add_subdirectory(tests)
endif ()

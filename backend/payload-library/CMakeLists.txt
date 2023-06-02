cmake_minimum_required(VERSION 3.17)
project(payload-library)

set(CMAKE_CXX_STANDARD 20)

set(LIBRARY_OUTPUT_PATH ..)


if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

file(GLOB_RECURSE sources "src/*.cpp" "include/*.hpp")

add_library(payload-library
        ${sources}
        )


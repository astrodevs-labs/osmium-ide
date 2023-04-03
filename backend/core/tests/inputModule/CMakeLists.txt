cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE ICLS include/*.hpp)

add_library(backend-core-tests-input-module SHARED  ${SRCS} ${ICLS})
target_include_directories(backend-core-tests-input-module PUBLIC include ../../include)

cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE ICLS *.hpp)

add_executable(backend-file-e2e-tests EXCLUDE_FROM_ALL ${SRCS} ${ICLS})
target_link_libraries(backend-file-e2e-tests PRIVATE module-tester GTest::gtest_main)
add_dependencies(backend-file-e2e-tests backend-file)
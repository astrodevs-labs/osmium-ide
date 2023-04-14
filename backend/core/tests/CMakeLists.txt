cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE UNIT_TESTS_SRCS unit-tests/*.cpp)
file(GLOB_RECURSE UNIT_TESTS_ICLS unit-tests/*.hpp)
file(GLOB_RECURSE E2E_TESTS_SRCS e2e-tests/*.cpp)
file(GLOB_RECURSE E2E_TESTS_ICLS e2e-tests/*.hpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_subdirectory(inputModule)

add_executable(backend-core-unit-tests EXCLUDE_FROM_ALL ${UNIT_TESTS_SRCS} ${UNIT_TESTS_ICLS})
target_link_libraries(backend-core-unit-tests PRIVATE backend-core GTest::gtest_main)
target_include_directories(backend-core-unit-tests PRIVATE ../include)

add_executable(backend-core-e2e-tests EXCLUDE_FROM_ALL ${E2E_TESTS_SRCS} ${E2E_TESTS_ICLS})
target_link_libraries(backend-core-e2e-tests PRIVATE backend-core GTest::gtest_main)
target_include_directories(backend-core-e2e-tests PRIVATE ../include)
add_dependencies(backend-core-e2e-tests backend-core-tests-input-module)

add_custom_target(backend-core-tests)
add_dependencies(backend-core-tests backend-core-unit-tests backend-core-e2e-tests)

include(GoogleTest)
gtest_discover_tests(backend-core-unit-tests)
gtest_discover_tests(backend-core-e2e-tests)
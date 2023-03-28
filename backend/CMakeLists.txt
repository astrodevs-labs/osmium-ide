cmake_minimum_required(VERSION 3.17)
project(backend)

set(CMAKE_CXX_STANDARD 20)
set(OSMIUM_TESTS_ENABLED ON)

set(modules "")

# subfolders for  modules
foreach(module ${modules})
    add_subdirectory(${module})
endforeach()


add_subdirectory(core)

add_executable(backend main.cpp)
target_link_libraries(backend backend-core)
foreach(module ${modules})
    add_dependencies(backend backend-${module})
endforeach()


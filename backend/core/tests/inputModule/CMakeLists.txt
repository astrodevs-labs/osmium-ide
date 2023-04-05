cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE ICLS include/*.hpp)

# c++ types list
set(types
    "int"
    "float"
    "double"
    "char"
    "bool"
    "string")

add_custom_target(backend-core-tests-input-module)

#for each type
foreach(type ${types})
    string(TOUPPER ${type} upper_type)
    #create a new target
    add_library(backend-core-tests-input-module-${type} SHARED  ${SRCS} ${ICLS})
    #set the target name
    set_target_properties(backend-core-tests-input-module-${type} PROPERTIES OUTPUT_NAME "backend-core-tests-input-module-${type}")
    #set the include directories
    target_include_directories(backend-core-tests-input-module-${type} PUBLIC include ../../include)
    #set the type
    target_compile_definitions(backend-core-tests-input-module-${type} PUBLIC "TYPE_${upper_type}")
    #add the target to the parent target
    add_dependencies(backend-core-tests-input-module backend-core-tests-input-module-${type})
endforeach()
file(GLOB_RECURSE USOCKETS_SRCS uWebSockets/uSockets/src/*.c)
file(GLOB_RECURSE USOCKETS_ICLS uWebSockets/uSockets/src/*.h)

add_library(uSockets STATIC ${USOCKETS_SRCS} ${USOCKETS_ICLS})
set_target_properties(uSockets PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(uSockets PUBLIC uWebSockets/uSockets/src)
target_link_libraries(uSockets PUBLIC ssl crypto z)

if (TEST_FRONT_COMMUNICATION_NO_SSL)
    target_compile_definitions(uSockets PUBLIC LIBUS_NO_SSL=0)
else()
    target_compile_definitions(uSockets PUBLIC LIBUS_USE_OPENSSL=1)
endif()

file(GLOB_RECURSE UWEBSOCKETS_ICLS uWebSockets/src/*.h)

add_custom_target(uWebSockets SOURCES ${UWEBSOCKETS_ICLS})
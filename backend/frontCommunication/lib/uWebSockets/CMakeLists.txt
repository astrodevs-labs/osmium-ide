include(FetchContent)

get_target_property(ZLIB_INCLUDE_DIRS z INTERFACE_INCLUDE_DIRECTORIES)

message(STATUS "Fetching uWebSockets")
FetchContent_Declare(
        uws
        GIT_REPOSITORY https://github.com/uNetworking/uWebSockets.git
        GIT_TAG v20.44.0
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
)
message(STATUS "Fetched uWebSockets")
FetchContent_GetProperties(uws)

if (NOT uws_POPULATED)
    FetchContent_Populate(uws)
endif()

add_library(uWebSockets INTERFACE)
target_include_directories(uWebSockets INTERFACE ${uws_SOURCE_DIR}/src)
message(STATUS "uWebSockets include dir: ${uws_SOURCE_DIR}/src")
message(STATUS "uWebSockets include dir: ${uws_SOURCE_DIR}/uSockets/src")
file(GLOB_RECURSE uSockets_SRCS ${uws_SOURCE_DIR}/uSockets/src/*.c)
add_library(uSockets STATIC ${uSockets_SRCS})
target_include_directories(uSockets PUBLIC ${uws_SOURCE_DIR}/uSockets/src ${ZLIB_INCLUDE_DIRS})
set_target_properties(uSockets PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(uSockets PUBLIC z uv)
add_dependencies(uSockets z)

target_link_libraries(uWebSockets INTERFACE uSockets)

#[[
file(GLOB_RECURSE USOCKETS_SRCS uWebSockets/uSockets/src/*.c)
file(GLOB_RECURSE USOCKETS_ICLS uWebSockets/uSockets/src/*.h)

add_library(uSockets STATIC ${USOCKETS_SRCS} ${USOCKETS_ICLS})
set_target_properties(uSockets PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(uSockets PUBLIC uWebSockets/uSockets/src)

if (MSVC)
    find_package(libuv CONFIG REQUIRED)
    find_package(ZLIB REQUIRED)
    target_link_libraries(uSockets PRIVATE $<IF:$<TARGET_EXISTS:uv_a>,uv_a,uv> ZLIB::ZLIB)
    target_include_directories(uSockets ${ZLIB_INCLUDE_DIRS})
else()
    target_link_libraries(uSockets PRIVATE z)
endif()

if (TEST_FRONT_COMMUNICATION_NO_SSL)
    target_compile_definitions(uSockets PUBLIC LIBUS_NO_SSL=0)
else()
    target_compile_definitions(uSockets PUBLIC LIBUS_USE_OPENSSL=1)
endif()

file(GLOB_RECURSE UWEBSOCKETS_ICLS uWebSockets/src/*.h)

add_custom_target(uWebSockets SOURCES ${UWEBSOCKETS_ICLS})]]

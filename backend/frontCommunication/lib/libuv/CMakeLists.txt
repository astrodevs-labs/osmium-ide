cmake_minimum_required(VERSION 3.17)

if (NOT TARGET uv)
    include(FetchContent)
    message(STATUS "Fetching libuv")
    FetchContent_Declare(
            uv
            GIT_REPOSITORY https://github.com/libuv/libuv.git
            GIT_TAG v1.45.0
    )
    FetchContent_MakeAvailable(uv)
    message(STATUS "Fetched libuv")
endif ()
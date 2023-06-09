cmake_minimum_required(VERSION 3.17)

if (NOT TARGET ixwebsocket)
    include(FetchContent)
    message(STATUS "Fetching IXWebSocket")

    set(USE_ZLIB OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(
            ixwebsocket
            GIT_REPOSITORY https://github.com/machinezone/IXWebSocket.git
            GIT_TAG v11.4.4
            #PATCH_COMMAND git apply "${CMAKE_CURRENT_SOURCE_DIR}/patches/IXWebSockets-zlib.patch" || echo "No patch applied"
    )
    FetchContent_MakeAvailable(ixwebsocket)
    message(STATUS "Fetched IXWebSocket")
endif ()
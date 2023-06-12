if(NOT TARGET module-tester)
    include(FetchContent)

    FetchContent_Declare(
            module-tester
            GIT_REPOSITORY https://github.com/astrodevs-labs/module-tester.git
            GIT_TAG main
    )

    FetchContent_MakeAvailable(module-tester)
endif()
FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/spurious/SDL-mirror.git
        GIT_TAG release-2.0.10
)

FetchContent_MakeAvailable(SDL2)

target_compile_definitions(SDL2-static PUBLIC SDL_MAIN_HANDLED)
cmake_minimum_required(VERSION 3.12)
project(projekcik_SDL)

set(CMAKE_CXX_STANDARD 17)
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2")

include(FetchContent)

FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/spurious/SDL-mirror.git
)

FetchContent_MakeAvailable(SDL2)

add_executable(projekcik_SDL main.cpp)
target_link_libraries(projekcik_SDL SDL2)

#FetchContent_GetProperties(SDL2)
#if(NOT SDL2_POPULATED)
#    FetchContent_Populate(SDL2)
#    add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_BINARY_DIR}/SDL2)
#    include_directories(${SDL2_SOURCE_DIR}/include)
#endif()

#link_directories(${SDL2_SOURCE_DIR})
#link_libraries(${SDL2_SOURCE_DIR})

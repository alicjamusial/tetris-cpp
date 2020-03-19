cmake_minimum_required(VERSION 3.15)
project(projekcik_SDL)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

add_subdirectory(libs)

add_executable(projekcik_SDL main.cpp)
target_link_libraries(projekcik_SDL SDL2-static gtest)

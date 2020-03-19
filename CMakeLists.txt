cmake_minimum_required(VERSION 3.15)
project(tetris)

include(FetchContent)

add_subdirectory(libs)
add_subdirectory(tests)

add_executable(tetris main.cpp)
target_link_libraries(tetris SDL2-static)
cmake_minimum_required(VERSION 3.15)

project(tetris)

include(FetchContent)

add_subdirectory(tetris)
add_subdirectory(libs)
add_subdirectory(tests)

target_link_libraries(tetris SDL2-static)
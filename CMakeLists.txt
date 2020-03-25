cmake_minimum_required(VERSION 3.15)

set(NAME tetris_project)
project(${NAME})

include(FetchContent)

add_subdirectory(tetris)
add_subdirectory(libs)
add_subdirectory(tests)

enable_testing()
cmake_minimum_required(VERSION 3.15)

set(NAME tetris)
project(${NAME})

include(FetchContent)

add_subdirectory(tetris)
add_subdirectory(libs)
add_subdirectory(tests)

enable_testing()

target_include_directories(${NAME} PRIVATE tetris/include)
target_link_libraries(${NAME} SDL2-static)

set_property(TARGET ${NAME} PROPERTY CXX_STANDARD 14)
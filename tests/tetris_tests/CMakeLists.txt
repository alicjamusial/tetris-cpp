include(GoogleTest)

add_executable(tetris_test main_test.cpp)

target_link_libraries(tetris_test PRIVATE gtest_main)

target_compile_features(tetris_test PRIVATE cxx_std_11)

gtest_discover_tests(tetris_test)
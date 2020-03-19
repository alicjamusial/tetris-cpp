add_executable(tetris_test main_test.cpp)

target_sources(tetris_test PRIVATE main_test.cpp)
target_link_libraries(tetris_test PRIVATE gtest_main)

target_compile_features(tetris_test PRIVATE cxx_std_11)

enable_testing()
add_test(
        NAME google_test
        COMMAND $<TARGET_FILE:tetris_test>
)
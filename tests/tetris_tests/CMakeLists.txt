#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tetris_test "")
target_sources(tetris_test
    PRIVATE
    main_test.cpp
    )

target_link_libraries(tetris_test
        PRIVATE
        gtest_main
        )

enable_testing()
add_test(
        NAME google_test
        COMMAND $<TARGET_FILE:tetris_test>
)
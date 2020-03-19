FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG 482ac6ee63429af2aa9c44f4e6427873fb68fb1f
)

FetchContent_GetProperties(gtest)

if(NOT gtest_POPULATED)
    FetchContent_Populate(gtest)

    add_subdirectory(
            ${gtest_SOURCE_DIR}
            ${gtest_BINARY_DIR}
    )

    foreach(_tgt gtest gtest_main gmock gmock_main)
        target_compile_options(${_tgt} PRIVATE -Wno-deprecated-declarations)
    endforeach()

endif()
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG 482ac6ee63429af2aa9c44f4e6427873fb68fb1f
)

#FetchContent_MakeAvailable(gtest)
#
#add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
#        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
#        EXCLUDE_FROM_ALL)

FetchContent_GetProperties(gtest)

if(NOT gtest_POPULATED)
    FetchContent_Populate(gtest)

    # Prevent GoogleTest from overriding our compiler/linker options
    # when building with Visual Studio
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    # Prevent GoogleTest from using PThreads
    set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

    # adds the targers: gtest, gtest_main, gmock, gmock_main
    add_subdirectory(
            ${gtest_SOURCE_DIR}
            ${gtest_BINARY_DIR}
    )


    # Silence std::tr1 warning on MSVC
#    if(MSVC)
        foreach(_tgt gtest gtest_main gmock gmock_main)
            target_compile_options(${_tgt} PRIVATE -Wno-deprecated-declarations)
#            target_compile_definitions(${_tgt}
#                    PRIVATE
#                    "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
#                    )
        endforeach()
#    endif()

endif()
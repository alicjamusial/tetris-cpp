if (NOT EXISTS "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/install_manifest.txt")
    message(FATAL_ERROR "Cannot find install manifest: \"D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/install_manifest.txt\"")
endif(NOT EXISTS "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/install_manifest.txt")

file(READ "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach (file ${files})
    message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
    execute_process(
        COMMAND C:/Program Files/JetBrains/CLion 2019.3.2/bin/cmake/win/bin/cmake.exe -E remove "$ENV{DESTDIR}${file}"
        OUTPUT_VARIABLE rm_out
        RESULT_VARIABLE rm_retval
    )
    if(NOT ${rm_retval} EQUAL 0)
        message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif (NOT ${rm_retval} EQUAL 0)
endforeach(file)


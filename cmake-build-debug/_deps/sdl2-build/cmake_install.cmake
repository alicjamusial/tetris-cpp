# Install script for directory: D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/projekcik_SDL")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-build/libSDL2d.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-build/libSDL2maind.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake"
         "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-build/CMakeFiles/Export/cmake/SDL2Targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-build/CMakeFiles/Export/cmake/SDL2Targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-build/CMakeFiles/Export/cmake/SDL2Targets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/SDL2Config.cmake"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/SDL2ConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_assert.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_atomic.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_audio.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_bits.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_blendmode.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_clipboard.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_config_android.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_config_iphoneos.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_config_macosx.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_config_minimal.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_config_os2.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_config_pandora.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_config_psp.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_config_windows.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_config_winrt.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_config_wiz.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_copying.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_cpuinfo.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_egl.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_endian.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_error.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_events.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_filesystem.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_gamecontroller.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_gesture.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_haptic.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_hints.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_joystick.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_keyboard.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_keycode.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_loadso.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_log.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_main.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_messagebox.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_metal.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_mouse.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_mutex.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_name.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_opengl.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_opengl_glext.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_opengles.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_opengles2.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_opengles2_gl2.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_opengles2_gl2ext.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_opengles2_gl2platform.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_opengles2_khrplatform.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_pixels.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_platform.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_power.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_quit.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_rect.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_render.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_revision.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_rwops.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_scancode.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_sensor.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_shape.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_stdinc.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_surface.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_system.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_syswm.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_assert.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_common.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_compare.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_crc32.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_font.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_fuzzer.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_harness.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_images.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_log.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_md5.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_memory.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_test_random.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_thread.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_timer.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_touch.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_types.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_version.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_video.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/SDL_vulkan.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/begin_code.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-src/include/close_code.h"
    "D:/Biblioteki/Dokumenty/kurs_udemy/projekcik_SDL/cmake-build-debug/_deps/sdl2-build/include/SDL_config.h"
    )
endif()


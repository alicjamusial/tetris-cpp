//
// Created by Alicja on 2020-03-20.
//
#include <cstdio>
#include <string>
#include <SDL.h>

#include "Tetris.hpp"

using namespace game;

Tetris::Tetris() {

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    showError("SDL could not initialize!");
  } else {
    //Create window
    window = SDL_CreateWindow(
        windowTitle.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screenWidth, screenHeight,
        SDL_WINDOW_SHOWN);

    if (window == nullptr) {
      showError("Window could not be created!");
    } else {
      screenSurface = SDL_GetWindowSurface(window);

      SDL_FillRect(
          screenSurface,
          nullptr,
          SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF));

      SDL_UpdateWindowSurface(window);

      while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
          /* handle your event here */

          if(event.type == SDL_QUIT)
            running = false;
        }
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Tetris::showError(const std::string& errorMsg) {
  printf("%s SDL_Error: %s\n", errorMsg.c_str(), SDL_GetError());
}

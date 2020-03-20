//
// Created by Alicja on 2020-03-20.
//
#include <cstdio>
#include <string>
#include <SDL.h>

#include "Tetris.hpp"
#include "constants.hpp"

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

      GraphicInterface graphicInterface {window};

      if (graphicInterface.getRenderer() == nullptr) {
        showError("Renderer could not be created!");
      } else {

        while (running) {
          SDL_Event event;

          while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
              running = false;
          }
          
          graphicInterface.ClearScreen();
          graphicInterface.UpdateScreen();


//          gameplay.DrawScene ();

        }
        SDL_DestroyWindow(window);
        SDL_Quit();
      }
    }
  }
}

void Tetris::showError(const std::string& errorMsg) {
  printf("%s SDL_Error: %s\n", errorMsg.c_str(), SDL_GetError());
}


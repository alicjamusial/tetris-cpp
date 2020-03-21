//
// Created by Alicja on 2020-03-06.
//

#include "GraphicInterface.hpp"
#include "SDL.h"
#include "settings.hpp"

using namespace game;

GraphicInterface::GraphicInterface(SDL_Window *window) {
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
}

GraphicInterface::~GraphicInterface() {
  SDL_DestroyRenderer(renderer);
}

void GraphicInterface::ClearScreen() {
  colorEnum boardColor = ColorBoard;
  SDL_SetRenderDrawColor(
      renderer,
      colorsMap[boardColor][0],
      colorsMap[boardColor][1],
      colorsMap[boardColor][2],
      colorsMap[boardColor][3]
      );
  SDL_RenderClear(renderer);
}


void GraphicInterface::DrawRectangle(int x, int y, int w, int h, enum colorEnum color) {
  SDL_Rect fillRect = {x, y, w, h};
  SDL_SetRenderDrawColor(
      renderer,
      colorsMap[color][0],
      colorsMap[color][1],
      colorsMap[color][2],
      colorsMap[color][3]
  );
  SDL_RenderFillRect(renderer, &fillRect);
}

void GraphicInterface::UpdateScreen() {
  SDL_RenderPresent(renderer);
}
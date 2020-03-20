//
// Created by Alicja on 2020-03-06.
//

#include "GraphicInterface.hpp"
#include "SDL.h"
#include "constants.hpp"

using namespace game;

GraphicInterface::GraphicInterface(SDL_Window *window) {
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
}

GraphicInterface::~GraphicInterface() {
  SDL_DestroyRenderer(renderer);
}

SDL_Renderer *GraphicInterface::GetRenderer() {
  return renderer;
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
//  SDL_Rect fillRect = {screenWidth / 4, screenHeight / 4, screenWidth / 2, screenHeight / 2};
//  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
//  SDL_RenderFillRect(renderer, &fillRect);
//
//  SDL_Rect outlineRect = {screenWidth / 6, screenHeight / 6, screenWidth * 2 / 3, screenHeight * 2 / 3};
//  SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
//  SDL_RenderDrawRect(renderer, &outlineRect);
//
//  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
//  SDL_RenderDrawLine(renderer, 0, screenHeight / 2, screenWidth, screenHeight / 2);
//
//  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
//  for (int i = 0; i < screenHeight; i += 4) {
//    SDL_RenderDrawPoint(renderer, screenWidth / 2, i);
//  }

  SDL_RenderPresent(renderer);
}


int GraphicInterface::Pollkey() {
  SDL_Event event;
//  while ( SDL_PollEvent(&event) )
//  {
//    switch (event.type) {
//      case SDL_KEYDOWN:
//        return event.key.keysym.sym;
//      case SDL_QUIT:
//        exit(3);
//    }
//  }
  return -1;
}

int GraphicInterface::Getkey() {
  SDL_Event event;
//  while (true)
//  {
//    SDL_WaitEvent(&event);
//    if (event.type == SDL_KEYDOWN)
//      break;
//    if (event.type == SDL_QUIT)
//      exit(3);
//  };
//  return event.key.keysym.sym;
  return -1;
}

int GraphicInterface::IsKeyDown (int pKey) {
  Uint8* mKeytable;
  int mNumkeys;
  SDL_PumpEvents();
//  mKeytable = SDL_GetKeyState(&mNumkeys);
  return mKeytable[pKey];
}



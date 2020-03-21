//
// Created by Alicja on 2020-03-06.
//

#include "GraphicInterface.hpp"
#include "SDL.h"
#include "settings.hpp"

using namespace game;

GraphicInterface::GraphicInterface(SDL_Window *window) {
  _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  InitImages();
}

GraphicInterface::~GraphicInterface() {
  SDL_DestroyTexture(_gameOverTexture);
  SDL_FreeSurface(_gameOverImage);
  SDL_DestroyTexture(_legendTexture);
  SDL_FreeSurface(_legendImage);
  SDL_DestroyRenderer(_renderer);
}

void GraphicInterface::InitImages() {
  _gameOverImage = SDL_LoadBMP("assets/game_over.bmp");
  _gameOverTexture = SDL_CreateTextureFromSurface(_renderer, _gameOverImage);
  _legendImage = SDL_LoadBMP("assets/legend.bmp");
  _legendTexture = SDL_CreateTextureFromSurface(_renderer, _legendImage);
}

void GraphicInterface::ClearScreen() {
  colorEnum boardColor = ColorBoard;
  SDL_SetRenderDrawColor(
      _renderer,
      colorsMap[boardColor][0],
      colorsMap[boardColor][1],
      colorsMap[boardColor][2],
      colorsMap[boardColor][3]
      );
  SDL_RenderClear(_renderer);
}


void GraphicInterface::DrawRectangle(int16_t x, int16_t y, int16_t w, int16_t h, enum colorEnum color) {
  SDL_Rect fillRect = {x, y, w, h};
  SDL_SetRenderDrawColor(
      _renderer,
      colorsMap[color][0],
      colorsMap[color][1],
      colorsMap[color][2],
      colorsMap[color][3]
  );
  SDL_RenderFillRect(_renderer, &fillRect);
}

void GraphicInterface::DrawGameOver() {
  SDL_RenderCopy(_renderer, _gameOverTexture, nullptr, &_gameOverImgPosition);
}

void GraphicInterface::DrawLegend() {
  SDL_RenderCopy(_renderer, _legendTexture, nullptr, &_legendImgPosition);
}

void GraphicInterface::UpdateScreen() {
  SDL_RenderPresent(_renderer);
}
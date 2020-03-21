//
// Created by Alicja on 2020-03-06.
//

#pragma once

#include <SDL.h>
#include "settings.hpp"

namespace game {

  class GraphicInterface {
  public:
    explicit GraphicInterface(SDL_Window *window);

    ~GraphicInterface();

    void DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum colorEnum pC);

    void ClearScreen();

    void UpdateScreen();

    void DrawGameOver();

  private:
    SDL_Renderer* renderer {nullptr};
    SDL_Surface* image {nullptr};
    SDL_Texture* texture {nullptr};
    SDL_Rect imgPosition = {screenWidth/2 - imgWidth/2, screenHeight/2 - imgHeight/2, imgWidth, imgHeight};
  };
}
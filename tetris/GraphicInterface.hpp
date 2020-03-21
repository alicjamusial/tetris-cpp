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

    void DrawRectangle(int16_t pX1, int16_t pY1, int16_t pX2, int16_t pY2, enum colorEnum pC);

    void ClearScreen();

    void UpdateScreen();

    void DrawGameOver();
    void DrawLegend();

  private:
    SDL_Renderer* renderer {nullptr};
    SDL_Surface* gameOverImage {nullptr};
    SDL_Texture* gameOverTexture {nullptr};
    SDL_Surface* legendImage {nullptr};
    SDL_Texture* legendTexture {nullptr};
    SDL_Rect gameOverImgPosition = {screenWidth/2 - gameOverImgWidth/2, screenHeight/2 - gameOverImgHeight/2,
                                    gameOverImgWidth, gameOverImgHeight};
    SDL_Rect legendImgPosition = {screenWidth/2 - legendImgWidth/2, legendMargin,
                                  legendImgWidth, legendImgHeight};
  };
}
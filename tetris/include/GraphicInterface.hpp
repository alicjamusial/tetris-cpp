//
// Created by Alicja on 2020-03-06.
//

#pragma once

#include "SDL.h"
#include "settings.hpp"
#include "Point.hpp"
#include <cstdint>
#include <map>
#include <vector>

namespace game
{
    class GraphicInterface
    {
    public:
        explicit GraphicInterface(SDL_Window* window);

        ~GraphicInterface();

        void InitImages();

        void DrawRectangle(Point point, int16_t h, int16_t w, ColorEnum pC);

        void ClearScreen();

        void UpdateScreen();

        void DrawGameOver();
        void DrawLegend();

    private:
        SDL_Renderer* _renderer{nullptr};
        SDL_Surface* _gameOverImage{nullptr};
        SDL_Texture* _gameOverTexture{nullptr};
        SDL_Surface* _legendImage{nullptr};
        SDL_Texture* _legendTexture{nullptr};
        SDL_Rect const _gameOverImgPosition = {screenWidth / 2 - gameOverImgWidth / 2,
                                               screenHeight / 2 - gameOverImgHeight / 2,
                                               gameOverImgWidth,
                                               gameOverImgHeight};
        SDL_Rect const _legendImgPosition = {screenWidth / 2 - legendImgWidth / 2,
                                             legendMargin,
                                             legendImgWidth,
                                             legendImgHeight};

        std::map<ColorEnum, std::vector<uint32_t>> _colorsMap;
    };
}
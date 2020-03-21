//
// Created by Alicja on 2020-03-06.
//

#include "GraphicInterface.hpp"
#include "SDL.h"
#include "settings.hpp"

using namespace game;

GraphicInterface::GraphicInterface(SDL_Window* window)
{
    _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    _colorsMap = {{ColorEnum::ColorBoard, {0x8c, 0x8a, 0x93, 0xFF}},
                  {ColorEnum::ColorPrimary, {0xd1, 0xf0, 0xb1, 0xFF}},
                  {ColorEnum::ColorThird, {0xb6, 0xcb, 0x9e, 0xFF}}};

    InitImages();
}

GraphicInterface::~GraphicInterface()
{
    SDL_DestroyTexture(_gameOverTexture);
    SDL_FreeSurface(_gameOverImage);
    SDL_DestroyTexture(_legendTexture);
    SDL_FreeSurface(_legendImage);
    SDL_DestroyRenderer(_renderer);
}

void GraphicInterface::InitImages()
{
    _gameOverImage = SDL_LoadBMP("assets/game_over.bmp");
    _gameOverTexture = SDL_CreateTextureFromSurface(_renderer, _gameOverImage);
    _legendImage = SDL_LoadBMP("assets/legend.bmp");
    _legendTexture = SDL_CreateTextureFromSurface(_renderer, _legendImage);
}

void GraphicInterface::ClearScreen()
{
    ColorEnum boardColor = ColorEnum::ColorBoard;
    SDL_SetRenderDrawColor(
        _renderer,
        _colorsMap[boardColor][0],
        _colorsMap[boardColor][1],
        _colorsMap[boardColor][2],
        _colorsMap[boardColor][3]);
    SDL_RenderClear(_renderer);
}

void GraphicInterface::DrawRectangle(int16_t x, int16_t y, int16_t w, int16_t h, ColorEnum color)
{
    SDL_Rect fillRect = {x, y, w, h};
    SDL_SetRenderDrawColor(
        _renderer, _colorsMap[color][0], _colorsMap[color][1], _colorsMap[color][2], _colorsMap[color][3]);
    SDL_RenderFillRect(_renderer, &fillRect);
}

void GraphicInterface::DrawGameOver()
{
    SDL_RenderCopy(_renderer, _gameOverTexture, nullptr, &_gameOverImgPosition);
}

void GraphicInterface::DrawLegend()
{
    SDL_RenderCopy(_renderer, _legendTexture, nullptr, &_legendImgPosition);
}

void GraphicInterface::UpdateScreen()
{
    SDL_RenderPresent(_renderer);
}
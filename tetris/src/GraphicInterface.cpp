//
// Created by Alicja on 2020-03-06.
//

#include "GraphicInterface.hpp"
#include "Board.hpp"
#include "SDL.h"
#include "settings.hpp"

using namespace game;

GraphicInterface::GraphicInterface(SDL_Window* window)
{
    _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    _colorsMap = {{ColorEnum::ColorBoard, {0x8c, 0x8a, 0x93, 0xFF}},
                  {ColorEnum::ColorPrimary, {0xd1, 0xf0, 0xb1, 0xFF}},
                  {ColorEnum::ColorThird, {0xb6, 0xcb, 0x9e, 0xFF}}};
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

void GraphicInterface::DrawBoardLines()
{
    Point pointBoard1{boardLineX1, boardLineY1};
    Point pointBoard2{boardLineX2, boardLineY2};
    DrawBoardLine(pointBoard1, boardLineWidth, boardHeight * blockSize, ColorEnum::ColorPrimary);
    DrawBoardLine(pointBoard2, boardLineWidth, boardHeight * blockSize, ColorEnum::ColorPrimary);
}

void GraphicInterface::DrawBoardLine(Point point, int16_t w, int16_t h, ColorEnum color)
{
    SDL_Rect fillRect = {point.x, point.y, w, h};
    SDL_SetRenderDrawColor(
        _renderer, _colorsMap[color][0], _colorsMap[color][1], _colorsMap[color][2], _colorsMap[color][3]);
    SDL_RenderFillRect(_renderer, &fillRect);
}

void GraphicInterface::DrawBlock(Point point, int16_t blockType)
{
    ColorEnum currentPieceColor = blockType == 2 ? ColorEnum::ColorThird : ColorEnum::ColorPrimary;

    int16_t width = blockSize - blockMargin;
    int16_t height = blockSize - blockMargin;
    SDL_Rect fillRect = {point.x, point.y, width, height};

    SDL_SetRenderDrawColor(
        _renderer,
        _colorsMap[currentPieceColor][0],
        _colorsMap[currentPieceColor][1],
        _colorsMap[currentPieceColor][2],
        _colorsMap[currentPieceColor][3]);
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
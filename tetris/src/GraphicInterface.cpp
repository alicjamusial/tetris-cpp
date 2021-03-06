//
// Created by Alicja on 2020-03-06.
//

#include "GraphicInterface.hpp"
#include "Board.hpp"
#include "SDL.h"
#include "settings.hpp"

using namespace game;

GraphicInterface::GraphicInterface(SDL_Window* window) :
    _renderer{SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer},
    _gameOverImage{GraphicInterface::SDL_LoadGameOverImage()},
    _legendImage{GraphicInterface::SDL_LoadLegendImage()},
    _gameOverTexture{GraphicInterface::SDL_LoadGameOverTexture()},
    _legendTexture{GraphicInterface::SDL_LoadLegendTexture()}
{
    _colorsMap = {{ColorEnum::ColorBoard, {0x8c, 0x8a, 0x93, 0xFF}},
                  {ColorEnum::ColorPrimary, {0xd1, 0xf0, 0xb1, 0xFF}},
                  {ColorEnum::ColorThird, {0xb6, 0xcb, 0x9e, 0xFF}},
                  {ColorEnum::ColorSpecial, {0xa1, 0x3b, 0x69, 0xFF}}};

    _piecesColorsMap = {{NormalPiece, ColorEnum::ColorPrimary},
                        {RotationPiece, ColorEnum::ColorThird},
                        {SpecialPiece, ColorEnum::ColorSpecial}};
}

std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> GraphicInterface::SDL_LoadGameOverImage()
{
    char* path = SDL_GetBasePath();
    std::string gameOverImg = "assets\\game_over.bmp";
    std::string gameOverPath = std::string(path) + gameOverImg;
    SDL_Surface* gameOverSurface = SDL_LoadBMP(gameOverPath.c_str());
    return {gameOverSurface, SDL_FreeSurface};
}

std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> GraphicInterface::SDL_LoadLegendImage()
{
    char* path = SDL_GetBasePath();
    std::string legendImg = "assets\\legend.bmp";
    std::string legendPath = std::string(path) + legendImg;
    SDL_Surface* legendSurface = SDL_LoadBMP(legendPath.c_str());
    return {legendSurface, SDL_FreeSurface};
}

std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> GraphicInterface::SDL_LoadGameOverTexture()
{
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), _gameOverImage.get());
    return {texture, SDL_DestroyTexture};
}

std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> GraphicInterface::SDL_LoadLegendTexture()
{
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), _legendImage.get());
    return {texture, SDL_DestroyTexture};
}

void GraphicInterface::ClearScreen()
{
    ColorEnum boardColor = ColorEnum::ColorBoard;
    SDL_SetRenderDrawColor(
        _renderer.get(),
        _colorsMap[boardColor][0],
        _colorsMap[boardColor][1],
        _colorsMap[boardColor][2],
        _colorsMap[boardColor][3]);
    SDL_RenderClear(_renderer.get());
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
    SDL_Rect fillRect = {point.GetX(), point.GetY(), w, h};
    SDL_SetRenderDrawColor(
        _renderer.get(), _colorsMap[color][0], _colorsMap[color][1], _colorsMap[color][2], _colorsMap[color][3]);
    SDL_RenderFillRect(_renderer.get(), &fillRect);
}

void GraphicInterface::DrawBlock(Point point, int16_t blockType)
{
    ColorEnum currentPieceColor = _piecesColorsMap[blockType];

    int16_t width = blockSize - blockMargin;
    int16_t height = blockSize - blockMargin;
    SDL_Rect fillRect = {point.GetX(), point.GetY(), width, height};

    SDL_SetRenderDrawColor(
        _renderer.get(),
        _colorsMap[currentPieceColor][0],
        _colorsMap[currentPieceColor][1],
        _colorsMap[currentPieceColor][2],
        _colorsMap[currentPieceColor][3]);
    SDL_RenderFillRect(_renderer.get(), &fillRect);
}

void GraphicInterface::DrawGameOver()
{
    SDL_RenderCopy(_renderer.get(), _gameOverTexture.get(), nullptr, &_gameOverImgPosition);
}

void GraphicInterface::DrawLegend()
{
    SDL_RenderCopy(_renderer.get(), _legendTexture.get(), nullptr, &_legendImgPosition);
}

void GraphicInterface::UpdateScreen()
{
    SDL_RenderPresent(_renderer.get());
}
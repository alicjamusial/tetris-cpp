//
// Created by Alicja on 2020-03-20.
//
#include <SDL.h>

#include "Board.hpp"
#include "Gameplay.hpp"
#include "GraphicInterface.hpp"
#include "Tetris.hpp"
#include "settings.hpp"

using namespace game;

Tetris::~Tetris()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Tetris::GameInit()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw std::runtime_error("SDL could not initialize!");
    }
    _window = SDL_CreateWindow(
        _windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

    if(_window == nullptr)
    {
        throw std::runtime_error("Window could not be created!");
    }
}

void Tetris::GameRun()
{
    Board board;
    GraphicInterface graphicInterface{_window};
    Gameplay gameplay(&board, &graphicInterface);

    board.CreateBoard();
    graphicInterface.InitImages();
    gameplay.InitGameplay();

    float time1 = SDL_GetTicks();
    float time2;

    while(_running)
    {
        graphicInterface.ClearScreen();
        gameplay.DrawScene();
        graphicInterface.UpdateScreen();

        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_KEYDOWN)
            {
                gameplay.CallAction(event.key.keysym.sym);
            }
            if(event.type == SDL_QUIT)
            {
                _running = false;
            }
        }

        time2 = SDL_GetTicks();

        if((time2 - time1) > timeInterval)
        {
            gameplay.Fall();
            time1 = SDL_GetTicks();
        }
    }
}
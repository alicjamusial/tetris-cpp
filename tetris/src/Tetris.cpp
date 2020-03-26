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

Tetris::Tetris() :
    _window{SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN),
            SDL_DestroyWindow}
{
}

Tetris::~Tetris()
{
    SDL_Quit();
}

void Tetris::GameInit()
{
    if(_window == nullptr)
    {
        throw std::runtime_error("Window could not be created!");
    }
}

void Tetris::GameRun()
{
    GraphicInterface graphicInterface{_window.get()};
    Gameplay gameplay(graphicInterface);

    gameplay.InitGameplay();

    float time1 = SDL_GetTicks();

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

        float time2 = SDL_GetTicks();

        if((time2 - time1) > timeInterval)
        {
            gameplay.Fall();
            time1 = SDL_GetTicks();
        }
    }
}
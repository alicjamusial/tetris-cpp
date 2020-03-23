//
// Created by Alicja on 2020-03-20.
//
#include <SDL.h>
#include <cstdio>
#include <string>

#include "Tetris.hpp"
#include "Board.hpp"
#include "Gameplay.hpp"
#include "GraphicInterface.hpp"
#include "settings.hpp"

using namespace game;

Tetris::Tetris()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        showError("SDL could not initialize!");
    }
    else
    {
        _window = SDL_CreateWindow(
            _windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

        if(_window == nullptr)
        {
            showError("Window could not be created!");
        }
        else
        {
            GraphicInterface graphicInterface{_window};
            Board board;
            Gameplay gameplay(&board, &graphicInterface);

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
                        uint16_t key = event.key.keysym.sym;
                        switch(key)
                        {
                            case(SDLK_d):
                                gameplay.MoveRight();
                                break;

                            case(SDLK_a):
                                gameplay.MoveLeft();
                                break;

                            case(SDLK_s):
                                gameplay.MoveDown();
                                break;

                            case(SDLK_x):
                                gameplay.MoveBottom();
                                break;

                            case(SDLK_z):
                                gameplay.Rotate();
                                break;

                            case(SDLK_r):
                                gameplay.RestartGame();
                                break;

                            default:
                                break;
                        }
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
            SDL_DestroyWindow(_window);
            SDL_Quit();
        }
    }
}

void Tetris::showError(const std::string& errorMsg)
{
    printf("%s SDL_Error: %s\n", errorMsg.c_str(), SDL_GetError());
}

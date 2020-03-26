//
// Created by Alicja on 2020-03-20.
//
#pragma once
#include "SDL.h"
#include <memory>
#include <string>

namespace game
{
    class Tetris
    {
    public:
        Tetris();
        ~Tetris();

        void GameInit();
        void GameRun();

    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;
        bool _running{true};
    };
}

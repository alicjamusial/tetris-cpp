//
// Created by Alicja on 2020-03-20.
//
#pragma once
#include "SDL.h"
#include <string>

namespace game
{
    class Tetris
    {
    public:
        ~Tetris();

        void GameInit();
        void GameRun();

    private:
        std::string _windowTitle{"Tetris"};

        bool _running{true};
        SDL_Window* _window{nullptr};
    };
}

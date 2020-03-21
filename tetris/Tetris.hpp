//
// Created by Alicja on 2020-03-20.
//
#pragma once
#include "Board.hpp"
#include "Gameplay.hpp"
#include "GraphicInterface.hpp"
#include "PieceDefinition.hpp"
#include <SDL.h>
#include <cstdint>
#include <string>

namespace game
{
    class Tetris
    {
    public:
        Tetris();

        static void showError(const std::string& errorMsg);

    private:
        std::string _windowTitle{"Tetris"};

        bool _running{true};
        SDL_Window* _window{nullptr};
    };
}

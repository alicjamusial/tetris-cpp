//
// Created by Alicja on 2020-03-20.
//
#pragma once
#include <string>
#include <cstdint>
#include <SDL.h>
#include "GraphicInterface.hpp"
#include "PieceDefinition.hpp"
#include "Board.hpp"
#include "Gameplay.hpp"

namespace game {
  class Tetris {
  public:
    Tetris();

    static void showError(const std::string& errorMsg);

  private:
    std::string _windowTitle {"Tetris"};

    bool _running {true};
    SDL_Window* _window {nullptr};
  };
}

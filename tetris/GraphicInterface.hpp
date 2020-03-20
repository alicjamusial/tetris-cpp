//
// Created by Alicja on 2020-03-06.
//

#pragma once

#include <SDL.h>

namespace game {

  enum color {
    BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX
  };

  class GraphicInterface {
  public:
    GraphicInterface(SDL_Window *window);

    ~GraphicInterface();

    void InitWindow(SDL_Window* window);

    SDL_Renderer* GetRenderer();

    void DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC);

    void ClearScreen();

    int GetScreenHeight();

    int InitGraph();

    int Pollkey();

    int Getkey();

    int IsKeyDown(int pKey);

    void UpdateScreen();

  private:
    SDL_Renderer* renderer {nullptr};
  };
}
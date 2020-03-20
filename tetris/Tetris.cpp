//
// Created by Alicja on 2020-03-20.
//
#include <cstdio>
#include <string>
#include <SDL.h>

#include "Tetris.hpp"
#include "settings.hpp"

using namespace game;

Tetris::Tetris() {

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    showError("SDL could not initialize!");
  } else {
    //Create window
    window = SDL_CreateWindow(
        windowTitle.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screenWidth, screenHeight,
        SDL_WINDOW_SHOWN);

    if (window == nullptr) {
      showError("Window could not be created!");
    } else {

      Piece piece;
      GraphicInterface graphicInterface {window};
      Board board {&piece};
      Gameplay gameplay(&board, &piece, &graphicInterface);

      time1 = SDL_GetTicks();

      while (running) {

        graphicInterface.ClearScreen();
        gameplay.DrawScene();
        graphicInterface.UpdateScreen();

        SDL_Event event;

        while (SDL_PollEvent(&event)) {
          if (event.type == SDL_KEYDOWN) {
            uint16_t key = event.key.keysym.sym;
            switch (key) {
              case (SDLK_d): {
                if (board.IsPossibleMovement(gameplay.mPosX + 1, gameplay.mPosY, gameplay.mPiece, gameplay.mRotation)) {
                  gameplay.mPosX++;
                }
                break;
              }

              case (SDLK_a): {
                if (board.IsPossibleMovement(gameplay.mPosX - 1, gameplay.mPosY, gameplay.mPiece, gameplay.mRotation)) {
                  gameplay.mPosX--;
                }
                break;
              }

              case (SDLK_s): {
                if (board.IsPossibleMovement(gameplay.mPosX, gameplay.mPosY + 1, gameplay.mPiece, gameplay.mRotation)) {
                  gameplay.mPosY++;
                }
                break;
              }

              case (SDLK_x): {
                while (board.IsPossibleMovement(gameplay.mPosX, gameplay.mPosY, gameplay.mPiece, gameplay.mRotation)) {
                  gameplay.mPosY++;
                }

                board.StorePiece(gameplay.mPosX, gameplay.mPosY - 1, gameplay.mPiece, gameplay.mRotation);

                board.DeletePossibleLines();

                if (board.IsGameOver())
                {
                  // mIO.Getkey();
                  // exit(0);
                  // todo: gameover
                }

                gameplay.CreateNewPiece();

                break;
              }
              case (SDLK_z): {
                if (board.IsPossibleMovement(gameplay.mPosX, gameplay.mPosY, gameplay.mPiece, (gameplay.mRotation + 1) % 4)) {
                  gameplay.mRotation = (gameplay.mRotation + 1) % 4;
                }
                break;
              }

              default:
                break;
            }
          }
          if (event.type == SDL_QUIT) {
            running = false;
          }
        }

        time2 = SDL_GetTicks();

        if ((time2 - time1) > timeInterval) {
          if (board.IsPossibleMovement(gameplay.mPosX, gameplay.mPosY + 1, gameplay.mPiece, gameplay.mRotation)) {
            gameplay.mPosY++;
          } else {
            board.StorePiece(gameplay.mPosX, gameplay.mPosY, gameplay.mPiece, gameplay.mRotation);

            board.DeletePossibleLines();

            if (board.IsGameOver())
            {
//              mIO.Getkey();
//              exit(0);
            }

            gameplay.CreateNewPiece();
          }

          time1 = SDL_GetTicks();
        }

      }
      SDL_DestroyWindow(window);
      SDL_Quit();
    }
  }
}

void Tetris::showError(const std::string& errorMsg) {
  printf("%s SDL_Error: %s\n", errorMsg.c_str(), SDL_GetError());
}


//
// Created by Alicja on 2020-03-06.
//

#pragma once
#include <string>
#include <cstdint>
#include <ctime>
#include "Board.hpp"
#include "GraphicInterface.hpp"
#include "Piece.hpp"

namespace game {

  enum GameState {Game, GameOver};

  class Gameplay {
  public:
    Gameplay(Board *pBoard, Piece *pPieces, GraphicInterface *pGraphicInterface);

    void DrawScene();
    void CreateNewPiece();

    // current falling piece
    int16_t mPosX{}, mPosY{};
    int16_t mPiece{}, mRotation{};

    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void MoveBottom();
    void Rotate();
    void Fall();

    void RestartGame();

  private:
    GameState gameState {Game};

    int16_t mNextPosX{}, mNextPosY{};
    int16_t mNextPiece{}, mNextRotation{};

    Board *board;
    Piece *pieces;
    GraphicInterface *graphicInterface;

    void InitGameplay();

    void DrawPiece(int16_t pX, int16_t pY, int16_t pPiece, int16_t pRotation);

    void DrawBoardAndLegend();

    void CheckIfGameOver();

    void StorePiece();

    static int16_t GetRand(int16_t max);
  };
}

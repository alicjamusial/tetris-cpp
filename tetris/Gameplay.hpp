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
  class Gameplay {
  public:
    bool gameOver {false};

    Gameplay(Board *pBoard, Piece *pPieces, GraphicInterface *pGraphicInterface);

    void DrawScene();
    void CreateNewPiece();

    // current falling piece
    int mPosX{}, mPosY{};
    int mPiece{}, mRotation{};

    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void MoveBottom();
    void Rotate();
    void Fall();

    void RestartGame();

  private:
    int mNextPosX{}, mNextPosY{};
    int mNextPiece{}, mNextRotation{};

    Board *board;
    Piece *pieces;
    GraphicInterface *graphicInterface;

    void InitGameplay();

    void DrawPiece(int pX, int pY, int pPiece, int pRotation);

    void DrawBoard();

    void CheckIfGameOver();

    void StorePiece();

    static int GetRand(int max);
  };
}

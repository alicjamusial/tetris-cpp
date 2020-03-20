//
// Created by Alicja on 2020-03-04.
//
#pragma once

#include "Piece.hpp"
#include "settings.hpp"

namespace game {
  class Board {
  public:
    Board();

    Board(Piece *pPieces);

    int GetXPosInPixels(int pPos);

    int GetYPosInPixels(int pPos);

    bool IsFreeBlock(int pX, int pY);

    bool IsPossibleMovement(int pX, int pY, int pPiece, int pRotation);

    void StorePiece(int pX, int pY, int pPiece, int pRotation);

    void DeletePossibleLines();

    bool IsGameOver();

  private:
    enum {
      POS_FREE, POS_FILLED
    };
    Piece *mPieces;
    int mScreenHeight;
    int mBoard[boardWidth][boardHeight];

    void InitBoard();

    void DeleteLine(int pY);
  };

}

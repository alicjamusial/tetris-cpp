//
// Created by Alicja on 2020-03-04.
//
#pragma once

#include "Piece.hpp"
#include "settings.hpp"

namespace game {
  class Board {
  public:
    Board(Piece *pPieces);

    static int GetXPosInPixels(int pPos);

    static int GetYPosInPixels(int pPos);

    bool IsFreeBlock(int pX, int pY);

    bool IsPossibleMovement(int pX, int pY, int pPiece, int pRotation);

    void StorePiece(int pX, int pY, int pPiece, int pRotation);

    void DeletePossibleLines();

    bool IsGameOver();

    void Restart();

  private:
    enum {
      POS_FREE, POS_FILLED
    };

    Piece *boardPieces;
    int boardFields[boardWidth][boardHeight]{};

    void InitBoard();

    void DeleteLine(int pY);
  };

}

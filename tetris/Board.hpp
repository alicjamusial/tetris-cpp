//
// Created by Alicja on 2020-03-04.
//
#pragma once

#include "PieceDefinition.hpp"
#include "settings.hpp"

namespace game {
  class Board {
  public:
    Board();

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

    int boardFields[boardWidth][boardHeight]{};

    void InitBoard();

    void DeleteLine(int pY);
  };

}

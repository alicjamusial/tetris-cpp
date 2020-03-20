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

#define WAIT_TIME 700

namespace game {
  class Gameplay {
  public:
    Gameplay(Board *pBoard, Piece *pPieces, GraphicInterface *pGraphicInterface);

    void DrawScene();

    void CreateNewPiece();

    // params for current falling piece
    int mPosX, mPosY;
    int mPiece, mRotation;

  private:
    int mScreenHeight;
    int mNextPosX, mNextPosY;
    int mNextPiece, mNextRotation;

    Board *mBoard;
    Piece *mPieces;
    GraphicInterface *mGraphicInterface;

    int GetRand(int pA, int pB);

    void InitGameplay();

    void DrawPiece(int pX, int pY, int pPiece, int pRotation);

    void DrawBoard();
  };
}

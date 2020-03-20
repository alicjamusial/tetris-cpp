//
// Created by Alicja on 2020-03-06.
//

#include <cstdlib>
#include "Gameplay.hpp"
#include "constants.hpp"

using namespace game;

Gameplay::Gameplay(Board *pBoard, Piece *pPieces, GraphicInterface *pGraphicInterface)
{
  board = pBoard;
  pieces = pPieces;
  mGraphicInterface = pGraphicInterface;

  InitGameplay();
}

int Gameplay::GetRand(int pA, int pB) {
  return rand() % (pB - pA + 1) + pA;
}

void Gameplay::InitGameplay() {
  srand((unsigned int) time(NULL));

  mPiece = GetRand(0, 6);
  mRotation = GetRand(0, 3);
  mPosX = (boardWidth / 2) + pieces->GetXInitialPosition(mPiece, mRotation);
  mPosY = pieces->GetYInitialPosition(mPiece, mRotation);

  mNextPiece = GetRand(0, 6);
  mNextRotation = GetRand(0, 3);
  mNextPosX = boardWidth + 5;
  mNextPosY = 5;
}

void Gameplay::CreateNewPiece() {
  mPiece = mNextPiece;
  mRotation = mNextRotation;
  mPosX = (boardWidth / 2) + pieces->GetXInitialPosition(mPiece, mRotation);
  mPosY = pieces->GetYInitialPosition(mPiece, mRotation);

  mNextPiece = GetRand(0, 6);
  mNextRotation = GetRand(0, 3);
}

void Gameplay::DrawPiece (int pX, int pY, int pPiece, int pRotation) {
  colorEnum mColor;

  int mPixelsX = board->GetXPosInPixels(pX);
  int mPixelsY = board->GetYPosInPixels(pY);

  for (int i = 0; i < pieceBlocks; i++) {
    for (int j = 0; j < pieceBlocks; j++) {
      switch (pieces->GetBlockType(pPiece, pRotation, j, i))
      {
        case 1: mColor = ColorPrimary; break;
        case 2: mColor = ColorSecondary; break;
      }

      if (pieces->GetBlockType (pPiece, pRotation, j, i) != 0) {
        mGraphicInterface->DrawRectangle(
            mPixelsX + i * blockSize,
            mPixelsY + j * blockSize,
            blockSize,
            blockSize,
            mColor);
      }
    }
  }
}

void Gameplay::DrawBoard() {

  mGraphicInterface->DrawRectangle(boardLineX1, boardLineY1, boardLineWidth, boardHeight * blockSize, ColorPrimary);
  mGraphicInterface->DrawRectangle(boardLineX2, boardLineY2, boardLineWidth, boardHeight * blockSize, ColorPrimary);

  for (int i = 0; i < boardWidth; i++) {
    for (int j = 0; j < boardHeight; j++) {
      if (!board->IsFreeBlock(i, j)) {
        mGraphicInterface->DrawRectangle(
            boardLineX1 + (i * blockSize) + boardLineWidth + blockMargin,
            boardLineY1 + (j * blockSize),
            blockSize - blockMargin,
            blockSize - blockMargin,
            ColorThird);
      }
    }
  }
}

void Gameplay::DrawScene() {
  DrawBoard();
  DrawPiece(mPosX, mPosY, mPiece, mRotation);
  DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
}
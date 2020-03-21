//
// Created by Alicja on 2020-03-06.
//

#include <cstdlib>
#include "Gameplay.hpp"
#include "settings.hpp"

using namespace game;

Gameplay::Gameplay(Board *pBoard, Piece *pPieces, GraphicInterface *pGraphicInterface)
{
  board = pBoard;
  pieces = pPieces;
  mGraphicInterface = pGraphicInterface;

  InitGameplay();
}

int Gameplay::GetRand(int max) {
  return rand() % max + 1;
}

void Gameplay::InitGameplay() {
  srand((unsigned int) time(nullptr));

  mPiece = GetRand(6);
  mRotation = GetRand(3);
  mPosX = halfBoardWidth + pieces->GetXInitialPosition(mPiece, mRotation);
  mPosY = pieces->GetYInitialPosition(mPiece, mRotation);

  mNextPiece = GetRand(6);
  mNextRotation = GetRand(3);
  mNextPosX = boardWidth + 5;
  mNextPosY = 5;
}

void Gameplay::CreateNewPiece() {
  mPiece = mNextPiece;
  mRotation = mNextRotation;
  mPosX = halfBoardWidth + pieces->GetXInitialPosition(mPiece, mRotation);
  mPosY = pieces->GetYInitialPosition(mPiece, mRotation);

  mNextPiece = GetRand(6);
  mNextRotation = GetRand(3);
}

void Gameplay::DrawPiece (int pX, int pY, int pPiece, int pRotation) {

  int mPixelsX = board->GetXPosInPixels(pX);
  int mPixelsY = board->GetYPosInPixels(pY);

  for (int i = 0; i < pieceBlocks; i++) {
    for (int j = 0; j < pieceBlocks; j++) {

      colorEnum pieceColor = pieces->GetBlockType(pPiece, pRotation, j, i) == RotationPiece ? ColorThird : ColorPrimary;

      if (pieces->GetBlockType(pPiece, pRotation, j, i) != Blank) {
        mGraphicInterface->DrawRectangle(
            mPixelsX + (i * blockSize) + boardLineWidth + blockMargin,
            mPixelsY + j * blockSize,
            blockSize - blockMargin,
            blockSize - blockMargin,
            pieceColor);
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
            ColorPrimary);
      }
    }
  }
}

void Gameplay::DrawScene() {
  DrawBoard();
  DrawPiece(mPosX, mPosY, mPiece, mRotation);
  DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
}
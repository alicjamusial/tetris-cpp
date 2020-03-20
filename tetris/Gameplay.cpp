//
// Created by Alicja on 2020-03-06.
//

#include <cstdlib>
#include "Gameplay.hpp"
#include "constants.hpp"

using namespace game;

Gameplay::Gameplay(Board *pBoard, Piece *pPieces, GraphicInterface *pGraphicInterface)
{
  mBoard = pBoard;
  mPieces = pPieces;
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
  mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
  mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

  mNextPiece = GetRand(0, 6);
  mNextRotation = GetRand(0, 3);
  mNextPosX = BOARD_WIDTH + 5;
  mNextPosY = 5;
}

void Gameplay::CreateNewPiece() {
  mPiece = mNextPiece;
  mRotation = mNextRotation;
  mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
  mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

  mNextPiece = GetRand(0, 6);
  mNextRotation = GetRand(0, 3);
}

void Gameplay::DrawPiece (int pX, int pY, int pPiece, int pRotation) {
  colorEnum mColor;

  int mPixelsX = mBoard->GetXPosInPixels(pX);
  int mPixelsY = mBoard->GetYPosInPixels(pY);

  for (int i = 0; i < PIECE_BLOCKS; i++) {
    for (int j = 0; j < PIECE_BLOCKS; j++) {
      switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
      {
        case 1: mColor = PRIMARY; break;
        case 2: mColor = SECONDARY; break;
      }

      if (mPieces->GetBlockType (pPiece, pRotation, j, i) != 0) {
        mGraphicInterface->DrawRectangle(mPixelsX + i * BLOCK_SIZE, mPixelsY + j * BLOCK_SIZE,
            (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1, (mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, mColor);
      }
    }
  }
}

void Gameplay::DrawBoard() {
  int x1 = screenWidth / 2 - (BOARD_WIDTH * BLOCK_SIZE);
  int y1 = screenHeight - (BOARD_HEIGHT * BLOCK_SIZE);

  int x2 = screenWidth / 2 + (BOARD_WIDTH * BLOCK_SIZE);
  int y2 = screenHeight - (BOARD_HEIGHT * BLOCK_SIZE);

  mGraphicInterface->DrawRectangle(x1, y1, BOARD_LINE_WIDTH, BOARD_HEIGHT * BLOCK_SIZE, PRIMARY);
  mGraphicInterface->DrawRectangle(x2, y2, BOARD_LINE_WIDTH, BOARD_HEIGHT * BLOCK_SIZE, PRIMARY);

//  mX1 += 1;
//  for (int i = 0; i < BOARD_WIDTH; i++) {
//    for (int j = 0; j < BOARD_HEIGHT; j++) {
//      if (!mBoard->IsFreeBlock(i, j))
//        mGraphicInterface->DrawRectangle(mX1 + i * BLOCK_SIZE, mY + j * BLOCK_SIZE, (mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
//            (mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, RED);
//    }
//  }
}

void Gameplay::DrawScene() {
  DrawBoard();
//  DrawPiece(mPosX, mPosY, mPiece, mRotation);
//  DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
}
//
// Created by Alicja on 2020-03-04.
//

#include "Board.hpp"
#include "constants.hpp"

using namespace game;

Board::Board() {
  InitBoard();
}

Board::Board(Piece *pPieces) {
  mScreenHeight = screenHeight;
  mPieces = pPieces;
  InitBoard();
}


void Board::InitBoard() {
  for (int i = 0; i < boardWidth; i++) {
    for (int j = 0; j < boardHeight; j++) {
      mBoard[i][j] = POS_FREE;
    }
  }
}

void Board::StorePiece(int pX, int pY, int pPiece, int pRotation) {
  for (int i1 = pX, i2 = 0; i1 < pX + pieceBlocks; i1++, i2++) {
    for (int j1 = pY, j2 = 0; j1 < pY + pieceBlocks; j1++, j2++) {
      // Store blocks that are not holes
//      if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) {
//        mBoard[i1][j1] = POS_FILLED;
//      }
    }
  }
}

bool Board::IsGameOver() {
  for (int i = 0; i < boardWidth; i++) {
    if (mBoard[i][0] == POS_FILLED) {
      return true;
    }
  }
  return false;
}

void Board::DeleteLine(int pY) {
  for (int j = pY; j > 0; j--) {
    for (int i = 0; i < boardWidth; i++) {
      mBoard[i][j] = mBoard[i][j-1];
    }
  }
}

void Board::DeletePossibleLines() {
  for (int j = 0; j < boardHeight; j++) {
    int i = 0;
    while (i < boardWidth) {
      if (mBoard[i][j] != POS_FILLED) {
        break;
      }
      i++;
    }
    if (i == boardWidth) {
      DeleteLine(j);
    }
  }
}

bool Board::IsFreeBlock(int pX, int pY) {
  return mBoard[pX][pY] == POS_FREE;
}

int Board::GetXPosInPixels(int pPos) {
  return boardLineX1 + (pPos * blockSize);
}

int Board::GetYPosInPixels(int pPos) {
  return boardLineY1 + (pPos * blockSize);
}

bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation) {
  for (int i1 = pX, i2 = 0; i1 < pX + pieceBlocks; i1++, i2++) {
    for (int j1 = pY, j2 = 0; j1 < pY + pieceBlocks; j1++, j2++)
    {
      if (i1 < 0 || i1 > boardWidth  - 1 || j1 > boardHeight - 1) {
//        if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) {
//          return false;
//        }
      }
      if (j1 >= 0) {
//        if ((mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) && (!IsFreeBlock (i1, j1))) {
//          return false;
//        }
      }
    }
  }
  return true;
}
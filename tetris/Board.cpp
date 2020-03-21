//
// Created by Alicja on 2020-03-04.
//

#include "Board.hpp"
#include "settings.hpp"

using namespace game;

Board::Board() {
  InitBoard();
}

void Board::Restart() {
  InitBoard();
}


void Board::InitBoard() {
  for (auto &i : boardFields) {
    for (int &j : i) {
      j = POS_FREE;
    }
  }
}

void Board::StorePiece(int pX, int pY, int pPiece, int pRotation) {
  for (int i1 = pX, i2 = 0; i1 < pX + pieceBlocks; i1++, i2++) {
    for (int j1 = pY, j2 = 0; j1 < pY + pieceBlocks; j1++, j2++) {
      if (PieceDefinition::GetBlockType(pPiece, pRotation, j2, i2) != Blank) {
        boardFields[i1][j1] = POS_FILLED;
      }
    }
  }
}

bool Board::IsGameOver() {
  for (auto &boardField : boardFields) {
    if (boardField[0] == POS_FILLED) {
      return true;
    }
  }
  return false;
}

void Board::DeleteLine(int pY) {
  for (int j = pY; j > 0; j--) {
    for (auto &boardField : boardFields) {
      boardField[j] = boardField[j-1];
    }
  }
}

void Board::DeletePossibleLines() {
  for (int j = 0; j < boardHeight; j++) {
    int i = 0;
    while (i < boardWidth) {
      if (boardFields[i][j] != POS_FILLED) {
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
  return boardFields[pX][pY] == POS_FREE;
}

bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation) {
  for (int i1 = pX, i2 = 0; i1 < pX + pieceBlocks; i1++, i2++) {
    for (int j1 = pY, j2 = 0; j1 < pY + pieceBlocks; j1++, j2++)
    {
      if (i1 < 0 || i1 > boardWidth  - 1 || j1 > boardHeight - 1) {
        if (PieceDefinition::GetBlockType(pPiece, pRotation, j2, i2) != Blank) {
          return false;
        }
      }
      if (j1 >= 0) {
        if ((PieceDefinition::GetBlockType(pPiece, pRotation, j2, i2) != Blank) && (!IsFreeBlock(i1, j1))) {
          return false;
        }
      }
    }
  }
  return true;
}

int Board::GetXPosInPixels(int pPos) {
  return boardLineX1 + (pPos * blockSize);
}

int Board::GetYPosInPixels(int pPos) {
  return boardLineY1 + (pPos * blockSize);
}
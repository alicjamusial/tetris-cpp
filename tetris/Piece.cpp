//
// Created by Alicja on 2020-03-02.
//

#include "Piece.hpp"

using namespace game;

int Piece::GetBlockType(int pPiece, int pRotation, int pX, int pY) {
  return mPiecesTypes[pPiece][pRotation][pX][pY];
}

int Piece::GetXInitialPosition(int pPiece, int pRotation) {
  return mPiecesInitialPosition[pPiece][pRotation][0];
}

int Piece::GetYInitialPosition(int pPiece, int pRotation) {
  return mPiecesInitialPosition[pPiece][pRotation][1];
}
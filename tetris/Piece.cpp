//
// Created by Alicja on 2020-03-02.
//

#include "Piece.hpp"

using namespace game;

int16_t Piece::GetBlockType(int16_t pPiece, int16_t pRotation, int16_t pX, int16_t pY) {
  return mPiecesTypes[pPiece][pRotation][pX][pY];
}

int16_t Piece::GetXInitialPosition(int16_t pPiece, int16_t pRotation) {
  return mPiecesInitialPosition[pPiece][pRotation][0];
}

int16_t Piece::GetYInitialPosition(int16_t pPiece, int16_t pRotation) {
  return mPiecesInitialPosition[pPiece][pRotation][1];
}
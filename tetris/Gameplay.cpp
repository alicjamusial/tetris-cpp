//
// Created by Alicja on 2020-03-06.
//

#include <cstdlib>
#include "Gameplay.hpp"
#include "settings.hpp"

using namespace game;

Gameplay::Gameplay(Board *pBoard, GraphicInterface *pGraphicInterface) {
  board = pBoard;
  graphicInterface = pGraphicInterface;

  InitGameplay();
}

void Gameplay::InitGameplay() {
  srand((unsigned int) time(nullptr));

  // Init current falling piece
  mPiece = GetRand(6);
  mRotation = GetRand(3);
  mPosX = halfBoardWidth + PieceDefinition::GetXInitialPosition(mPiece, mRotation);
  mPosY = PieceDefinition::GetYInitialPosition(mPiece, mRotation);

  // Init next piece next to board
  mNextPiece = GetRand(6);
  mNextRotation = GetRand(3);
  mNextPosX = boardWidth + nextPieceMargin;
  mNextPosY = nextPieceMargin;
}

void Gameplay::MoveRight() {
  if (board->IsPossibleMovement(mPosX + 1, mPosY, mPiece, mRotation)) {
    mPosX++;
  }
}

void Gameplay::MoveLeft() {
  if (board->IsPossibleMovement(mPosX - 1, mPosY, mPiece, mRotation)) {
    mPosX--;
  }
}

void Gameplay::MoveDown() {
  if (board->IsPossibleMovement(mPosX, mPosY + 1, mPiece, mRotation)) {
    mPosY++;
  }
}

void Gameplay::MoveBottom() {
  while (board->IsPossibleMovement(mPosX, mPosY + 1, mPiece, mRotation)) {
    mPosY++;
  }
  StorePiece();
}

void Gameplay::Rotate() {
  if (board->IsPossibleMovement(mPosX, mPosY, mPiece, (mRotation + 1) % 4)) {
    mRotation = (mRotation + 1) % 4;
  }
}

void Gameplay::Fall() {
  if (gameState == Game && board->IsPossibleMovement(mPosX, mPosY + 1, mPiece, mRotation)) {
    mPosY++;
  } else {
    StorePiece();
  }
}

void Gameplay::StorePiece() {
  board->StorePiece(mPosX, mPosY, mPiece, mRotation);
  board->DeletePossibleLines();

  CheckIfGameOver();
  CreateNewPiece();
}

void Gameplay::CheckIfGameOver() {
  if (board->IsGameOver()) {
    gameState = GameOver;
  }
}

void Gameplay::RestartGame() {
  gameState = Game;
  board->Restart();
  CreateNewPiece();
}

void Gameplay::DrawScene() {
  switch(gameState) {
    case Game:
      DrawBoardAndLegend();
      DrawPiece(mPosX, mPosY, mPiece, mRotation);
      DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
      break;
    case GameOver:
      graphicInterface->DrawGameOver();
      break;
  }
}

void Gameplay::CreateNewPiece() {
  // Get next piece and make it current
  mPiece = mNextPiece;
  mRotation = mNextRotation;
  mPosX = halfBoardWidth + PieceDefinition::GetXInitialPosition(mPiece, mRotation);
  mPosY = PieceDefinition::GetYInitialPosition(mPiece, mRotation);

  // Init new next piece
  mNextPiece = GetRand(6);
  mNextRotation = GetRand(3);
}

void Gameplay::DrawPiece(int16_t pX, int16_t pY, int16_t pPiece, int16_t pRotation) {

  int16_t mPixelsX = game::Board::GetXPosInPixels(pX);
  int16_t mPixelsY = game::Board::GetYPosInPixels(pY);

  for (int16_t i = 0; i < pieceBlocks; i++) {
    for (int16_t j = 0; j < pieceBlocks; j++) {

      colorEnum pieceColor = PieceDefinition::GetBlockType(pPiece, pRotation, j, i) == RotationPiece ? ColorThird : ColorPrimary;

      if (PieceDefinition::GetBlockType(pPiece, pRotation, j, i) != Blank) {
        graphicInterface->DrawRectangle(
            mPixelsX + (i * blockSize) + boardLineWidth + blockMargin,
            mPixelsY + j * blockSize,
            blockSize - blockMargin,
            blockSize - blockMargin,
            pieceColor);
      }
    }
  }
}

void Gameplay::DrawBoardAndLegend() {

  graphicInterface->DrawLegend();
  graphicInterface->DrawRectangle(boardLineX1, boardLineY1, boardLineWidth, boardHeight * blockSize, ColorPrimary);
  graphicInterface->DrawRectangle(boardLineX2, boardLineY2, boardLineWidth, boardHeight * blockSize, ColorPrimary);

  for (int16_t i = 0; i < boardWidth; i++) {
    for (int16_t j = 0; j < boardHeight; j++) {
      if (!board->IsFreeBlock(i, j)) {
        graphicInterface->DrawRectangle(
            boardLineX1 + (i * blockSize) + boardLineWidth + blockMargin,
            boardLineY1 + (j * blockSize),
            blockSize - blockMargin,
            blockSize - blockMargin,
            ColorPrimary);
      }
    }
  }
}

int16_t Gameplay::GetRand(int16_t max) {
  return rand() % max + 1;
}
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

  // Init current falling currentPiece
  currentPiece = GetRand(6);
  currentRotation = GetRand(3);
  currentPosX = halfBoardWidth + PieceDefinition::GetXInitialPosition(currentPiece, currentRotation);
  currentPosY = PieceDefinition::GetYInitialPosition(currentPiece, currentRotation);

  // Init next currentPiece next to board
  nextPiece = GetRand(6);
  nextRotation = GetRand(3);
  nextPosX = boardWidth + nextPieceMargin;
  nextPosY = nextPieceMargin;
}

void Gameplay::MoveRight() {
  if (board->IsPossibleMovement(currentPosX + 1, currentPosY, currentPiece, currentRotation)) {
    currentPosX++;
  }
}

void Gameplay::MoveLeft() {
  if (board->IsPossibleMovement(currentPosX - 1, currentPosY, currentPiece, currentRotation)) {
    currentPosX--;
  }
}

void Gameplay::MoveDown() {
  if (board->IsPossibleMovement(currentPosX, currentPosY + 1, currentPiece, currentRotation)) {
    currentPosY++;
  }
}

void Gameplay::MoveBottom() {
  while (board->IsPossibleMovement(currentPosX, currentPosY + 1, currentPiece, currentRotation)) {
    currentPosY++;
  }
  StorePiece();
}

void Gameplay::Rotate() {
  if (board->IsPossibleMovement(currentPosX, currentPosY, currentPiece, (currentRotation + 1) % 4)) {
    currentRotation = (currentRotation + 1) % 4;
  }
}

void Gameplay::Fall() {
  if (gameState == Game && board->IsPossibleMovement(currentPosX, currentPosY + 1, currentPiece, currentRotation)) {
    currentPosY++;
  } else {
    StorePiece();
  }
}

void Gameplay::StorePiece() {
  board->StorePiece(currentPosX, currentPosY, currentPiece, currentRotation);
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
      DrawPiece(currentPosX, currentPosY, currentPiece, currentRotation);
      DrawPiece(nextPosX, nextPosY, nextPiece, nextRotation);
      break;
    case GameOver:
      graphicInterface->DrawGameOver();
      break;
  }
}

void Gameplay::CreateNewPiece() {
  // Get next currentPiece and make it current
  currentPiece = nextPiece;
  currentRotation = nextRotation;
  currentPosX = halfBoardWidth + PieceDefinition::GetXInitialPosition(currentPiece, currentRotation);
  currentPosY = PieceDefinition::GetYInitialPosition(currentPiece, currentRotation);

  // Init new next currentPiece
  nextPiece = GetRand(6);
  nextRotation = GetRand(3);
}

void Gameplay::DrawPiece(int16_t pX, int16_t pY, int16_t piece, int16_t rotation) {

  int16_t mPixelsX = game::Board::GetXPosInPixels(pX);
  int16_t mPixelsY = game::Board::GetYPosInPixels(pY);

  for (int16_t i = 0; i < pieceBlocks; i++) {
    for (int16_t j = 0; j < pieceBlocks; j++) {

      colorEnum currentPieceColor = PieceDefinition::GetBlockType(piece, rotation, j, i) == RotationPiece ? ColorThird : ColorPrimary;

      if (PieceDefinition::GetBlockType(piece, rotation, j, i) != Blank) {
        graphicInterface->DrawRectangle(
            mPixelsX + (i * blockSize) + boardLineWidth + blockMargin,
            mPixelsY + j * blockSize,
            blockSize - blockMargin,
            blockSize - blockMargin,
            currentPieceColor);
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
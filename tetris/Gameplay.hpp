//
// Created by Alicja on 2020-03-06.
//

#pragma once
#include <string>
#include <cstdint>
#include <ctime>
#include "Board.hpp"
#include "GraphicInterface.hpp"
#include "PieceDefinition.hpp"

namespace game {

  enum GameState {Game, GameOver};

  class Gameplay {
  public:
    Gameplay(Board *pBoard, GraphicInterface *pGraphicInterface);

    void DrawScene();
    void CreateNewPiece();

    // current falling piece
    int16_t currentPosX{}, currentPosY{};
    int16_t currentPiece{}, currentRotation{};

    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void MoveBottom();
    void Rotate();
    void Fall();

    void RestartGame();

  private:
    GameState gameState {Game};

    int16_t nextPosX{}, nextPosY{};
    int16_t nextPiece{}, nextRotation{};

    Board *board;
    GraphicInterface *graphicInterface;

    void InitGameplay();

    void DrawPiece(int16_t pX, int16_t pY, int16_t piece, int16_t rotation);

    void DrawBoardAndLegend();

    void CheckIfGameOver();

    void StorePiece();

    static int16_t GetRand(int16_t max);
  };
}

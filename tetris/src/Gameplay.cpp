//
// Created by Alicja on 2020-03-06.
//

#include "Gameplay.hpp"
#include "settings.hpp"
#include <cstdlib>

using namespace game;

Gameplay::Gameplay(Board* pBoard, GraphicInterface* pGraphicInterface)
{
    _board = pBoard;
    _graphicInterface = pGraphicInterface;

    InitGameplay();
}

void Gameplay::InitGameplay()
{
    srand((unsigned int)time(nullptr));

    // Init current falling currentPiece
    currentPiece = GetRand(6);
    currentRotation = GetRand(3);
    currentPosX = halfBoardWidth + PieceDefinition::GetXInitialPosition(currentPiece, currentRotation);
    currentPosY = PieceDefinition::GetYInitialPosition(currentPiece, currentRotation);

    // Init next currentPiece next to board
    _nextPiece = GetRand(6);
    _nextRotation = GetRand(3);
    _nextPosX = boardWidth + nextPieceMargin;
    _nextPosY = nextPieceMargin;
}

void Gameplay::MoveRight()
{
    if(_board->IsPossibleMovement(currentPosX + 1, currentPosY, currentPiece, currentRotation))
    {
        currentPosX++;
    }
}

void Gameplay::MoveLeft()
{
    if(_board->IsPossibleMovement(currentPosX - 1, currentPosY, currentPiece, currentRotation))
    {
        currentPosX--;
    }
}

void Gameplay::MoveDown()
{
    if(_board->IsPossibleMovement(currentPosX, currentPosY + 1, currentPiece, currentRotation))
    {
        currentPosY++;
    }
}

void Gameplay::MoveBottom()
{
    while(_board->IsPossibleMovement(currentPosX, currentPosY + 1, currentPiece, currentRotation))
    {
        currentPosY++;
    }
    StorePiece();
}

void Gameplay::Rotate()
{
    if(_board->IsPossibleMovement(currentPosX, currentPosY, currentPiece, (currentRotation + 1) % 4))
    {
        currentRotation = (currentRotation + 1) % 4;
    }
}

void Gameplay::Fall()
{
    if(_gameState == Game &&
       _board->IsPossibleMovement(currentPosX, currentPosY + 1, currentPiece, currentRotation))
    {
        currentPosY++;
    }
    else
    {
        StorePiece();
    }
}

void Gameplay::StorePiece()
{
    _board->StorePiece(currentPosX, currentPosY, currentPiece, currentRotation);
    _board->DeletePossibleLines();

    CheckIfGameOver();
    CreateNewPiece();
}

void Gameplay::CheckIfGameOver()
{
    if(_board->IsGameOver())
    {
        _gameState = GameOver;
    }
}

void Gameplay::RestartGame()
{
    _gameState = Game;
    _board->Restart();
    CreateNewPiece();
}

void Gameplay::DrawScene()
{
    switch(_gameState)
    {
        case Game:
            DrawBoardAndLegend();
            DrawPiece(currentPosX, currentPosY, currentPiece, currentRotation);
            DrawPiece(_nextPosX, _nextPosY, _nextPiece, _nextRotation);
            break;
        case GameOver:
            _graphicInterface->DrawGameOver();
            break;
    }
}

void Gameplay::CreateNewPiece()
{
    // Get next currentPiece and make it current
    currentPiece = _nextPiece;
    currentRotation = _nextRotation;
    currentPosX = halfBoardWidth + PieceDefinition::GetXInitialPosition(currentPiece, currentRotation);
    currentPosY = PieceDefinition::GetYInitialPosition(currentPiece, currentRotation);

    // Init new next currentPiece
    _nextPiece = GetRand(6);
    _nextRotation = GetRand(3);
}

void Gameplay::DrawPiece(int16_t pX, int16_t pY, int16_t piece, int16_t rotation)
{
    int16_t mPixelsX = game::Board::GetXPosInPixels(pX);
    int16_t mPixelsY = game::Board::GetYPosInPixels(pY);

    for(int16_t i = 0; i < pieceBlocks; i++)
    {
        for(int16_t j = 0; j < pieceBlocks; j++)
        {
            ColorEnum currentPieceColor =
                PieceDefinition::GetBlockType(piece, rotation, j, i) == RotationPiece ?
                ColorEnum::ColorThird :
                ColorEnum::ColorPrimary;

            if(PieceDefinition::GetBlockType(piece, rotation, j, i) != Blank)
            {
                _graphicInterface->DrawRectangle(
                    mPixelsX + (i * blockSize) + boardLineWidth + blockMargin,
                    mPixelsY + j * blockSize,
                    blockSize - blockMargin,
                    blockSize - blockMargin,
                    currentPieceColor);
            }
        }
    }
}

void Gameplay::DrawBoardAndLegend()
{
    _graphicInterface->DrawLegend();
    _graphicInterface->DrawRectangle(
        boardLineX1, boardLineY1, boardLineWidth, boardHeight * blockSize, ColorEnum::ColorPrimary);
    _graphicInterface->DrawRectangle(
        boardLineX2, boardLineY2, boardLineWidth, boardHeight * blockSize, ColorEnum::ColorPrimary);

    for(int16_t i = 0; i < boardWidth; i++)
    {
        for(int16_t j = 0; j < boardHeight; j++)
        {
            if(!_board->IsFreeBlock(i, j))
            {
                _graphicInterface->DrawRectangle(
                    boardLineX1 + (i * blockSize) + boardLineWidth + blockMargin,
                    boardLineY1 + (j * blockSize),
                    blockSize - blockMargin,
                    blockSize - blockMargin,
                    ColorEnum::ColorPrimary);
            }
        }
    }
}

int16_t Gameplay::GetRand(int16_t max)
{
    return rand() % max + 1;
}
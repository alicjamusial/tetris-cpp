//
// Created by Alicja on 2020-03-06.
//

#include "Gameplay.hpp"
#include "PieceDefinition.hpp"
#include "settings.hpp"
#include <cstdlib>
#include <ctime>

using namespace game;

Gameplay::Gameplay(Board* pBoard, GraphicInterface* pGraphicInterface)
{
    _board = pBoard;
    _graphicInterface = pGraphicInterface;
}

void Gameplay::InitGameplay()
{
    srand((unsigned int)time(nullptr));

    // Init current falling currentPiece
    currentPiece = GetRand(6);
    currentRotation = GetRand(3);
    int16_t x = halfBoardWidth + PieceDefinition::GetXInitialPosition(currentPiece, currentRotation);
    int16_t y = PieceDefinition::GetYInitialPosition(currentPiece, currentRotation);
    currentPoint = Point{x, y};

    // Init next currentPiece next to board
    _nextPiece = GetRand(6);
    _nextRotation = GetRand(3);
    int16_t nextX = boardWidth + nextPieceMargin;
    int16_t nextY = nextPieceMargin;
    _nextPoint = Point{nextX, nextY};
}

void Gameplay::MoveRight()
{
    if(_board->IsPossibleMovement(currentPoint.Right(), currentPiece, currentRotation))
    {
        currentPoint = currentPoint.Right();
    }
}

void Gameplay::MoveLeft()
{
    if(_board->IsPossibleMovement(currentPoint.Left(), currentPiece, currentRotation))
    {
        currentPoint = currentPoint.Left();
    }
}

void Gameplay::MoveDown()
{
    if(_board->IsPossibleMovement(currentPoint.Down(), currentPiece, currentRotation))
    {
        currentPoint = currentPoint.Down();
    }
}

void Gameplay::MoveBottom()
{
    while(_board->IsPossibleMovement(currentPoint.Down(), currentPiece, currentRotation))
    {
        currentPoint = currentPoint.Down();
    }
    StorePiece();
}

void Gameplay::Rotate()
{
    if(_board->IsPossibleMovement(currentPoint, currentPiece, GetNextRotation(currentRotation)))
    {
        currentRotation = GetNextRotation(currentRotation);
    }
}

void Gameplay::Fall()
{
    if(_gameState == Game && _board->IsPossibleMovement(currentPoint.Down(), currentPiece, currentRotation))
    {
        currentPoint = currentPoint.Down();
    }
    else
    {
        StorePiece();
    }
}

void Gameplay::StorePiece()
{
    _board->StorePiece(currentPoint, currentPiece, currentRotation);
//    _board->DeletePossibleLines();
//
//    CheckIfGameOver();
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
    _board->CreateBoard();
    CreateNewPiece();
}

void Gameplay::DrawScene()
{
    switch(_gameState)
    {
        case Game:
            DrawBoardAndLegend();
            DrawPiece(currentPoint, currentPiece, currentRotation);
            DrawPiece(_nextPoint, _nextPiece, _nextRotation);
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
    int16_t x = halfBoardWidth + PieceDefinition::GetXInitialPosition(currentPiece, currentRotation);
    int16_t y = PieceDefinition::GetYInitialPosition(currentPiece, currentRotation);
    currentPoint = Point{x, y};

    // Init new next currentPiece
    _nextPiece = GetRand(6);
    _nextRotation = GetRand(3);
}

void Gameplay::DrawPiece(Point point, int16_t piece, int16_t rotation)
{
    int16_t mPixelsX = game::Board::GetXPosInPixels(point.x);
    int16_t mPixelsY = game::Board::GetYPosInPixels(point.y);

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
                int16_t x = mPixelsX + (i * blockSize) + boardLineWidth + blockMargin;
                int16_t y = mPixelsY + j * blockSize;
                Point rectangleCorner{x, y};
                _graphicInterface->DrawRectangle(
                    rectangleCorner, blockSize - blockMargin, blockSize - blockMargin, currentPieceColor);
            }
        }
    }
}

void Gameplay::DrawBoardAndLegend()
{
    Point pointBoard1{boardLineX1, boardLineY1};
    Point pointBoard2{boardLineX2, boardLineY2};
    _graphicInterface->DrawLegend();
    _graphicInterface->DrawRectangle(
        pointBoard1, boardLineWidth, boardHeight * blockSize, ColorEnum::ColorPrimary);
    _graphicInterface->DrawRectangle(
        pointBoard2, boardLineWidth, boardHeight * blockSize, ColorEnum::ColorPrimary);

    for(int16_t i = 0; i < boardWidth; i++)
    {
        for(int16_t j = 0; j < boardHeight; j++)
        {
            if(!_board->IsFreeBlock(Point{i, j}))
            {
                int16_t x = boardLineX1 + (i * blockSize) + boardLineWidth + blockMargin;
                int16_t y = boardLineX1 + (i * blockSize) + boardLineWidth + blockMargin;
                _graphicInterface->DrawRectangle(
                    Point{x, y},
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

int16_t Gameplay::GetNextRotation(int16_t rotation)
{
    return (rotation + 1) % 4;
}
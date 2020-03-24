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
    currentPosX = halfBoardWidth + PieceDefinition::GetXInitialPosition(currentPiece, currentRotation);
    currentPosY = PieceDefinition::GetYInitialPosition(currentPiece, currentRotation);
    currentPoint = Point{currentPosX, currentPosY};

    // Init next currentPiece next to board
    _nextPiece = GetRand(6);
    _nextRotation = GetRand(3);
    _nextPosX = boardWidth + nextPieceMargin;
    _nextPosY = nextPieceMargin;
    _nextPoint = Point{_nextPosX, _nextPosY};
}

void Gameplay::MoveRight()
{
    int16_t xRight = currentPosX + 1;
    Point pointRight{xRight, currentPosY};
    if(_board->IsPossibleMovement(pointRight, currentPiece, currentRotation))
    {
        currentPosX++;
    }
}

void Gameplay::MoveLeft()
{
    int16_t xLeft = currentPosX - 1;
    Point pointLeft{xLeft, currentPosY};
    if(_board->IsPossibleMovement(pointLeft, currentPiece, currentRotation))
    {
        currentPosX--;
    }
}

void Gameplay::MoveDown()
{
    int16_t yDown = currentPosY + 1;
    Point pointDown{currentPosX, yDown};
    if(_board->IsPossibleMovement(pointDown, currentPiece, currentRotation))
    {
        currentPosY++;
    }
}

void Gameplay::MoveBottom()
{
    int16_t yDown = currentPosY + 1;
    Point pointDown{currentPosX, yDown};
    while(_board->IsPossibleMovement(pointDown, currentPiece, currentRotation))
    {
        currentPosY++;
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
    int16_t yDown = currentPosY + 1;
    Point pointDown{currentPosX, yDown};
    if(_gameState == Game && _board->IsPossibleMovement(pointDown, currentPiece, currentRotation))
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
    _board->StorePiece(currentPoint, currentPiece, currentRotation);
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
    currentPosX = halfBoardWidth + PieceDefinition::GetXInitialPosition(currentPiece, currentRotation);
    currentPosY = PieceDefinition::GetYInitialPosition(currentPiece, currentRotation);
    currentPoint = Point{currentPosX, currentPosY};

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
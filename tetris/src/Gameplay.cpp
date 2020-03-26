//
// Created by Alicja on 2020-03-06.
//

#include "Gameplay.hpp"
#include "PieceDefinition.hpp"
#include "settings.hpp"

using namespace game;

Gameplay::Gameplay(std::shared_ptr<GraphicInterface>& pGraphicInterface) :
    _distributionPiece(0, 7), _distributionRotation(0, 3), _board{std::make_unique<Board>()}
{
    _board->CreateBoard();
    _engine.seed(_randomDevice());
    _graphicInterface = pGraphicInterface;
    _gameAction = {{SDLK_d, &Gameplay::MoveRight},
                   {SDLK_a, &Gameplay::MoveLeft},
                   {SDLK_s, &Gameplay::MoveDown},
                   {SDLK_x, &Gameplay::MoveBottom},
                   {SDLK_z, &Gameplay::Rotate},
                   {SDLK_r, &Gameplay::RestartGame}};
}

void Gameplay::InitGameplay()
{
    // Init current falling currentPiece
    _currentPiece = GetRandPiece();
    _currentRotation = GetRandRotation();
    int16_t x = halfBoardWidth + PieceDefinition::GetXInitialPosition(_currentPiece, _currentRotation);
    int16_t y = PieceDefinition::GetYInitialPosition(_currentPiece, _currentRotation);
    _currentPoint = Point{x, y};

    // Init next currentPiece next to board
    _nextPiece = GetRandPiece();
    _nextRotation = GetRandRotation();
    int16_t nextX = boardWidth + nextPieceMargin;
    int16_t nextY = nextPieceMargin;
    _nextPoint = Point{nextX, nextY};
}

void Gameplay::MoveRight()
{
    if(_board->IsPossibleMovement(_currentPoint.Right(), _currentPiece, _currentRotation))
    {
        _currentPoint = _currentPoint.Right();
    }
}

void Gameplay::MoveLeft()
{
    if(_board->IsPossibleMovement(_currentPoint.Left(), _currentPiece, _currentRotation))
    {
        _currentPoint = _currentPoint.Left();
    }
}

void Gameplay::MoveDown()
{
    if(_board->IsPossibleMovement(_currentPoint.Down(), _currentPiece, _currentRotation))
    {
        _currentPoint = _currentPoint.Down();
    }
}

void Gameplay::MoveBottom()
{
    while(_board->IsPossibleMovement(_currentPoint.Down(), _currentPiece, _currentRotation))
    {
        _currentPoint = _currentPoint.Down();
    }
    StorePiece();
}

void Gameplay::Rotate()
{
    if(_board->IsPossibleMovement(_currentPoint, _currentPiece, GetNextRotation(_currentRotation)))
    {
        _currentRotation = GetNextRotation(_currentRotation);
    }
}

void Gameplay::Fall()
{
    if(_gameState == Game && _board->IsPossibleMovement(_currentPoint.Down(), _currentPiece, _currentRotation))
    {
        _currentPoint = _currentPoint.Down();
    }
    else
    {
        StorePiece();
    }
}

void Gameplay::StorePiece()
{
    _board->StorePiece(_currentPoint, _currentPiece, _currentRotation);
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
            DrawPiece(_currentPoint, _currentPiece, _currentRotation);
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
    _currentPiece = _nextPiece;
    _currentRotation = _nextRotation;
    int16_t x = halfBoardWidth + PieceDefinition::GetXInitialPosition(_currentPiece, _currentRotation);
    int16_t y = PieceDefinition::GetYInitialPosition(_currentPiece, _currentRotation);
    _currentPoint = Point{x, y};

    // Init new next currentPiece
    _nextPiece = GetRandPiece();
    _nextRotation = GetRandRotation();
}

void Gameplay::DrawPiece(Point point, int16_t piece, int16_t rotation)
{
    for(int16_t i = 0; i < pieceBlocks; i++)
    {
        for(int16_t j = 0; j < pieceBlocks; j++)
        {
            int16_t blockType = PieceDefinition::GetBlockType(piece, rotation, j, i);
            if(blockType != Blank)
            {
                int16_t mPixelsX = game::Board::GetXPosInPixels(point.x);
                int16_t mPixelsY = game::Board::GetYPosInPixels(point.y);

                int16_t x = mPixelsX + (i * blockSize) + boardLineWidth + blockMargin;
                int16_t y = mPixelsY + j * blockSize;
                _graphicInterface->DrawBlock(Point{x, y}, blockType);
            }
        }
    }
}

void Gameplay::DrawBoardAndLegend()
{
    _graphicInterface->DrawLegend();
    _graphicInterface->DrawBoardLines();

    for(int16_t i = 0; i < boardWidth; i++)
    {
        for(int16_t j = 0; j < boardHeight; j++)
        {
            Point blockPoint = Point{i, j};
            if(!_board->IsFreeBlock(blockPoint))
            {
                int16_t x = boardLineX1 + (i * blockSize) + boardLineWidth + blockMargin;
                int16_t y = boardLineY1 + (j * blockSize);
                _graphicInterface->DrawBlock(Point{x, y}, 1);
            }
        }
    }
}

void Gameplay::CallAction(uint16_t key)
{
    auto action = _gameAction[key];
    if(action)
    {
        (this->*action)();
    }
}

int16_t Gameplay::GetRandPiece()
{
    return _distributionPiece(_engine);
}

int16_t Gameplay::GetRandRotation()
{
    return _distributionRotation(_engine);
}

int16_t Gameplay::GetNextRotation(int16_t rotation)
{
    return (rotation + 1) % 4;
}
//
// Created by Alicja on 2020-03-04.
//

#include "Board.hpp"
#include "PieceDefinition.hpp"
#include "settings.hpp"

using namespace game;

void Board::CreateBoard()
{
    for(auto& i: _boardFields)
    {
        for(PositionStatus& j: i)
        {
            j = PositionStatus::PositionFree;
        }
    }
}

void Board::StorePiece(Point point, int16_t piece, int16_t rotation)
{
    for(int16_t i1 = point.GetX(), i2 = 0; i1 < point.GetX() + pieceBlocks; i1++, i2++)
    {
        for(int16_t j1 = point.GetY(), j2 = 0; j1 < point.GetY() + pieceBlocks; j1++, j2++)
        {
            if(PieceDefinition::GetBlockType(piece, rotation, j2, i2) == NormalPiece ||
               PieceDefinition::GetBlockType(piece, rotation, j2, i2) == RotationPiece)
            {
                _boardFields[i1][j1] = PositionStatus::PositionFilled;
            }
            else if(PieceDefinition::GetBlockType(piece, rotation, j2, i2) == SpecialPiece)
            {
                for(int16_t m = 0; m < boardHeight; m++)
                {
                    _boardFields[i1][m] = PositionStatus::PositionFree;
                }
            }
        }
    }
}

bool Board::IsGameOver()
{
    for(auto& boardField: _boardFields)
    {
        if(boardField[0] == PositionStatus::PositionFilled)
        {
            return true;
        }
    }
    return false;
}

void Board::DeleteLine(int16_t y)
{
    for(int16_t j = y; j > 0; j--)
    {
        for(auto& boardField: _boardFields)
        {
            boardField[j] = boardField[j - 1];
        }
    }
}

void Board::DeletePossibleLines()
{
    for(int16_t i = 0; i < boardHeight; i++)
    {
        for(int16_t j = 0; j < boardWidth; j++)
        {
            if(_boardFields[j][i] != PositionStatus::PositionFilled)
            {
                break;
            }
            if(j == boardWidth - 1)
            {
                DeleteLine(i);
            }
        }
    }
}

bool Board::IsFreeBlock(Point point)
{
    return _boardFields[point.GetX()][point.GetY()] == PositionStatus::PositionFree;
}

bool Board::IsPossibleMovement(Point point, int16_t piece, int16_t rotation)
{
    for(int16_t i1 = point.GetX(), i2 = 0; i1 < point.GetX() + pieceBlocks; i1++, i2++)
    {
        for(int16_t j1 = point.GetY(), j2 = 0; j1 < point.GetY() + pieceBlocks; j1++, j2++)
        {
            if(i1 < 0 || i1 > boardWidth - 1 || j1 > boardHeight - 1)
            {
                if(PieceDefinition::GetBlockType(piece, rotation, j2, i2) != Blank)
                {
                    return false;
                }
            }
            if(j1 >= 0)
            {
                if((PieceDefinition::GetBlockType(piece, rotation, j2, i2) != Blank) &&
                   (!IsFreeBlock(Point{i1, j1})))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

Point Board::GetPosInPixels(Point point)
{
    int16_t x = boardLineX1 + (point.GetX() * blockSize);
    int16_t y = boardLineY1 + (point.GetY() * blockSize);
    return Point{x, y};
}
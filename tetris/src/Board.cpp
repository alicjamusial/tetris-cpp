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
    for(int16_t i1 = point.x, i2 = 0; i1 < point.x + pieceBlocks; i1++, i2++)
    {
        for(int16_t j1 = point.y, j2 = 0; j1 < point.y + pieceBlocks; j1++, j2++)
        {
            if(PieceDefinition::GetBlockType(piece, rotation, j2, i2) != Blank)
            {
                _boardFields[i1][j1] = PositionStatus::PositionFilled;
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
        for(int16_t j = 0; j < boardWidth; j++) {
            if(_boardFields[j][i] != PositionStatus::PositionFilled) {
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
    return _boardFields[point.x][point.y] == PositionStatus::PositionFree;
}

bool Board::IsPossibleMovement(Point point, int16_t piece, int16_t rotation)
{
    for(int16_t i1 = point.x, i2 = 0; i1 < point.x + pieceBlocks; i1++, i2++)
    {
        for(int16_t j1 = point.y, j2 = 0; j1 < point.y + pieceBlocks; j1++, j2++)
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

int16_t Board::GetXPosInPixels(int16_t pPos)
{
    return boardLineX1 + (pPos * blockSize);
}

int16_t Board::GetYPosInPixels(int16_t pPos)
{
    return boardLineY1 + (pPos * blockSize);
}
//
// Created by Alicja on 2020-03-04.
//
#pragma once
#include "Point.hpp"
#include "settings.hpp"
#include <cstdint>

namespace game
{
    class Board
    {
    public:
        static Point GetPosInPixels(Point point);

        bool IsFreeBlock(Point point);

        bool IsPossibleMovement(Point point, int16_t piece, int16_t rotation);

        void StorePiece(Point point, int16_t piece, int16_t rotation);

        void DeletePossibleLines();

        bool IsGameOver();

        void CreateBoard();

    private:
        enum class PositionStatus
        {
            PositionFree,
            PositionFilled
        };

        PositionStatus _boardFields[boardWidth][boardHeight]{};

        void DeleteLine(int16_t pY);
    };
}

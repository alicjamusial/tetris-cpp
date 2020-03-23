//
// Created by Alicja on 2020-03-04.
//
#pragma once
#include "settings.hpp"
#include <cstdint>

namespace game
{
    class Board
    {
    public:
        Board();

        static int16_t GetXPosInPixels(int16_t pPos);

        static int16_t GetYPosInPixels(int16_t pPos);

        bool IsFreeBlock(int16_t pX, int16_t pY);

        bool IsPossibleMovement(int16_t pX, int16_t pY, int16_t piece, int16_t rotation);

        void StorePiece(int16_t pX, int16_t pY, int16_t piece, int16_t rotation);

        void DeletePossibleLines();

        bool IsGameOver();

        void Restart();

    private:
        enum class PositionStatus
        {
            PositionFree,
            PositionFilled
        };

        PositionStatus _boardFields[boardWidth][boardHeight]{};

        void InitBoard();

        void DeleteLine(int16_t pY);
    };
}

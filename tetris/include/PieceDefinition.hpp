//
// Created by Alicja on 2020-03-02.
// Pieces definition from tutorial:
// http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/
//
#pragma once
#include <cstdint>

namespace game
{
    class PieceDefinition
    {
    public:
        static int16_t GetBlockType(int16_t piece, int16_t rotation, int16_t pX, int16_t pY);
        static int16_t GetXInitialPosition(int16_t piece, int16_t rotation);
        static int16_t GetYInitialPosition(int16_t piece, int16_t rotation);

    private:
        // Pieces definition
        const static char _piecesTypes[8 /*kind */][4 /* rotation */][5 /* horizontal blocks */][5 /* vertical blocks */];

        // Displacement of the piece to the position where it is first drawn in the
        // board when it is created
        const static int16_t _piecesInitialPosition[7 /*kind */][4 /* r2otation */][2 /* position */];
    };
}

//
// Created by Alicja on 2020-03-02.
//

#include "PieceDefinition.hpp"

using namespace game;

int16_t PieceDefinition::GetBlockType(int16_t piece, int16_t rotation, int16_t pX, int16_t pY)
{
    return PieceDefinition::_piecesTypes[piece][rotation][pX][pY];
}

int16_t PieceDefinition::GetXInitialPosition(int16_t piece, int16_t rotation)
{
    return PieceDefinition::_piecesInitialPosition[piece][rotation][0];
}

int16_t PieceDefinition::GetYInitialPosition(int16_t piece, int16_t rotation)
{
    return PieceDefinition::_piecesInitialPosition[piece][rotation][1];
}

const char PieceDefinition::_piecesTypes[7 /*kind */][4 /* rotation */][5 /* horizontal blocks */][5 /* vertical blocks */] = {
    // Square
    {{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 2, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 2, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 2, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 2, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}}},
    // I
    {{{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 1, 2, 1, 1}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 2, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {1, 1, 2, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 2, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}}},
    // L
    {{{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 2, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 1, 2, 1, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 2, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 1, 2, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}},
    // L mirrored
    {{{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 2, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 1, 2, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 2, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 1, 2, 1, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 0}}},
    // N
    {{{0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 2, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 1, 2, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 2, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 2, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}},
    // N mirrored
    {{{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 2, 1, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 2, 1, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 1, 2, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 1, 1, 0}, {0, 1, 2, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}},
    // T
    {{{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 2, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 1, 2, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 2, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}},
     {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 2, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}}};

// Displacement of the piece to the position where it is first drawn in the
// board when it is created
const int16_t PieceDefinition::_piecesInitialPosition[7 /*kind */][4 /* r2otation */][2 /* position */] = {
    /* Square */
    {{-2, -3}, {-2, -3}, {-2, -3}, {-2, -3}},
    /* I */
    {{-2, -2}, {-2, -3}, {-2, -2}, {-2, -3}},
    /* L */
    {{-2, -3}, {-2, -3}, {-2, -3}, {-2, -2}},
    /* L mirrored */
    {{-2, -3}, {-2, -2}, {-2, -3}, {-2, -3}},
    /* N */
    {{-2, -3}, {-2, -3}, {-2, -3}, {-2, -2}},
    /* N mirrored */
    {{-2, -3}, {-2, -3}, {-2, -3}, {-2, -2}},
    /* T */
    {{-2, -3}, {-2, -3}, {-2, -3}, {-2, -2}},
};
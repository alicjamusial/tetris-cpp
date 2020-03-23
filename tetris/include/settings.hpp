//
// Created by Alicja on 2020-03-20.
//

#pragma once
#include <cstdint>

namespace game
{
    constexpr uint16_t screenWidth{640};
    constexpr uint16_t screenHeight{480};

    constexpr uint16_t gameOverImgWidth{400};
    constexpr uint16_t gameOverImgHeight{200};

    constexpr uint16_t legendImgWidth{400};
    constexpr uint16_t legendImgHeight{120};
    constexpr uint16_t legendMargin{10};

    constexpr uint16_t timeInterval{200};

    constexpr uint16_t boardLineWidth{6};
    constexpr uint16_t blockSize{16};
    constexpr uint16_t blockMargin{2};
    constexpr uint16_t nextPieceMargin{5};
    constexpr uint16_t boardWidth{12};
    constexpr uint16_t boardHeight{18};

    constexpr uint16_t pieceBlocks{5};

    constexpr uint16_t halfBoardWidth{boardWidth / 2};
    constexpr uint16_t halfBlockMargin{blockMargin / 2};

    constexpr uint16_t boardLineX1{screenWidth / 2 - (halfBoardWidth * blockSize) -
                                   boardLineWidth / 2 - halfBlockMargin};
    constexpr uint16_t boardLineY1{screenHeight - (boardHeight * blockSize)};

    constexpr uint16_t boardLineX2{screenWidth / 2 + (halfBoardWidth * blockSize) +
                                   boardLineWidth / 2 + halfBlockMargin};
    constexpr uint16_t boardLineY2{screenHeight - (boardHeight * blockSize)};

    enum class ColorEnum
    {
        ColorBoard,
        ColorPrimary,
        ColorThird
    };
}
//
// Created by Alicja on 2020-03-20.
//

#pragma once
#include <map>
#include <cstdint>

namespace game {
  uint16_t const screenWidth {640};
  uint16_t const screenHeight {480};

  uint16_t const timeInterval {700};

  uint16_t const boardLineWidth {6};
  uint16_t const blockSize {16};
  uint16_t const blockMargin {2};
  uint16_t const boardWidth {10};
  uint16_t const boardHeight {20};
  uint16_t const pieceBlocks {5};

  uint16_t const boardLineX1 = screenWidth / 2 - (boardWidth / 2 * blockSize) - boardLineWidth / 2 - (blockMargin / 2);
  uint16_t const boardLineY1 = screenHeight - (boardHeight * blockSize);

  uint16_t const boardLineX2 = screenWidth / 2 + (boardWidth / 2 * blockSize) + boardLineWidth / 2 + (blockMargin / 2);
  uint16_t const boardLineY2 = screenHeight - (boardHeight * blockSize);

  enum colorEnum {ColorBoard, ColorPrimary, ColorSecondary, ColorThird};

  uint32_t const colorsMap[][4] = {
      {0x8c, 0x8a, 0x93, 0xFF},
      {0xd1, 0xf0, 0xb1, 0xFF},
      {0x81, 0x66, 0x7a, 0xFF},
      {0xb6, 0xcb, 0x9e, 0xFF},
  };

}
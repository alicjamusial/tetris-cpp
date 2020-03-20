//
// Created by Alicja on 2020-03-20.
//

#pragma once
#include <map>
#include <cstdint>

namespace game {
  uint16_t const screenWidth{640};
  uint16_t const screenHeight{480};

  enum colorEnum {BOARD, PRIMARY, SECONDARY};

  uint32_t const colorsMap[][4] = {
      {0x92, 0xb4, 0xa7, 0xFF},
      {0xd1, 0xf0, 0xb1, 0xFF},
      {0x81, 0x66, 0x7a, 0xFF}
  };

}
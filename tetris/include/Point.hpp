//
// Created by Alicja on 2020-03-24.
//

#pragma once
#include <cstdint>

class Point
{
public:
    int16_t x;
    int16_t y;

    Point Right();
    Point Left();
    Point Down();
};
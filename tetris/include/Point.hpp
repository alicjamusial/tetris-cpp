//
// Created by Alicja on 2020-03-24.
//

#pragma once
#include <cstdint>

class Point
{
public:
    Point(int16_t pX, int16_t pY);

    int16_t GetX();
    int16_t GetY();

    Point Right();
    Point Left();
    Point Down();

private:
    int16_t x;
    int16_t y;
};
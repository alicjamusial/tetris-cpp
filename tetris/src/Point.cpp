//
// Created by Alicja on 2020-03-24.
//

#include "Point.hpp"

Point Point::Right()
{
    int16_t newX = x + 1;
    return Point{newX, y};
}

Point Point::Left()
{
    int16_t newX = x - 1;
    return Point{newX, y};
}

Point Point::Down()
{
    int16_t newY = y + 1;
    return Point{x, newY};
}
//
// Created by Alicja on 2020-03-24.
//

#include "Point.hpp"

Point Point::Right()
{
    return Point{x++, y};
}

Point Point::Left()
{
    return Point{x--, y};
}

Point Point::Down()
{
    return Point{x, y++};
}

Point Point::Up()
{
    return Point{x, y--};
}

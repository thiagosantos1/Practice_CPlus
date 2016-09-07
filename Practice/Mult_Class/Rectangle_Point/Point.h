#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point
{
    int x;
    int y;
};


bool operator==(const Point& lhs, const Point& rhs);

std::ostream & operator<<(std::ostream & lhs, const Point & p);

#endif
#include <iostream>
#include "point.h"

using namespace std;


bool operator==(const Point& lhs, const Point& rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}


ostream & operator<<(ostream & lhs, const Point & p)
{
    lhs << '(' << p.x << ", " << p.y << ')';
    return lhs;
}
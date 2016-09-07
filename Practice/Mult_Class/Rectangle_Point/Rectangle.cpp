#include <iostream>
#include "Rectangle.h"

using namespace std;

// constructor
Rectangle::Rectangle(const Point & topleft_in, int width_in, int height_in)
{
    topleft = topleft_in;
    width = width_in;
    height = height_in;
}


bool Rectangle::operator==(const Rectangle & other)
{
    return topleft == other.topleft &&
           width == other.width &&
           height == other.height;
}


bool Rectangle::contains(const Point & p) const
{
    // Point to the left
    if (p.x < topleft.x)
        return false;

    // Point to the right
    if (p.x > topleft.x + width)
        return false;

    // Point above
    if (p.y > topleft.y)
        return false;

    // Point below
    if (p.y < topleft.y - height)
        return false;

    return true;
}


ostream & operator<<(ostream & lhs, const Rectangle & r)
{
    lhs << "Top:    " << r.getTopleft().y << endl
        << "Bottom: " << r.getTopleft().y - r.getHeight() << endl
        << "Left:   " << r.getTopleft().x << endl
        << "Right:  " << r.getTopleft().x + r.getWidth() << endl;

    return lhs;
}

#include <iostream>
using namespace std;

struct Point
{
    int x, y;
};


bool operator==(const Point& lhs, const Point& rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}


ostream & operator<<(ostream & lhs, const Point & p)
{
    lhs << '(' << p.x << ", " << p.y << ')';
    return lhs;
}

struct Rectangle
{
    Point topleft;
    Point bottomright;
};


bool operator==(const Rectangle & lhs, const Rectangle & rhs)
{
    return lhs.topleft == rhs.topleft && lhs.bottomright == rhs.bottomright;
}


ostream & operator<<(ostream & lhs, const Rectangle & r)
{
    lhs << "Top:    " << r.topleft.y << endl
        << "Bottom: " << r.bottomright.y << endl
        << "Left:   " << r.topleft.x << endl
        << "Right:  " << r.bottomright.x << endl;

    return lhs;
}

bool isInside(const Point & p, const Rectangle & r)
{
    // Point to the left
    if (p.x < r.topleft.x)
        return false;

    // Point to the right
    if (p.x > r.bottomright.x)
        return false;

    // Point above
    if (p.y > r.topleft.y)
        return false;

    // Point below
    if (p.y < r.bottomright.y)
        return false;

    return true;
}

int main(int argc, char const *argv[])
{
    Rectangle a = { {2, 4}, {3, 2} };

    Point p = {3, 4};

    if (isInside(p, a))
    {
        cout << "p is inside a" << endl;
    }

    return 0;
}
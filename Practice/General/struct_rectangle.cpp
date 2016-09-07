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
// change the rectangle for have just the topleft anda weidth, height, to muke sure
// the rectangle is right, it's always a rectangle, then you can "draw" the rectangle
{
    Point topleft;
    int weidth;
    int height; 
};


bool operator==(const Rectangle & lhs, const Rectangle & rhs)
{
    return lhs.topleft == rhs.topleft && lhs.weidth == rhs.weidth && lhs.height == rhs.height ;
}


ostream & operator<<(ostream & lhs, const Rectangle & r)
{
    lhs << "Top:    " << r.topleft.y << endl
        << "Bottom: " << r.topleft.y - r.height << endl
        << "Left:   " << r.topleft.x << endl
        << "Right:  " << r.topleft.x  + r.weidth << endl;

    return lhs;
}

bool isInside(const Point & p, const Rectangle & r)
{
    // Point to the left
    if (p.x < r.topleft.x)
        return false;

    // Point to the right
    if (p.x > (r.topleft.x + r.weidth) )
        return false;

    // Point above
    if (p.y > r.topleft.y)
        return false;

    // Point below
    if (p.y < (r.topleft.x  + r.weidth ))
        return false;

    return true;
}

// ter certeza se um triangulo colide com outro, caso colisao
bool overlaps(const Rectangle & a, const Rectangle & b){

/*
	// uma boa soluçao seria usar a funcao inside, e testar para ambos,
	// se a estiver em b, ou parte te b estiver em a, temos um overlap

	//test if topleft os a is inside of b
	if(inside(a.topleft, b))
		return true;

	// test if topright of a is inside of b
												// same of a, because segue a reta y
	Point a_topright = {a.topleft.x + a.weidth, a.topleft.y};
	if(inside(a_topright, b))
		return true;

	Point a_bottoleft = {a.topleft.x, a.topleft.y - height};
	if(inside(a_bottoleft, b))
		return true;

	// Test if bottomright of a is indide of b

	// Test if topleft of b is inside a
	if(isInside(b.topleft, a))
		return true

	// teste

	//
*/
	// better way to check is laps

	// Check if a is below b, checa o ponto mais baixo de b com o mais auto de a
	if(a.topleft.y < (b.topleft.y - b.height))
		return false;

	// check if a if above b
	if(b.topleft.y < (a.topleft - a.height))
		return false;

	// Check if a if left of b
	if( (a.topleft + weidth) < b.topleft.x)
		return false

	// check if a is right of b
	if( a.topleft.x> b.topleft + b.weidth)
		return false;


	return true;

}

int main(int argc, char const *argv[])
{
    Rectangle a = { {2, 4}, 3, 2 };

    Point p = {3, 4};


    if (isInside(p, a))
    {
        cout << "p is inside a" << endl;
    }

    return 0;
}
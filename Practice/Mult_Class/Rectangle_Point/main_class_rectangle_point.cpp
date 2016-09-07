// Now, we've moved most functions outside of the classes, and moved the
// class (and struct) into seperate specification and implementation files.
//
// We compile with:
//
//    clang++ main.cpp Point.cpp Rectangle.cpp -o main

#include <iostream>

#include "Point.h"
#include "Rectangle.h"

using namespace std;


int main(int argc, char const *argv[])
{

    Point q = {2, 4};
    Rectangle a(q, 3, 2);

    Point p = {3, 4};

    cout << "p: " << p << endl;
    cout << "a: " << endl
         << a << endl;

    if (a.contains(p))
    {
        cout << "p is inside a" << endl;
    }

    return 0;
}


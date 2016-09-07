#include <iostream>

#include "smallest.h"

using namespace std;

// we can use template to determine a class and method
// ex

template <typename T>
struct Point
{
	T x;
	T y;
};

int main(int argc, char const *argv[])
{
	int a =3;
	int b = 5;

	Point <int> pt; // especifica o tipo T da struct

	Point <Point<int> > funny; // it becomes a pointer for integer, the we have to do funny.x.x to get he integer

	cout<<smallest(a,b) <<endl;
	return 0;
}
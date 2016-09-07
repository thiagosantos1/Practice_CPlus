#include <iostream>
// doing the same of the program point_file, but using struct to save the cordenaadas (x,y)
using namespace std;

struct Point // abstract Data type - ADT - like object - (int, double... is primative data type)  
{
	int x;
	int y;
	//int z; // after criate everyhitng, we cant put more members, at any time of the program.
	       // and doesn't change anything at the code

};

void print(const Point & p){ // passing by reference(&), to don't spend time passing the copy

	cout<< '(' <<p.x <<", " <<p.y <<')';
}

bool isEqual(const Point & lhs, const Point & rhs){

	return (lhs.x == rhs.x && lhs.y==rhs.y); // return true or false automactilly 
}



int  main(int argc, char const *argv[])
{

	Point a;
	Point b = {2,4};

	a.x =3;
	a.y=6;


	// you cannot do the follow commands with Struct
	/*

		if(a!=b)
		cout <<a


	*/

	print(a);
	cout<<endl;


	return 0;
}
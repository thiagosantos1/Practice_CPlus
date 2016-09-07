// Lab 07
// Thiago Santos
// 2015/09/25

#include <iostream>
#include "number_array.h"
using namespace std;

int main(int argc, char const *argv[])
{

	Array arrayA(15);
	Array arrayB(20);

	arrayA.displayArray();

	arrayA.initializeArray(1);
	arrayB.initializeArray(1);

	arrayA.displayArray();
	arrayB.displayArray();

	arrayA.setNumber(3,54);
	arrayA.setNumber(10,12);
	arrayA.setNumber(15,-20);
	arrayB.setNumber(4,44);
	arrayB.setNumber(20,53);
	arrayB.setNumber(1,-99);

	cout<<"The highest value in array A is: " << arrayA.getHighest() << endl;
	cout<<"The highest value in array B is: " << arrayB.getHighest() << endl;

	cout<<"The lowest value in array A is: " << arrayA.getLowest() << endl;
	cout<<"The lowest value in array B is: " << arrayB.getLowest() << endl;

	cout<<"The average in array A is: " << arrayA.getAverage() << endl;
	cout<<"The average in array B is: " << arrayB.getAverage() << endl;

	cout<<"Final values in the arrays\n" <<endl;

	arrayA.displayArray();
	arrayB.displayArray();
	
	return 0;
}
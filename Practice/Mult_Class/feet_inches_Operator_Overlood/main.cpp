#include <iostream>
using namespace std;

#include "feet_inches.h"

int  main(int argc, char const *argv[])
{
	FeetInches warn(5,9);
	FeetInches yaoming(7,6);

	cout << "Warn " << warn <<endl;

	cout << "Total: " << warn + yaoming << endl;

	cout << "Difference: " << yaoming -  warn << endl;

	cout << "twice : " << yaoming * 2 << endl;

	if(warn < yaoming)
		cout <<"warn is shorter thatn yaoming";

	// want to get the inches and put in the feet
	// 12 inches = 1 feet
	// in this case would be 5.75 feet
	cout <<"Warm in decimal feet" << double(want) << endl;
	// or could use like that
	double totalFeet = double(warn);
					// explicit
	cout<< 3.5 + (double)warm <<endl;

	cout<<warm++ <<endl;

	cout<<++yaoming <<endl;


	return 0;
}
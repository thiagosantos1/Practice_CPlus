// Lab 07
// Thiago Santos
// 2015/09/25

#ifndef NUMBER_ARRAY_H
#define NUMBER_ARRAY_H


#include <iostream>

class Array
{
public:
	Array(const int SIZE);

	Array();

	void initializeArray(int value);
	void setNumber(int number, int index);
	int getNumber(int index);
	int getHighest();
	int getLowest();
	double getAverage();
	void displayArray();


	~Array();

private:
	int *array;
	int SIZE;
	
};



#endif
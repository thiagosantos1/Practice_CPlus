// Lab 07
// Thiago Santos
// 2015/09/25

#include <iostream>
#include "number_array.h"
using namespace std;

Array::Array(const int size_in){

	SIZE = size_in;
	array = new int[SIZE];


}

Array::Array(){

	SIZE = 10;
	array = new int[SIZE];

}

void Array::initializeArray(int value){


	for(int index = 0; index < SIZE; index++){

		array[index] = value;	
	}
	

}

void Array::setNumber(int index, int  number){

	if (index <=SIZE && index >0)
		array[index -1] = number;

}

int Array::getNumber(int index){

	if (index >SIZE-1)
		return 0;
	else
		return array[index];

}

int Array::getHighest(){

	int highest = -10000;

	for(int index = 0; index < SIZE; index++){
		if (array[index] >= highest)
		{
			highest = array[index];
		}
	}
	
	return highest;

}

int Array::getLowest(){

	int lowest = 10000;

	for(int index = 0; index < SIZE; index++){
		if (array[index] <= lowest)
		{
			lowest = array[index];
		}
	}
	
	return lowest;

	

}

double Array::getAverage(){

	double average = 0.0;

	for(int index = 0; index < SIZE; index++){
	
			average += array[index];
	}
	
	return average/(double)SIZE;
}

void Array::displayArray(){

	cout<<"Array values" <<endl;
	for(int index = 0; index < SIZE; index++){
	
			cout<< array[index] << " ";
			if( (index +1) %5 == 0)
				cout<<endl;
	}
	cout <<endl <<endl;

}


Array::~Array(){

	delete [] array;

}



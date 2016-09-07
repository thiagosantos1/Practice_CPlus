#include <iostream>
using namespace std;


class InvalidSize{}; // to handle the constructor error


class Array{

public:
	Array(int size){
		// can handle expection in classes/constructor
		if (size < 1)
			throw InvalidSize();


		data = new int[size];
	}

	~Array(){

		delete [] data;
	}

private:
	int * data;
};


int main(int argc, char const *argv[]){

	int size;
	cout<< "How many number: ";
	cin>> size;

	// user could enter a negative value to make a new array, it'll crash the program
	try{
		Array a(size);

		// do anything we have to do with the array
	}
	catch(InvalidSize i){

		cout<< "You can't make arrays of that size" <<endl;

	}
	



	return 0;
}
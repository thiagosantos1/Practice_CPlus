#include <iostream>

using namespace std;

class Bunch
{
public:
	Bunch(){

		capacity =10;
		data =  new int[capacity];
		count =0;
	}

	// Copy constructcor

	Bunch( const Bunch & other){

		capacity = other.capacity;
		count = other.count;
		data = new int[capacity];
		for (int i = 0; i < count; i++)
		{
			data[i] = other.data[i];
		}
	}

	// assignment operator, to use with coppy constrctor
	Bunch & operator=(const Bunch & other){

		capacity = other.capacity;
		count = other.count;

		delete [] data; // delete the old array first, before copy a new one

		data = new int[capacity];

		for (int i = 0; i < count; i++)
		{
			data[i] = other.data[i];
		}

		return *this;
	}

	void append(int n){

		if (count == capacity)
		{
			// thre's no more room

			int * temp = new int[capacity * 2];

			for (int i = 0; i < count; i++)
				temp[i] = data[i];

			delete [] data;

			data = temp;

			// don't delete [] temp, because delete means delete what the pointer is pointing, so the array in the heap, temp and data
			// is just a variable name, in the stack. so if we delete [] temp we will delete the array that data is pointer now
		}
		
		data[count++] = n;
	}

	int & operator[](int index){

		return data[index];
	}

	void remove(int index){

		for (int i = index +1; i < count; i++)
		{
			data[i-1] = data[i];

		}
		count--;
	}


	~Bunch(){

		delete [] data;
	}

private:

	int * data;
	int count;
	int capacity;
	
};

int main(int argc, char const *argv[])
{
	Bunch b;



	for (int i = 0; i < 15; ++i)
	{
		b.append(i);
	}

	for (int i = 0; i < 15; ++i)
	{
		cout<< b[i] <<endl;
	}

	Bunch c =b;



	return 0;
}
#include <iostream>

using namespace std;

// make the bunch class as a template, so then it can be a bunch of anything, shape, int, etc
template <typename T>
class Bunch
{
public:
	Bunch(){

		capacity =10;
		data =  new T[capacity];
		count =0;
	}

	// Copy constructcor

	Bunch( const Bunch & other){

		capacity = other.capacity;
		count = other.count;
		data = new T[capacity];
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

		data = new T[capacity];

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

			int * T = new T[capacity * 2];

			for (int i = 0; i < count; i++)
				temp[i] = data[i];

			delete [] data;

			data = temp;

			// don't delete [] temp, because delete means delete what the pointer is pointing, so the array in the heap, temp and data
			// is just a variable name, in the stack. so if we delete [] temp we will delete the array that data is pointer now
		}
		
		data[count++] = n;
	}

	T & operator[](int index){

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

	// no longer has a int data pointer, but now a T typy, can be int, double, etc
	T * data;
	int count;
	int capacity;
	
};

int main(int argc, char const *argv[])
{
	// it's mean, wherever it found T in the class Bunch, it'll remove and "put" int
	// or any other type you enter
	Bunch <int> b;



	for (int i = 0; i < 15; ++i)
	{
		b.append(i);
	}


	Bunch <int> c =b;

	c[3] = 100;

	cout<< b[3] << endl;

	/* ****** Here is where templates come to be userfuk */

	Bunch <float> d; // so now we can use the same class and has float to our bunch



	return 0;
}




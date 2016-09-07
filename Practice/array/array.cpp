#include <iostream>
using namespace std;


void printArray(const int array[], const int SIZE)
{
	for(int i=0; i<SIZE; i++){
		cout << array[i] << ' ';
	}
	cout << endl;


}
int main(){

	const int SIZE =10;

	int nums[SIZE] = {3,6,1,9,12};
	     //or
	int numbers[SIZE] = {1,2,3,4}; // the rest will be 0
	    // or
	int n[20] = {0};  // everything it will be 0
		// or
	int nu[] = {1,2,3,4,5};  // it will be declare a size of 5, not change
	
	printArray(numbers, SIZE);

	return 0;
}
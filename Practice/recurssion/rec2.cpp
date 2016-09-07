#include <iostream>
using namespace std;


bool inOrder(int nums[], int size, int start){

	if (start == size)
		return true;

	if(nums[start] >  nums[start +1])
		return false;

	return inOrder(nums, size, start+1);
}

int smallest(int nums[], int size, int start){

	if(start == size -1)
		return nums[start];

	int this_one = nums[start];
	int smallest_of_the_rest = smallest(nums, size, start+1)

	if(this_one < smallest_of_the_rest)
		return this_one;
	else
		return smallest_of_the_rest;

}

int smallest(int * start, int * stop){

	if(stop - start ==1)
		return *start;

	int this_one = *start;
	int smallest_of_the_rest = smallest(start+1, stop);

	if(this_one < smallest_of_the_rest)
		return this_one;
	else
		return smallest_of_the_rest;

}

int sum(int * begin, int * stop){

	if(start == stop)
		return 0;
		  // get the first position of the array
	return *start + sum(start+1, stop);
}

bool binarySearch(int * start, int * stop, int target){

	if(start == stop)
		return false;

	int difference = stop - start;
	int halfway =  difference / 2;

	int * middle = start + halfway;  // it's a pointer for the array

	if(*middle == target)  // if the value of the array in the middle is equal target
		return true;

	if(*middle > target)
		return binarySearch(start, middle, target); // search for the right
	else
		return binarySearch(middle + 1, stop, target);  // search for left

}

int main(int argc, char const *argv[])
{
	const int SIZE = 5;
	int nums[SIZE] = {1,2,3,4,5};

	if(inOrder(nums, SIZE, 30))
		cout<<"It's in order" <<endl;
	else
		cout<<"It's not in order" <<endl;

	cout<<sum(nums, nums+5); // gets the beggining of the array and the last position of the array


	return 0;
}
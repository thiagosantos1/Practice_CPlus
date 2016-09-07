#include <iostream>
using namespace std;

// not the best way
// shouldn't use temp array
void qSortWithTempArray(int * start, int * end){

	int size = end - start;

	if(size <=1) // base case
		return;

	int *middleArray = start+size/2;  // get the pointer for the middle of the array, in other words, the value store in the middle
	int * temp = new int[size];
	int next =0 ;

	// less then the middle
	for(int i=0; i<size; i++)
		if(start[i] < *mid)
			temp[next++] = start[i];
	qSort(start, start+next);
	start[next++] = * mid;
	int begin = next;
	// bigger than the middle

	for (int i = 0; i < size; i++)
		if(start[i] >= *mid)
			temp[next++] = start[i];
	qSort(start[begin], end);

	for(int i=0; i<size; i++)
		start[i] = temp[i];

	delete[] temp;


}

void swap(int &a, int &b){

	int t =;
	a=b;
	b = t;
}

/*
// best way, using swap the values
void qSort(int * start, int * end){

	int size = end - start;

	if(size <=1) // base case
		return;

	int middleArray = start+size/2;  // get the pointer for the middle of the array, in other words, the value store in the middle
	
	swap(mid, start[num_left])
	qSort(start, end);



}*/


int main(int argc, char const *argv[])
{
	
	return 0;
}
#include <iostream>


using namespace std;

void sayBoth(int n){


	if(n== 0){
		return;
	}

	else{

		cout<<"Hello" <<endl;
		sayBoth(n-1);
		cout<<"Goodbye" <<endl;
	}


}

void sayHello(int n){

	if (n==0)
		return;

	else{
		cout<<"Hello" <<endl;

		sayHello(n-1);
	}
}

bool contains(int nums[], int start, int size, int target){

	if(start == size)
		return false;  // element is not in array

	if(nums[start] == target)
		return true;

	return contains(nums, start+1, size, target);
}

void alternate(int n, bool startwWithHello){

	if(n==0){
		return;
	}

	else if(startwWithHello){

		cout<<"Hello" <<endl;
	}
	else{

		cout<<"Goodbye" <<endl;
	}

	alternate(n-1,!startwWithHello);

}

void totalArray(int nums[], int start, int size){

	if(start == size)
		return 0;

	return nums[start] + totalArray(nums, start+1, size);
}

int main(int argc, char const *argv[])
{

	const int SIZE =5;
	int nums[SIZE] = {3,51,22,7,9};

	if(contains(nums, 0, SIZE, 5))
		cout<<"Element is in the array"<<endl;
	else
		cout<<"Element is not in the array"<<endl;
	
	sayHello(5);
	cout<<"\n\n";
	sayBoth(3);
	cout<<"\n\n";

	alternate(3,true); // hello, goodbye,hello
	cout<<"\n\n";
	alternate(4,false);
	cout<<"\n\n";

	return 0;
}





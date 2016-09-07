// Thiago Santos
// 08/26/15
// Lab 01

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void createV(int );

int main(){

	int V_times=0;

	cout<< "\nHow many V do you want to print it? ";
	cin>>V_times;

	createV(V_times);

	cout<<endl;
	

	return 0;
}

void createV(int V_times){

	if(V_times >0){

		for(int i=0; i<=V_times; i++){

			cout<<"*   ";
		}

		cout<<endl;

		for(int i=0; i<V_times; i++){

			cout<<" * *";
		}

		cout<<endl;
		for(int i=0; i<V_times; i++){

			cout<<"  * ";
		}
		cout<<endl;

	}
	else{

		cout<<endl;
	}
}


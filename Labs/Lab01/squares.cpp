// Thiago Santos
// 08/26/15
// Lab 01

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){

	int numb_charct=0;

	while(numb_charct <1){

		cout << "How many starst and time do you want to print? Must be >= 1 ";
		cin >> numb_charct;
	}

	for(int i=0; i<numb_charct ; i++){

		for(int j=0; j<numb_charct; j++){

			cout<<'*';
		}
		cout<<endl;
	}
		

	cout<<endl;
	

	return 0;
}
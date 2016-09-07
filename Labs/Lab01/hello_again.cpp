// Thiago Santos
// 08/26/15
// Lab 01

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main(){

	string name="";
	int times=0;

	cout<< "What's your name? ";
	cin>>name;
	cout<< "\nHow many time do you want to print it? ";
	cin>> times;

	for(int i=0; i<times ; i++)
		cout<<"\n" << name;

	cout<<endl;
	

	return 0;
}
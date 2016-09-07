// Thiago Santos
// Lab 08
// 09/30/ 2015


#include <iostream>
#include "number.h"

using namespace std;

int  main(int argc, char const *argv[])
{

	Number numb1;
	int number =-1;

	cout<< "\n\t\tWelcome to the trasnaler program\n" <<endl;
	cout<< "Please, enter a number to translate to English and Italian(0 - 9999)" <<endl;
	
	while(number <0 || number > 9999){
		cout<< "Number : ";
		cin>> number;
	}

	numb1.setNumber(number);

	cout<<"\n\tEnglish" << endl;
	cout << numb1.getNumber() << " = " << numb1.inEnglish() << endl;

	cout<<"\n\tPortuguese" << endl;
	cout << numb1.getNumber() << " = " << numb1.inPortuguese() << endl << endl;

	
	return 0;
}
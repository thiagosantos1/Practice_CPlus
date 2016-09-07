#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

int main(int argc, char const *argv[]){

	Employee arrayEmployee[3];
	Employee empl1("Susan Meyers", 48927 ,"Accounting" ,"Vice President");
	Employee empl2("Mark Jonesee", 39482, "IT", "Programmer");
	Employee empl3("Joy Rogers", 29841, "Manufacturing", "Engineer");

	cout<< "_________________________________________________________________________\n"
		<< "|\tName\t\t|   ID Number\t\t|   Department\t\t|   Position\t\t|\n" 
		<< "_________________________________________________________________________" << endl;

	empl1.printReport();
	empl2.printReport();
	empl3.printReport();

	cout<<endl<<endl;
	
	return 0;
}
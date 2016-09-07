// Thiago Santos
// Lab06
// 2015/09/22

#include <iostream>
# include <string>
# include <iomanip>
#include "employee.h"

using namespace std;



Employee::Employee(string name_in, int id_number_in, string department_in, string position_in){

	name = name_in;
	id_number = id_number_in;
	department = department_in;
	position = position_in;

}

Employee::Employee(string name_in, int id_number_in){

	name = name_in;
	id_number = id_number_in;
	department = " ";
	position = " ";

}

Employee::Employee(){

	name = " ";
	id_number = 0;
	department = " ";
	position = " ";

}

string Employee::getName() const{
	return name;
}

void Employee::setName(string name_in){
	name = name_in;
}

string Employee::getDepartment() const{
	return department;
}

void Employee::setDepartment(string department_in){
	department = department_in;
}

string Employee::getPsition() const{
	return position;
}

void Employee::setPsotion(string position_in){
	position = position_in;
}

void Employee::printReport(){

	cout<< name << "\t\t\t"<< id_number << "\t\t\t" << setfill(' ') <<setw(8) <<department 
				<< "\t\t\t" << position <<  endl;

}




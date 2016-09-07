// Thiago Santos
// Lab05
// 2015/09/19

#include <iostream>
# include <string>
# include <iomanip>

using namespace std;

class Employee{

public:

	Employee(string name_in, int id_number_in, string department_in, string position_in){

		name = name_in;
		id_number = id_number_in;
		department = department_in;
		position = position_in;

	}

	Employee(string name_in, int id_number_in){

		name = name_in;
		id_number = id_number_in;
		department = " ";
		position = " ";

	}

	Employee(){

		name = " ";
		id_number = 0;
		department = " ";
		position = " ";

	}

	string getName() const{
		return name;
	}

	void setName(string name_in){
		name = name_in;
	}

	string getDepartment() const{
		return department;
	}

	void setDepartment(string department_in){
		department = department_in;
	}

	string getPsition() const{
		return position;
	}

	void setPsotion(string position_in){
		position = position_in;
	}

	void printReport(){

		cout<< name << "\t\t\t"<< id_number << "\t\t\t" << setfill(' ') <<setw(8) <<department 
					<< "\t\t\t" << position <<  endl;

	}


	
private:
	string name;
	string department;
	string position;
	int id_number;
	
};

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
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>


class Employee{

public:

	Employee(std::string name_in, int id_number_in, std::string department_in, 
			std::string position_in);

	Employee(std::string name_in, int id_number_in);

	Employee();

	std::string getName() const;

	void setName(std::string name_in);

	std::string getDepartment() const;

	void setDepartment(std::string department_in);

	std::string getPsition() const;

	void setPsotion(std::string position_in);

	void printReport();


	
private:
	std::string name;
	std::string department;
	std::string position;
	int id_number;
	
};


#endif
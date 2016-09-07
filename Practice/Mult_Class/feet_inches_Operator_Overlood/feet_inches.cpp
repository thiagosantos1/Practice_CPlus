#include "feet_inches.h"
#include <iostream>
 
using namespace std;

FeetInches::FeetInches(int feet_in, int inches_in){

	feet = feet_in;
	inches = inches_in;
	simplify();

}

FeetInches FeetInches::operator+(const FeetInches & other) const{

	int total_feet =  feet + other.feet;
	int total_inches = inches + other.inches;

	FeetInches returnFeet(total_feet, total_inches );
	returnFeet.simplify();

	return returnFeet;
}

FeetInches FeetInches::operator-(const FeetInches & other) const{

	
	int my_total_inches = feet * 12 + inches;
	int other_total_inches = other.fee * 12 + other.inches;

	// simplify is gonna run in the constructor
	FeetInches returnFeet( 0 , total_feet - total_inches);

	

	return returnFeet;
}

FeetInches& FeetInches::operator=(const FeetInches & other) {

	feet = other.feet;
	inches = other.inches;

	return * this;
}

FeetInches& FeetInches::operator*(int rhs) {

	return FeetInches(feet * rhs, inches * rhs);
}

bool FeetInches::operator<(const FeetInches & other) const {

	int my_total_inches = feet * 12 + inches;
	int other_total_inches = other.fee * 12 + other.inches;

	return my_total_inches < other_total_inches;


}


FeetInches::operator double() const{

	double result = feet;
	result + = double(inches) / 12;

	return result;
}

FeetInches::operator double() const{

	double result = feet;
	result + = double(inches) / 12;

	return result;
}

FeetInches FeetInches::operator++(){

	inches++;
	simplify();
	return *this;

}

FeetInches FeetInches::operator++(int ){

	// make the copy to return the post increment
	FeetInches temp(feet, inches);
	inches++;
	simplify();
	return temp;

}

void FeetInches::simplify(){

	while(inches >=12){

		inches -=12;
		feet +=1;
	}
}

ostream& operator<<(ostream & out, const FeetInches & fi){

	out << fi.feet << " feet, " << fi.inches << " inches";

	return out;
}

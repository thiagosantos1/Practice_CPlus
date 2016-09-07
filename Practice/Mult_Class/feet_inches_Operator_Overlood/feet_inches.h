#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>

class FeetInches{

public:

	FeetInches(int feet, int inches);

	// quando soma, o retorno é outro objeto, que é o resultado da operaçao
	FeetInches operator+(const FeetInches & other) const;
	FeetInches operator-(const FeetInches & other) const;

	// here it's the diferent thing about this exercise, when you need to return
	// a new object, that actually is the object that you just change
	FeetInches& operator=(const FeetInches & other)  ;

	FeetInches operator*(int rhs) const ;
	bool operator<(const FeetInches & other) const ;

	friend std::ostream operator <<(std::ostream & out, const FeetInches & fi);

	// different overload Syntax, no return and space after operator
	// it tells the compile how to convert int inches and convert to feet
	// but i can make messy, can change the value for other thing

	explicit // it avoid troubles, because then we have to say we want to use that operator
	operator double () const

	// Thing++
	FeetInches operator++(int);

	// ++ Thing
	FeetInches operator++();


private:

	void simplify();
	int feet;
	int inches;


};



#endif
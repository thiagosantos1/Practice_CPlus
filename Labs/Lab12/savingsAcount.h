#ifndef SAVINGS_H
#define SAVINGS_H

#include "bank.h"

class SavingsAcount : public Bank{

public:
	SavingsAcount(double,double);

	virtual void deposit(double);

	virtual void withdraww(double);

	virtual void monthlyProc();

	void setStatus();

	int getStatus();

	//std::string getAccountType();


	//~SavingsAcount();

private:

	int status;   // it's 1 if it's an active account
				 // it's 0 if it's an inactive account - balance below than 25
	
	
};

#endif
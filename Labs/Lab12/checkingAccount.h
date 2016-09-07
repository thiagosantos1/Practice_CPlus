#ifndef CHEKING_H
#define CHEKING_H

#include "bank.h"

class CheckingAccount : public Bank{

public:
	CheckingAccount(double,double);

	virtual void withdraww(double);

	virtual void monthlyProc();

	//std::string getAccountType();

private:

	//std::string accountType;
	
};

#endif
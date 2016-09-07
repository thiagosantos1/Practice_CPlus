#include <iostream>
#include <string>
#include "bank.h"
#include "savingsAcount.h"
#include "checkingAccount.h"


void deposit(Bank *);
void withdraw(Bank *);

int main(int argc, char const *argv[])
{

	// create 2 acco10unt, both of them starting with balance = 1000 and interest = 
	Bank * account[2] = {0};

	account[0] = new SavingsAcount(1000,10);
	account[1] = new CheckingAccount(1000,10);


	std::cout<<"\n          Welcome to CISS 245 Bank\n" <<std::endl;;

	std::cout<<"Both accounts(Savings and Checking) start with a balance = 1000 and the annual interest rate = 10%%\n"<<std::endl;

	deposit(account[0]);
	withdraw(account[0]);
	account[0]->monthlyProc();
	account[0]->printMontlyStatistics();


	deposit(account[1]);
	withdraw(account[1]);
	account[1]->monthlyProc();
	account[1]->printMontlyStatistics();


	//savAcct.printMontlyStatistics(savAcct.getAccountType());

	

	
	return 0;
}


void deposit(Bank * account){

	int depositsQtd = -1;

	double depositValue =-1;


	std::cout<<"For " + account->getAccountType() <<" account, how many deposits do you want to do?" <<std::endl;

	while(depositsQtd <0)
		std::cin>>depositsQtd;

	for (int i = 0; i < depositsQtd; i++)
	{
		std::cout<<"Please, enter the amount for the deposit(must be a posite value) " << i+1 <<" :"; 
		
		while (depositValue <=0)
			std::cin>> depositValue;

		account->deposit(depositValue);

		depositValue = - 1; // set negative for the next loop

	}


}

void withdraw(Bank * account){

	int withdrawQtd = -1;

	double withdrawValue =-1;

	std::cout<<"How many withdraw do you want to do(cannot be a negative value)?" <<std::endl;

	while(withdrawQtd <0)
		std::cin>>withdrawQtd;

	for (int i = 0; i < withdrawQtd; i++)
	{
		std::cout<<"Please, enter the amount for the withdraw(must be a posite value) " << i+1 <<" :"; 
		
		while (withdrawValue <=0)
			std::cin>> withdrawValue;

		account->withdraww(withdrawValue);

		withdrawValue = - 1; // set negative for the next loop

	}


}









#include <iostream>
#include "bank.h"
#include "savingsAcount.h"



SavingsAcount::SavingsAcount(double balance_in, double anuualInterest_in)
				: Bank(balance_in, anuualInterest_in){

					setStatus(); // set the status for the account

					accountType = "Savings";

				}

void SavingsAcount::setStatus(){

	if(getBalance() < 25)
		status = 0; // inactive account
	else
		status = 1;
}

/*
string SavingsAcount::getAccountType(){

	return accountType;
}
*/

int SavingsAcount::getStatus(){

	return status;
}

void SavingsAcount::withdraww(double amount){

	if (status == 1) // check to see if account is active
	{
		Bank::withdraww(amount); // call the parent method
		setStatus(); // set a new status

	}

}

void SavingsAcount::deposit(double deposit){

	Bank::deposit(deposit);  // make the deposit

	setStatus();  // then, update the status by cheking the new balance

}

void SavingsAcount::monthlyProc(){

	if (getNumberWithdraws() >4)
	{
		int withdrawwsCharged = getNumberWithdraws() - 4;

		// set 1 dolar for each more than 4 withdraw made in that month
		setMontlyServiceCharges(withdrawwsCharged);
	}

	Bank::monthlyProc(); // deduce the monthly charges for that account

	setStatus(); // update the status;


}









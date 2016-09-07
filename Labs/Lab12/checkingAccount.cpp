#include <iostream>
#include "bank.h"
#include "checkingAccount.h"



CheckingAccount::CheckingAccount(double balance_in, double anuualInterest_in)
				: Bank(balance_in, anuualInterest_in){

					accountType = "Checking";

				}

/*
string SavingsAcount::getAccountType(){

	return accountType;
}*/

void CheckingAccount::withdraww(double amount){

	if(getBalance() - amount <0){

		// if withdraw make account balance being negative, Bank charges customer $15
		setBalance(getBalance() - 15);
	}

	Bank::withdraww(amount); // make the withdraw

}


void CheckingAccount::monthlyProc(){

	double monthlyCharged = 5 + (getNumberWithdraws() * 0.1);

	setMontlyServiceCharges(monthlyCharged);

	Bank::monthlyProc(); // deduce the monthly charges for that account



}









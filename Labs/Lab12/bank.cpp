# include <iostream>
# include "bank.h"

using namespace std;

Bank::Bank(double balance_in , double anuualInterest_in){ // set default valor for 10

	balance = balance_in;

	balanceBeginMonth = balance;

	anuualInterest = anuualInterest_in;

	number_deposits = 0;

	number_withdraws = 0;

	montlyServiceCharges = 0;


}

Bank::Bank(){

	Bank::Bank(0,10); // call parent constructor with default values
				// set default valor of interest for 10 

}

void Bank::deposit(double deposit){

	balance += deposit;
	increaseDeposits();
}

void Bank::increaseDeposits(){

	number_deposits++;

	montlySavedDeposits = number_deposits; // save the number of deposits for the last month with deposits variable
}

void Bank::withdraww(double amount){

	balance -= amount;
	increaseWithdraw();

}

void Bank::increaseWithdraw(){

	number_withdraws++;

	montlySavedWithDraws = number_withdraws; // save the number of withdraws for the last month with draws variable
}

double Bank::getBalanceBeginMonth() const{

	return balanceBeginMonth;
}

double Bank::getBalance() const{

	return balance;
}

void Bank::setBalance(double new_balance){

 	balance = new_balance;
}

double Bank::getAnuualInterest() const{

	return anuualInterest;
}

void Bank::setAnuualInterest(double anuualInterest_in){

 	anuualInterest = anuualInterest_in;
}

void Bank::calcInt(){

	double interest = anuualInterest/100; // we get in percentage, has to put it in number
	double monthlyRate = interest/12;
	double monthlyInterest = monthlyRate * balance;
	balance += monthlyInterest;
}

void Bank::monthlyProc(){

	balance -= montlyServiceCharges;
	calcInt();

	// save the values of last month
	montlySavedWithDraws = number_withdraws;
	montlySavedDeposits = number_deposits;
	savedMonthlyServiceCharges = montlyServiceCharges;

	// reset for the next month
	number_deposits = 0;
	number_withdraws = 0;
	montlyServiceCharges =0;
}

int Bank::getMontlySavedWithDraws() const{

	return montlySavedWithDraws;

}

int Bank::getMontlySavedDeposits() const{

	return montlySavedDeposits;

}

double Bank::getSavedMonthlyServiceCharges() const{

	return savedMonthlyServiceCharges;

}

int Bank::getNumberDeposits() const{

	return number_deposits;

}

int Bank::getNumberWithdraws() const{

	return number_withdraws;

}

void Bank::setMontlyServiceCharges(double newCharged){

	// it sets any  new charged for the account
	montlyServiceCharges += newCharged;


	savedMonthlyServiceCharges = montlyServiceCharges; // save the value of service charges for the last month with charges variable

}

double Bank::getMontlyServiceCharges(){

	return montlyServiceCharges;

}

string Bank::getAccountType(){

	return accountType;
}

void Bank::printMontlyStatistics(){

	cout<<"\n--------------------------------------------------------" <<endl;
	cout<<"          "<< getAccountType() <<" Account Statistics Report" <<endl;
	cout<<"--------------------------------------------------------\n" <<endl;
	cout<<"     The begin balance in this month was: $" << getBalanceBeginMonth() <<endl;
	cout<<"     Total of deposits in this month: " << getMontlySavedDeposits() <<endl;
	cout<<"     Total of withdrawls in this month: " << getMontlySavedWithDraws() <<endl;
	cout<<"     Total of Services charged for this month: $"<< getSavedMonthlyServiceCharges() <<endl;
	cout<<"     The final balance for this month is: $" << getBalance() <<endl<<endl;
}





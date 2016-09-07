#ifndef BANK_H
#define BANK_H


class Bank{

public:
	Bank(double,double);

	Bank();

	virtual void deposit(double);

	void increaseDeposits();

	virtual void withdraww(double);

	void increaseWithdraw();

	virtual void calcInt();

	virtual void monthlyProc();

	virtual double getBalanceBeginMonth() const;

	virtual double getBalance() const;

	virtual void setBalance(double);

	virtual int getNumberDeposits() const ;

	virtual int getNumberWithdraws() const ;

	// function set any new montly charged for the account
	virtual void setMontlyServiceCharges(double) ;

	virtual double getMontlyServiceCharges();

	virtual double getAnuualInterest() const;

	virtual void setAnuualInterest(double);

	virtual std::string getAccountType();

	virtual void printMontlyStatistics();

	virtual double getSavedMonthlyServiceCharges() const;

	virtual int getMontlySavedWithDraws() const;

	virtual int getMontlySavedDeposits() const;





//	~Bank();


	

protected:

	double balance;
	double balanceBeginMonth;
	double anuualInterest;
	int number_deposits;
	int number_withdraws;
	double montlyServiceCharges;

	// These 3 variables save the information of number_deposit, withdraws, and service charges for that month
	// it'll always have thoso values for that month, and it'll reset when the monthly calc charges is made, changing the value
	// for the new ones
	int montlySavedWithDraws;
	int montlySavedDeposits;
	double savedMonthlyServiceCharges;

	std::string accountType;

	
};



#endif
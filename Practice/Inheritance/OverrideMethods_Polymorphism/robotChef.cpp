#include <iostream>
#include <string>
using namespace std;

// Class Robot
class Robot
{
public:

	// use virtual to make the compile to decide in run time, each method
	// is gonna use, from parent, child, etc, because we're gonna override this
	// method on children
	virtual void beep() const{

		cout<< "Beep" <<endl;
	}

	void takeJobs() const{

		cout<<"Human job eliminated" <<endl;
	}

};


// Here is where inheritance is good, because you can have different type of robots
// and in this case we can see that it's not logical to put a ChefRot to be able to shot
class Chefbot : public Robot{
public:

	void cook() const{
		cout<< "Robot makes breakfast" << endl;
	}

	// overriden the method beep from class Robot
	virtual void beep() const { 
		cout << "Bam" << endl;
	}

};

class FreechChefBot : public Chefbot{

public:
	void sautee() const {
		cout<< "Sauteeing same foodd" <<endl;
	}
};

// Polymorphism
void beep_three_times(const Robot & r){

	r.beep(); r.beep(); r.beep();
	// in this case, if we pass a cheef robot or anything else not Robot,
	// it'll always call Robot function, the parent method, and forget about
	// the overload, because everything is a Robot

	// To fix that, we have to use a new keyword in front of the function
	//       virtual returnType nameFunction()
	//  See in class Robot and child


}

int main(int argc, char const *argv[])
{

/*
	Robot r;
	r.beep();
	r.takeJobs();

	Chefbot c;
	c.takeJobs(); // didn't override
	c.beep();  // it overrided
	c.cook();

	FreechChefBot f;
	f.beep();
	f.takeJobs();
	f.beep(); // it use the method from ChefBot, because it inheritance from there
	// to use from super class we can to specify.
	f.sautee();

	*/

	//  To solve the polymorphism problem, we have to use dynamic allocation
	// to solve the Virtual run time problem, mentioned in method beep_thee_times()
	// For that we use pointer to alocate dinamic class
	// because dynamic dispatch and virtual disatch works with pointers and reference
	// if we don't create the class as a pointer, and if we have diferent robots
	// in an array for example, when you click robot.beep(), it'll always take
	// the parent method, but if we use pointer, it knows the type of each one in memory
	// then each one can use their own method
	// ex

	Robot * robots[5] = {0};

	for (int i = 0; i < 5; i++)
	{
		char choice;
		cout<< "choose robot type: r or c" << endl;
		cin>> choice; 

		if(choice == 'r')
			robots[i] = new Robot();
		else
			robots[i] = new Chefbot();

	}

	for (int i = 0; i < 5; i++)
	{
		robots[i]->beep();
	}

	for (int i = 0; i < 5; i++)
	{
		robots[i]->beep();
	}



	
	

	
	return 0;
}





#include <iostream>
#include <string>
using namespace std;

// Class Robot
class Robot
{
public:

	Robot(string name_in){

		name = name_in;
	}
	void beep() const{

		cout << "Robot" << name << " beeps "<<endl;
	}
	string getName() const{
		return name;
	}

// it's a specifier that makes all members privates for outside of the class
// but make them public for who inheritance the class( For the childrens)
protected:
	string name;

};

// Class Warbot that inheretance from Robot
// it's means Warbot is a Robot as well and can use and overload Robot methods
class Warbot : public Robot
{
public:
	// have to call parent constructor to initialize what we have in robot
	// : Robot(name_in) is the command to call the parent constructor
	// then you can put " , " and the what you're gonna initialize inside of 
	// this class, like ammo
	Warbot(string name_in, int ammo_in) 
		: Robot(name_in), ammo(ammo_in)
	{
	

	}
	void shoot() {

		cout << "Robot " << name << " shoots: Blam!" << endl;
		cout  << "Robot has" << ammo << endl;
		ammo--;
	}

protected:
	int ammo;

};


// Robot and Warbot can acess, because Warbot is also a Robot
void beepThereeTime(Robot & r){

	r.beep();
	r.beep();
	r.beep();
}

// Just Warbot can use, because Warbot is a Robot, but Robot is not a Warbot
void shootThereeTime(Warbot & w){

	w.beep();
	w.beep();
	w.beep();
}


/*
// Here is where inheritance is good, because you can have different type of robots
// and in this case we can see that it's not logical to put a ChefRot to be able to shot
class Chefbot : public Robot{
public:
	void cook() const{
		cout<< "Robot makes breakfast" << endl;
	}

};
*/

int main(int argc, char const *argv[])
{

	Robot r("Bot");
	r.beep();

	Warbot w("Evill", 10);
	w.beep();
	w.shoot();

	beepThereeTime(r);

	beepThereeTime(w);
	
	return 0;
}





#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

// serve para guardar as posicoes
struct Vec2D
{
	int x;
	int y;
	
};

// Structe is made to save data
// But Class, is made to save data and methods
// methods that change the class
class Robot
{
 // acess specifier, by defualt c++ define everthing inside of the class being private
 // then we have to change if we want to	
 public:

 	// constructor, you can as many you want to, like java
 	Robot(Vec2D init_posit, int energy_in, int size_in, string name_in)
 	{
 		position = init_posit;
 		energy = energy_in;
 		ammo = 10; // it'll ayways be 1
 		size = size_in;
 		name = name_in;

 	}

 	// colocando a funçao dentro da classe
 	// override
 	void move(Vec2D v)
	{
		position.x += v.x;
		position.y += v.y;

	}


	void shoot(Robot & target)
	{
		if(ammo <=0){

			cout<<name <<" tries to shoot, but is out of ammo" <<endl;
			return;
		}

		ammo -=1;

		// check the range - the shoot go just until 10

		int dx = position.x - target.position.x;
		int dy = position.y - target.position.y;
		double range = sqrt(dx *dx + dy *dy);

		if(range >10){

			cout<< name<< " shoot, but target is out of range" <<endl;
			return;
		}

		cout<<name<<" hits "<<target.name <<endl;

		target.energy -=5;



	}

	bool isAlive()
	{
		return (energy >0);
	}

	string getName()
	{
		return name;
	}

	Vec2D getPosition(){
		return position;
	}




private: 

	// position of the robot
	Vec2D position; 
	// Durability
	int energy;

	// Ammo count
	int ammo;

 
	// Size of the robot
	int size;

	string name;

};
						// how much you're gonna change in direction x and y


Vec2D makeRandomMove(){

	int rand_move_x = rand() % 11 -5;
	int rand_move_y = rand() % 11 -5;
	Vec2D result = {rand_move_x, rand_move_y};

	return result;
}

int main(int argc, char const *argv[])
{
	srand(time(0));

	// a and b are object now, instance of the class Robot
	Vec2D v1 = {10,20};
	//using constructor
	Robot a (v1, 13, 3, "a");
	Vec2D v2 = {40,60};
	//using construtor
	Robot b ( v2, 15, 2, "b");

	while(true)
	{

		// after, using a member function, both of them are duing the same think
		a.move(makeRandomMove());
		cout<<a.getName() <<" moved to " << a.getPosition().x <<", " <<a.getPosition().y <<endl;

		// after change for member function
		a.shoot(b);
		if(b.isAlive()){
			cout<< b.getName()<<" blew up" <<endl;
			break;
		}

		b.move(makeRandomMove());
		cout<<b.getName() <<" moved to " << b.getPosition().x <<", " <<b.getPosition().y <<endl;

		b.shoot(a);
		if(a.isAlive()){
			cout<< a.getName()<<" blew up" <<endl;
			break;
		}

	}


	
	return 0;
}
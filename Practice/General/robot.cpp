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

struct Robot
{
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
void moveRobot(Robot & r, Vec2D v)
{
	r.position.x += v.x;
	r.position.y += v.y;

}

void shoot(Robot & shooter, Robot & target)
{
	if(shooter.ammo <=0){

		cout<<shooter.name <<" tries to shoot, but is out of ammo" <<endl;
		return;
	}

	shooter.ammo -=1;

	// check the range - the shoot go just until 10

	int dx = shooter.position.x - target.position.x;
	int dy = shooter.position.y - target.position.y;
	double range = sqrt(dx *dx + dy *dy);

	if(range >10){

		cout<< shooter.name<< " shoot, but target is out of range" <<endl;
		return;
	}

	cout<<shooter.name<<" hits "<<target.name <<endl;

	target.energy -=5;



}

Vec2D makeRandomMove(){

	int rand_move_x = rand() % 11 -5;
	int rand_move_y = rand() % 11 -5;
	Vec2D result = {rand_move_x, rand_move_y};

	return result;
}

int main(int argc, char const *argv[])
{
	srand(time(0));
	Robot a = { {10, 20}, 15, 10, 3, "a"};
	Robot b = { {40, 60}, 10, 10, 2, "b"};

	while(true)
	{
		
		moveRobot(a, makeRandomMove() );
		cout<<a.name <<" moved to " << a.position.x <<", " <<a.position.y <<endl;

		shoot(a,b);
		if(b.energy <=0){
			cout<< b.name<<" blew up" <<endl;
			break;
		}

		moveRobot(b, makeRandomMove() );
		cout<<b.name <<" moved to " << b.position.x <<", " <<b.position.y <<endl;

		shoot(b,a);
		if(a.energy <=0){
			cout<< a.name<<" blew up" <<endl;
			break;
		}

	}


	
	return 0;
}
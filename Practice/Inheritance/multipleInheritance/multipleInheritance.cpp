# include <iostream>
using namespace std;

class Mom
{
public:
	void doMomStuff(){ cout << "Mom" << endl;}
	void doParentStuff() {cout << "Parent stuff from mom" <<endl;}
};

class Dad
{
public:
	void doDadStuff(){ cout << "Dad" << endl;}
	void doParentStuff() {cout << "Parent stuff from Dad" <<endl;}

};

class Child: public Mom, public Dad
{
public:
	void doChildStuff() { cout <<"Child" << endl}
	void doParentStuff() {Dad::doParentStuff();} // have to specify, because there're 2 and compile doesn't know with one
												// to call. Or we have to override
;

int main(int argc, char const *argv[])
{
	Child c;

	c.doMomStuff();
	c.doDadStuff();
	c.doChildStuff();



	return 0;
}
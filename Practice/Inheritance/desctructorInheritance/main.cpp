# include <iostream>
using namespace std;

class Parent{

public:

	Parent(){ cout<<"Parent Constructor" << endl; }
	virtual ~Parent(){ cout<<"Parenet Destructor" << endl; }  // important to use virtual as well
};

class Child : public Parent{

public:

	Child(){ 
		cout<<"Child Constructor" << endl; 
		data = new int[10]
	}
	virtual ~Child(){ // important to use virtual as well
		cout<<"Child Destructor" << endl; 
		delete [] data;
	} 

private:
	int * date

};

int main(int argc, char const *argv[])
{

	Parent *p1 = new Parent(); // runs just constructor


	Parent *p2 = new Child();   // it call parent and child constructor

	delete p1;

	delete p2;   // however, it doesn't run child destructor if we don'w virtual for destructor
				 // because p is a Parent, so then will delete in parent
				// then we have to use Virtual
	
	return 0;
}
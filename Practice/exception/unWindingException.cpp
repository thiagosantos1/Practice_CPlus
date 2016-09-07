#include <iostream>

using namespace std;

class Thing{
public:

	Thing(char c) {
		my_c = c
		cout<< my_c<<": constructor" <<endl;
	}

	~Thing(){

		cout<<my_c<<": destructor" <<endl;
	}

private:
	char my_c;


};

void a(){


	cout<< "Star a" <<endl;
	Thing x('x');

	// even though we thrwo an exception here, and the last lines one a, b, and c will not execute, the destructors
	// of each object runs anyway, because it goes out of the escope, you don't "have" to run the last lines of code
	// to run the destructors
	throw 5;

	cout <<"End a" <<endl;
}

void b(){


	cout<< "Star b" <<endl;
	Thing y('y');
	a();
	cout <<"End b" <<endl;
}

void c(){


	cout<< "Star c" <<endl;
	Thing z('z');
	b();
	cout <<"End c" <<endl;
}

int main(int argc, char const *argv[])
{
	try{
		c();
	}
	catch (int i){

		cout<<"caught"<<endl;
	}
	return 0;
}




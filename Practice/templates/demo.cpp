##include <iostream>

using namespace std;

template <typename T>
T smallest(T a, T b){

	if(a < b)
		return a

	return b;
}

class Foo
{
public:
	bool operator<(Foo & other){

		return true // just to test
	}

};


int main(int argc, char const *argv[])
{
	
	int x=1;
	int y =2;

	double a =6;
	double s = 9;

	cout<<smallest(x,y)<<endl;   // T is any type, so it works for int and double
	cout<<smallest(a,s)<<endl;

	Foo f;
	Foo g;

	Foo min = smallest(f,g);  // in this case, T will be Foo, and it'll works because we have overload the operator <, withou it, it doesn't wotk




	return 0;
}
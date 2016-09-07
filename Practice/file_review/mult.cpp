
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{

	if(argc != 3)
		return 1;

	int lhs = atoi(argv[1]); 
	int rhs = atoi(argv[2]);

	cout << lhs * rhs <<endl;

	return 0;
}
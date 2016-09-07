#include <iostream>
using namespace std;

// recursive
void countdown(int n){

	if(n==0){

		cout<<"blast off" <<endl;
	}
	else{

		cout<< n << endl;
		countdown(n-1);
	}
}

int factorial(int n){

	if( n==0)
		return 1; // stop calculating

	// nesse cato ele calcula n * factorial de n-1, sendo assim o proximo fara o mesmo, ate chegar na base de stop = 0
	// dai faz a volta, calculando o valor. ou seja, primeiro quebramos toda a strutura pra dai fazer o calculo
	return n * factorial(n-1);

}

int fib(int n){

	// have to stop in 2 stops, when is 0 or 1
	if( n ==0)
		return 0;
	if ( n ==1 )
		return 1;

	return fib(n-1) + fib(n-2);


}
				//n == number of "people"   // r == number of selected
int combination(int n, int r){

	if(n ==r)
		return 1;
	if(r == 0)
		return 1;

	// remove one person from the pool
	// if i pick that person
	int picked_person = combination(n-1, r-1);

	// if I didn't pick that person
	int not_picked = combination(n-1, r);

	return picked_person + not_picked;
}



int main(int argc, char const *argv[])
{
	countdown(3);
	cout<<factorial(6)<<endl;
	cout<<fib(8) <<endl;

	cout<< combination(3,2) <<endl;
	
	return 0;
}
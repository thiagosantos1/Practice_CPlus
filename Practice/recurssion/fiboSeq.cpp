// Thiago Santos

#include <iostream>

long int fNumberN(int numberN){

	long int valueOfFN =0;
	long aux1 = 0, aux2 = 1; // hold the values of the last 2 numbers - it starts with the value of f(0) and f(1)

	for ( unsigned int i = 0; i <= numberN; i++)
	{
		if(i ==0){

			 valueOfFN = 0;
			 aux1 = 0;
		}
		else if (i==1){

			valueOfFN = 1;
			aux2 = 1;
		}
		else{

			valueOfFN = aux1 + aux2;
			aux1 = aux2;
			aux2 = valueOfFN;

		}
		
	}

	return valueOfFN;


}

int main()
{	
	int numberN; 
	std::cout<<"Please, enter the number n to be calculated: ";
	std::cin>> numberN;
	std::cout<< "The value of F( "  << numberN << " ) is: " <<  fNumberN(numberN) << std::endl;
	return 0;
}






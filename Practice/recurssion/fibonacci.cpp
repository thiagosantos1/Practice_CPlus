// Thiago Santos

#include <iostream>

long int fNumberN(int numberN){

	// have to stop in 2 stops, when is 0 or 1, because there is already an answer for both
	if( numberN ==0)
		return 0;
	if ( numberN ==1 )
		return 1;

	return fNumberN(numberN-1) + fNumberN(numberN-2);


}

int main()
{	
	int numberN; 
	std::cout<<"Please, enter the number n to be calculated: ";
	std::cin>> numberN;
	std::cout<< "The value of F( "  << numberN << " ) is: " <<  fNumberN(numberN) << std::endl;
	return 0;
}
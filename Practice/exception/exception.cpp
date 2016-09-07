#include <iostream>
using namespace std;

// try, catch, and throw - keywords for exception

class NegativeDonuts{




};

int get_user_donuts();

int main(int argc, char const *argv[])
{

	int num_glasses;
	double num_donuts;
	bool do_it_again = true;

	while(do_it_again){

		try{

			num_donuts = get_user_donuts();

			cout<<"How many glasses of milk do you have: ";
			cin>> num_glasses;

			if(num_glasses <=0)
				throw num_glasses; // thrown an exception for numb glasses if it's less or equal 0
									// the try will stop and will go to catch


			double donutsPerMilk = static_cast<double>(num_donuts) / num_glasses;

			cout<< "You have " << donutsPerMilk << " Donuts for each glass of milk " << endl;

			do_it_again = false;  // if don't pass in catch it comes here and set it false


		}
		catch(int e){

			cout<<"You have got "<< e << " glasses of milk. Go and get more "<<endl;

		}
		// can catch by object type/ structuct, typdef, etc
		catch(NegativeDonuts n){

			cout<<"You have got negative Donuts! Go and get more "<<endl;

		}
	}


	return 0;
}


// try excetion inside of the function
int get_user_donuts(){

	int num_donuts;
	cout<<"How many donuts do you have: ";
	cin>> num_donuts;

	if (num_donuts <0)
		throw NegativeDonuts();

	// if num_donuts is negative, return is never execute, becuase throw is like a return
	// and it's go until find the apropiate catch, or abort the program
	return num_donuts;
}





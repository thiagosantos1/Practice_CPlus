// lendo e gravando no arquivo

#include <iostream>
#include <fstream>

using namespace std;

int main(){

	const int MAX = 100;
	
	int numNames =0;
	string names[MAX];

	ifstream infile;
	infile.open("data_name.txt");
	

	if(!infile){

		cout<<"Error opening file..." <<endl;
	}

	else{

		//cout<< "File opened right" <<endl;

	}

	getline(infile, names[numNames]);

	while(infile && numNames <MAX){  // reading from the file, just to get the information

		numNames++;
		getline(infile, names[numNames]);
	}

	cout <<"number of Names: " << numNames << endl;
	for(int i=0; i<numNames; i++)
		cout << names[i]<<endl;

	infile.close();


	return 0;
}
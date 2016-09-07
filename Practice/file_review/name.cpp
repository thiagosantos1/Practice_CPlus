// lendo do arquivo para o programa, colocando em 1 vetor

#include <iostream>
#include <fstream>

using namespace std;

int main(){

	const int MAX_NAMES = 100;
	
	if(argc <2){

		cout<<"I need a file name" <<endl;
	}


	int numNames =0;
	string names[MAX_NAMES];

	ifstream infile;
	//infile.open("data_name.txt");
	
	// ou pode passar o nome do arquivo ao executar e ler pelo argv

	infile.open(argv[1]); // pois o nome estara na posiçao 1 do vetor argv
	

	if(!infile){

		cout<<"Error opening file..." <<endl;
	}

	else{

		//cout<< "File opened right" <<endl;

	}

	getline(infile, names[numNames]);

	while(infile && numNames <MAX_NAMES){  // reading from the file, just to get the information

		numNames++;
		getline(infile, names[numNames]);
	}

	cout <<"number of Names: " << numNames << endl;
	for(int i=0; i<numNames; i++)
		cout << names[i]<<endl;

	infile.close();


	return 0;
}
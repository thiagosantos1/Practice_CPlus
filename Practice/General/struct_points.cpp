#include <iostream>
#include <fstream>
#include <cmath>

// program will calculate with position is faier in the array(file), all the combinatios between the points
// points in this case mean like (x,y), position in a grafic
// reading from the file for an array


using namespace std;

struct Point // abstract Data type - ADT - like object - (int, double... is primative data type)  
{
	int x;
	int y;

};

void print(const Point & p){ // passing by reference(&), to don't spend time passing the copy

	cout<< '(' <<p.x <<", " <<p.y <<')';
}

void printPoints(const Point points[], int num_points );
double distance(const Point &, const Point & ); // print the distance between 2 points

const int MAX_POINTS = 100;
int  main(int argc, char const *argv[])
{

	if(argc !=2){

		cout<<"Usage: Point filename" << endl;
	}

	ifstream datafile(argv[1]);

	if(! datafile)
	{
		cout <<"Problem opening " << argv[1] << endl;
	}

	int xs[MAX_POINTS];
	int ys[MAX_POINTS];
	int num_points =0; // conta a qtd d linha no arq// conta a qtd q point q vc quer ler no maximo no arq
	
	// informaçao esta saindo do arquivo e indo pro vetor
	datafile >> xs[num_points] >> ys[num_points];
	// funciona como o cin. ex: cin >> firstname >> lastname
	// embora vc nao digite enter, um double nome na mesma linha sao 2 variaveis
	// ou seja, primeiro valor do arq ira para vetor xs, e o seg vai para ys

	while(datafile && num_points < MAX_POINTS){

		num_points++;
		datafile >> xs[num_points] >> ys[num_points];

	}

	printPoints(xs, ys, num_points);

  // ou podia fazia td isso acima em uma construct

/*

	while(num_points < MAX_POINTS && datafile >> xs[num_points] >> ys[num_points];){

		num_points++;
	}

*/


	datafile.close();

	//cout<< distance(xs[4], xs[4], ys[5], ys[45);

	//calculcar o ponto mais distante no vetor

	// fisr 2 fors to calculate with points we have to compare, to don't repeat
	// like, (1 2 ), and later (2 1).

	double biggest =0;
	int p1; // p1 and p2 is where you find the biggest distance in the points
	int p2;
	for (int left = 0; left < num_points -1; left++)
	{
		for(int right = left + 1; right < num_points ; right++){

			double dist = distance(points[left], points[right]);
			// just have to save the biggest double that you find in this research
			
			if(dist > biggest){

				biggest = dist;
				p1=left;
				p2=right;
			}
		}
		
	}


	cout <<"The longest distance is: " << biggest <<endl;
	cout<<"Between point " << p1 <<" and " <<p2 <<endl;

}

double distance(const Point & a, const Point & b){
	// tem q usar a formula para saber quais ponstos graficos é o mais longe

	int dx = b.x - a.x;
	int dy = b.y - a.y;

	return sqrt(dx *dx + dy*dy);

}

void printPoints(const Point points[], int num_points){


	for (int i = 0; i <num_points; ++i)
	{	
		print(points[i]);
	}



}
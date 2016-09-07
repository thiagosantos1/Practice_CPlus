// Thiago Santos
// 31/08/15
// Lab 02

#include <iostream>
#include <cstdlib>

using namespace std;

void draw_triangles(const int, const int);

int  main(int argc, char const *argv[])
{
	int numb_triang =0, height_triang =0;

	if(argc != 3){
		cout<<"Must enter number of triangles and height" <<endl;
		return 1;  // must enter numb of triangles and the height
	}

	numb_triang = atoi(argv[1]);
	height_triang = atoi(argv[2]);

	if (numb_triang <1 || height_triang <1)
	{
		cout<<"Number of triangles and height, must be at least 1." << endl;
		return -1;
	}

	draw_triangles(numb_triang, height_triang);

}

void draw_triangles(const int NUMB_TRIANG, const int HEIGHT)
{

	for (int i = HEIGHT; i >0; i--) // to control how many spaces between the *
	{
		
		for (int a = 0; a < NUMB_TRIANG; a++) // to control how many triangles to print
		{
			for(int j=HEIGHT - (i-1); j>0; j--){ // to control how many * have to print per time

				cout<<'*';
			}

			for (int t = 0; t < i; t++)  // to print the spaces
			{
				cout<<' ';
			}
		}
		
		cout<<endl; // finishing 1 line of the triangle(s)

	}

}
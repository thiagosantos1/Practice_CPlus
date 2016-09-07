// Thiago Santos
// 09/09/15
// Lab 04
# include <iostream>

using namespace std;


struct MovieData{
	string title;
	string director;
	int year_released;
	int runing_time;
	
};

void print( const MovieData &);

int main(int argc, char const *argv[]){

	MovieData movie_data1={"Panic", "Jorge", 2002, 123};
	MovieData movie_data2={"Pirate of Caribe", "Matieu", 2008, 132};


	print(movie_data1);
	print(movie_data2);
	
	return 0;
}

void print( const MovieData & movie_data){

	cout<<"\n\tMovie Title: " << movie_data.title <<endl;
	cout<<"\tDirector: "<<  movie_data.director<<endl;
	cout<<"\tYear Released: " << movie_data.year_released <<endl;
	cout<<"\tRuning time: " <<movie_data.runing_time <<endl <<endl;

}
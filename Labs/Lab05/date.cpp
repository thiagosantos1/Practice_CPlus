// Thiago Santos
// Lab05
// 2015/09/19

# include <iostream>
# include <string>
# include <iomanip>

using namespace std;


class Date{

public:

	Date(int yearIn, int monthIn, int dayIn){

		year = yearIn;
		month = monthIn;
		day = dayIn;
	}

	Date(){

		year = 1970;
		month = 1;
		day = 1;

	}
					// cannot change the variable using this method
	int getMonth() const {
		return month;
	}
	void setMonth(int newMonth){
		month =  newMonth;
	}

	int getDay() const{
		return day;
	}
	void setDay(int new_Day){
		 day = new_Day;
	}

	int getYear() const{
		return year;
	}
	void setYear(int new_Year){
		 year = new_Year;
	}

	void printSlashes( ) const {

		cout << month <<"/" << day <<"/" << year <<endl;
	}

	void printLong() const {

		string month_names[] = {"January", "February", "March", "April", "May",
							  	"June", "July", "August", "September", "Octuber",
							  	"November", "December"};

		cout << month_names[month-1] <<" " << day <<", '"<< year <<endl;
	}

	void printISO() const {

		cout << year <<"-" << setfill('0') <<setw(2) << month << "-" <<setw(2) <<day <<endl; 
	}

private:
	int month;
	int day;
	int year;

};

int main(int argc, char const *argv[]){


	Date a(2014, 12, 5);
	Date b;  // we don't put () to say it's a default constructor, have to use witout ()

	a.printSlashes();
	a.printLong();
	a.printISO();

	b.printSlashes();
	b.printLong();
	b.printISO();

	return 0;
}



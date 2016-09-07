// Thiago Santos
// 09/02/2015
// Lab 03

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int how_many_days_month(const int, const int);
void draw_calendar(const int, const int, const int);

int  main(int argc, char const *argv[])
{

	int  month, year, first_day_month;

 	if(argc != 4){
 		cout<<"Must enter the month, year, and the day-of-week for the first day of the month\n";
 		return -1;
 	}

	month= atoi(argv[1]);
	year = atoi(argv[2]);
	first_day_month = atoi(argv[3]);

	if( (month <1 || month >12) || (first_day_month<0 || first_day_month>6) 
		|| (year <1) ){

		cout<< "Month has to be between 1 and 12, Day of the week has to be between 0 "; 
		cout <<"and 6 \nand year has to be a positive value" <<endl;
		return -1; //stop programm

	}

	draw_calendar(month, first_day_month, year);
	
	return 0;
}



void draw_calendar(const int MONTH, const int FIRST_DAY_MONTH, const int YEAR){

	const string MONTH_NAME[] = {"January", "Februaray", "March", "April","May", "June", 
							"July", "August", "September", "Octuber", "November", "December" };

	int count_end_week = FIRST_DAY_MONTH; // just to check if it is the end of the week
										  // if it's, we break the line 
	int days_month = how_many_days_month(MONTH, YEAR);

	// ***** Drawing the Calendar ****** //

	cout<<"\n\n" <<MONTH_NAME[MONTH -1];
	cout<< "\t" << YEAR <<"\n";
	cout<<"--------------------------------\n";
	cout<<"Su   MO   TU   We   Th   Fr   Sa\n";


	for(int i=0; i<=FIRST_DAY_MONTH; i++)  // just print the first line, until find the day the week starts
	{

		if(i !=FIRST_DAY_MONTH){
			cout<<"     "; 
		}
		else{
			cout<< " " <<1 <<"    ";
			if(FIRST_DAY_MONTH == 6){
				count_end_week = 0; // restart the line, for the next for
				cout<<"\n";
			}
			else{
				count_end_week +=1;  // stay in the the same line in the next for
			}
		}





	}

	//cout<< count_end_week;

	for(int i=2; i<=days_month; i++) // rest of the calendar
	{
		
		if(i<10)
			cout<<i <<"    ";
		else
			cout<<i <<"   ";

		if(count_end_week == 6){
				count_end_week = 0; 
				cout<<"\n";
			}
			else{
				count_end_week +=1; 
			}
	}


	cout<<"\n\n\n";

}

int how_many_days_month(const int MONTH, const int YEAR)
{
	int rest_year;

	if(YEAR > 999) // to get the lest 2 digits of the year, to check if it's a leap year
		rest_year= YEAR % 100;
	else if(YEAR > 99)
		rest_year= YEAR % 100;
	else
		rest_year= YEAR;


	if( (MONTH == 1) || (MONTH==3) || (MONTH==5) || (MONTH==7) || (MONTH==8)
		|| (MONTH==10) || (MONTH==12) )
	{
		return 31;
	}
	else if( (MONTH==4) || (MONTH==6) || (MONTH==9) || (MONTH==11) )
	{
		return 30;
	}
	else
	{
		if(rest_year ==0)
		{
			if(YEAR %400 == 0)
			{
				return 29;

			}
			else{
				return 28;
			}

		}
		else{

			if(YEAR %4 == 0)
			{
				return 29;

			}
			else{
				return 28;
			}

		}

	}

	return -1; // error
}






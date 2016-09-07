// Thiago Santos
// 09/09/15
// Lab 04
# include <iostream>

using namespace std;

const int MONTHS_YEAR =12;
const string MONTH_NAMES[MONTHS_YEAR]= {"Jan","Feb","March","Apr","May","Jun","Jul"
							 ,"Aug","Sep","Oct","Nov","Dec"};

struct WeatherData
{
	int toal_rain_fall;
	int hight_temperature;
	int low_temperature;
	float average_temperature;
	
};

double average_monthly_rainfall(const WeatherData & , int);
double total_rainfall_year(const WeatherData[] );
void print_highest_lowest_temperature(const WeatherData[] );

void print( const WeatherData &);

int main(int argc, char const *argv[])
{

	WeatherData weather_data[MONTHS_YEAR];
	WeatherData weather;

	cout<<"\n\tPlease enter the information bellow about the weather condition\n"<<endl;
	for (int index = 0; index < MONTHS_YEAR; index++)
	{
		cout<<"For " <<MONTH_NAMES[index]<<", enter:" <<endl;
		cout<<"\tTotal Rainfall: ";
		cin>> weather.toal_rain_fall;
		cout<<"\tHigh Temperature: ";
		cin>> weather.hight_temperature;
		cout<<"\tLow Temperature: ";
		cin>> weather.low_temperature;
		cout<<"\tAverage Temperature: ";
		cin>> weather.average_temperature;

 
 		weather_data[index] = weather;

	}

	

	for (int index = 0; index < MONTHS_YEAR; index++)
	{
		weather = weather_data[index];

		cout<<"The average of rainfall for " << MONTH_NAMES[index] <<" was ";
		cout<< average_monthly_rainfall(weather, index) <<endl;;

	}

	cout<<"The total of rainfall for the year was " << total_rainfall_year(weather_data) <<endl;

	print_highest_lowest_temperature(weather_data);
	
	
	return 0;
}

void print_highest_lowest_temperature(const WeatherData weather[])
{

	WeatherData weather_monthly;
	double hight_temperature= -1000, low_temperature=1000;
	int month_hight_temperatures_occured[MONTHS_YEAR]={0};
	int month_low_temperatures_occured[MONTHS_YEAR]={0};
	

	for (int index = 0; index < MONTHS_YEAR; index++)
	{
		
		weather_monthly = weather[index];
		if(weather_monthly.hight_temperature >= hight_temperature)
		{
			hight_temperature = weather_monthly.hight_temperature;

		}
		if(weather_monthly.low_temperature <= low_temperature)
		{
			low_temperature = weather_monthly.low_temperature;

		}

	}

	for (int index = 0; index < MONTHS_YEAR; index++)
	{
		
		weather_monthly = weather[index];
		if(weather_monthly.hight_temperature == hight_temperature)
		{
			month_hight_temperatures_occured[index]++; // where we find 1 it's because the highest
														// temperature occored at that month

		}
		if(weather_monthly.low_temperature == low_temperature)
		{
			month_low_temperatures_occured[index]++;

		}

	}

	cout<<"The highest temperature of the year was: " << hight_temperature <<endl;
	cout<<"And it most occored in ";
	for (int index = 0; index < MONTHS_YEAR; index++)
	{
		if(month_hight_temperatures_occured[index] == 1){
			cout<<MONTH_NAMES[index] <<", ";
		}

	}

	cout<<"\nThe Lowest temperature of the year was: " << low_temperature <<endl;
	cout<<"And it most occored in ";

	for (int index = 0; index < MONTHS_YEAR; index++)
	{
		if(month_low_temperatures_occured[index] == 1){
			cout<<MONTH_NAMES[index] <<" ";
		}

	}

	cout<<endl;
}

double total_rainfall_year(const WeatherData weather[] )
{

	WeatherData weather_monthly;
	double total_rainfall_year =0;

	for (int index = 0; index < MONTHS_YEAR; index++)
	{
		
		weather_monthly = weather[index];

		total_rainfall_year += (double)weather_monthly.toal_rain_fall;
	}

	return total_rainfall_year;


}

double average_monthly_rainfall(const WeatherData & weather, int month)
{

	int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	return (double)weather.toal_rain_fall / (double)month_days[month];



}

void print( const WeatherData & weather_ata)
{
	cout<<"Total of rain fall " << weather_ata.toal_rain_fall <<endl;
	cout<<"Hight temperature " << weather_ata.hight_temperature <<endl;
	cout<<"Low temperature " << weather_ata.low_temperature <<endl;
	cout<<"Average temperature " << weather_ata.average_temperature <<endl;

}



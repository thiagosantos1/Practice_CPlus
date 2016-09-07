// Thiago Santos
// Lab 08
// 09/30/ 2015

#include <iostream>
#include "number.h"

using namespace std;

Number::Number(){


}

Number::Number(int number_in){

	setNumber(number_in);
	
}
void Number::setNumber(int number_in){

		if (number_in > 0 && number_in <= 9999){

			number = number_in;
		} 
}

int Number::getNumber() const {

		return number;
}


string Number::inEnglish() const{

	int rest = number, quotiente = 0;
	string number_in_english = "";

	if( number >=0){


		if(rest >= 1000){

			quotiente = number / 1000;
			rest = number % 1000;
			number_in_english += less_than_20_eng[quotiente] + " " + 
								 thousand_eng + " ";
		}
		if( rest >=100){

			quotiente = rest / 100;
			rest %= 100;

			number_in_english += less_than_20_eng[quotiente] + " " + 
								 hundred_eng + " ";

		}
		if( rest >=20){

			quotiente = rest / 10;
			rest %= 10;

			number_in_english += grat_19_less_than_100_eng[quotiente - 2] + " ";

		}
		if( rest >0){

			number_in_english += less_than_20_eng[rest] + " ";

		}

				
	}

	return number_in_english;


}

string Number::inPortuguese() const{

	int rest = number, quotiente = 0;
	string number_in_portuguese = "";

	if( number >=0){


		if(rest >= 1000){

			quotiente = number / 1000;
			rest = number % 1000;
			number_in_portuguese += less_than_20_ptr[quotiente] + " " + 
								 thousand_ptr + " ";
		}
		if( rest >=100){

			quotiente = rest / 100;
			rest %= 100;

			number_in_portuguese += hundred_ptr[quotiente - 1] + " ";

		}
		if( rest >=20){

			quotiente = rest / 10;
			rest %= 10;

			number_in_portuguese += grat_19_less_than_100_ptr[quotiente - 2] + " ";

		}
		if( rest >0){

			number_in_portuguese += less_than_20_ptr[rest] + " ";

		}

				
	}

	return number_in_portuguese;


}


Number::~Number(){

	

}



string Number::less_than_20_eng[] = {"zero", "one", "two", "three", "four", "five", 
									"six","seven","eight", "nine", "ten", "eleven", 
 									"twelve", "thirteen", "fourteen","fifteen", 
 									"sixteen", "seventeen", "eighteen", "nineteen"};

string Number::grat_19_less_than_100_eng[] = {"twenty", "thirty", "forty",
											 "fifty", "sixty", "seventy",
											 "eighty", "ninety" };
string Number::hundred_eng = "hundred";
string Number::thousand_eng = "thousand";



string Number::less_than_20_ptr[] = {"zero", "um", "dois", "três", "quatro", 
									  "cinco", "seis","sete","oito", "nove", 
									  "dez", "onze", "doze", "treze","quatorze",
									  "quinze", "dezesseis", "dezessete",
									   "dezoito", "dezenove"};
	
string Number::grat_19_less_than_100_ptr[] = {"vinte", "trinta", "quarenta",
											 "cinquenta", "sessenta", "setenta",
											 "oitenta", "noventa" };



string Number::hundred_ptr[] = {"cem", "duzentos", "trezentos","quatrocentos", 
							  "quinhentos", "seiscentos","setecentos", 
							  "oitocentos", "novecentos" };

string Number::thousand_ptr = "mil";



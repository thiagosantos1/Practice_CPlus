// Thiago Santos
// Lab 08
// 09/30/ 2015
 
#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>

class Number
{
public:
	Number();
	Number(int number_in);

	void setNumber(int number_in);

	int getNumber() const;

	std::string  inEnglish() const;

	std::string inPortuguese() const;

	// I created the method because if put an especific code for 
	// inEnglish and another one for inRussian, we can see that 
	// is almost the same code, so just a way to save code
	//static std::string translateNumber(std::string language);


	~Number();

private:

	int number;
	static std::string less_than_20_eng[];
	static std::string grat_19_less_than_100_eng[];
	static std::string hundred_eng;
	static std::string thousand_eng;

	static std::string less_than_20_ptr[];
	static std::string grat_19_less_than_100_ptr[];
	static std::string hundred_ptr[];
	static std::string thousand_ptr;
	
};



#endif
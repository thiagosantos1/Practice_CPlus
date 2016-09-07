#ifndef SQUARE_H
#define SQUARE_H

class Square : public Shape 
{
public:
	Square(int);

	virtual void setX(int);

	virtual void setY(int);

	virtual void setGray (float);

	virtual void drawOn (sf::RenderWindow &);



private:
	int width;
	int x, y; 
	float colorGrey;


};

#endif
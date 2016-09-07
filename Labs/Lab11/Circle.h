#ifndef CIRCLE_H
#define CIRCLE_H 

class Circle : public Shape 
{
public:
	Circle(int);

	virtual void setX(int);

	virtual void setY(int);

	virtual void setGray (float);

	virtual void drawOn (sf::RenderWindow &);



private:
	int radius;
	int x, y; 
	float colorGrey;


};

#endif
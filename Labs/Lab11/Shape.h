#ifndef SHAPE_H 
#define SHAPE_H
#include <SFML/Graphics.hpp> 

class Shape
{
public:
	virtual void setX(int) = 0;

	virtual void setY(int) = 0;

	virtual void setGray (float) = 0;

	virtual void drawOn (sf::RenderWindow &) = 0;
};

#endif
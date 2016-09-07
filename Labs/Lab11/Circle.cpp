#include "Shape.h"
#include "Circle.h"
#include <SFML/Graphics.hpp> 
#include <iostream> 

Circle::Circle(int diameter)
{
	radius = diameter/2;
}

void Circle::setX(int x_in)
{
	x = x_in - radius;
}

void Circle::setY(int y_in)
{
	y = y_in - radius;
}

void Circle::setGray (float value_in)
{
	colorGrey = value_in;
}

void Circle::drawOn (sf::RenderWindow & window)
{
	float gray;

	gray = 255 * colorGrey;

	sf::CircleShape c_shape;
	c_shape.setRadius(radius);
    c_shape.setPosition(x, y);
    c_shape.setFillColor(sf::Color (gray,gray,gray) ) ;

    window.draw(c_shape);
}

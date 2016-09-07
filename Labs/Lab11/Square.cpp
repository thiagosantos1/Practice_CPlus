#include "Shape.h"
#include "Square.h"
#include <SFML/Graphics.hpp> 
#include <iostream>

Square::Square(int width_in)
{
	width = width_in;
}

void Square::setX(int x_in)
{
	x = x_in - width/2;
}

void Square::setY(int y_in)
{
	y = y_in - width/2;
}

void Square::setGray (float value_in)
{
	colorGrey = value_in;
}

void Square::drawOn (sf::RenderWindow & window)
{
	float gray;

	gray = 255 * colorGrey;

	sf::RectangleShape r_shape;
	r_shape.setSize(sf::Vector2f(width, width));
    r_shape.setPosition(x, y);
    r_shape.setFillColor(sf::Color (gray,gray,gray) ) ;

    window.draw(r_shape);
}

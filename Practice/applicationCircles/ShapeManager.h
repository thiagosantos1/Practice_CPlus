// changed the shape to have a vector from include, so then we can control, add, remove, much more
#ifndef SHAPEMANAGER_H 
#define SHAPEMANAGER_H 

#include "Shape.h"
#include <SFML/Graphics.hpp>

class ShapeManager
{
public:
	ShapeManager(int count);
	~ShapeManager();
	void randomize(const sf::Vector2u & size);
	void moveAll(float time, const sf::Vector2u & window_size);
	void drawAll(sf::RenderWindow & window);


private:

	// Dynamically allocated array of shapes
	// an array of pointers of shape
	// * shapes = array
	//Shape* pointers of shape
	Shape* * shapes;
	 // Shapes, has to be a pointer, because without that, we would have a array of pointer of shapes
    // so then, when we create shapes = new Shape[30], it would create 30 shapes, initialize with null. With Shapes of pointer
    // we create shapes = Shapes*[30], so the we had  pointer of 30 position for an array of shape, so each pointer can point for a shape
    // and then, if we delete some position, we delete just the pointer for that array of shape, in the other type, we would delete
    // all array

	int num_shapes;
};

#endif


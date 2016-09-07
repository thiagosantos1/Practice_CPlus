#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include "Shape.h"

#include <vector>
#include "SFML/Graphics.hpp"


class ShapeManager
{
public:
    ShapeManager(int count);
    ~ShapeManager();

    void randomize(const sf::Vector2u & size);
    void moveAll(float time, const sf::Vector2u & window_size);
    void drawAll(sf::RenderWindow & window);

private:
    std::vector<Shape *> shapes;
};

#endif
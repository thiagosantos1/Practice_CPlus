#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "Shape.h"
#include "ShapeManager.h"

using std::cout;
using std::endl;

int main()
{
    std::srand(std::time(0));

    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

    ShapeManager shapes(1);
    shapes.randomize(window.getSize());

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsedTime = clock.restart();
        shapes.moveAll(elapsedTime.asSeconds(), window.getSize());
        window.clear();
        shapes.drawAll(window);
        window.display();
    }

    return 0;
}
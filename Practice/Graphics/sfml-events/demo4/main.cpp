// We can respond to other kinds of events, like keys being pressed.

#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(100, 20);
    
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // event that get the action of any button you click
            else if (event.type == sf::Event::KeyPressed)
            {
                sf::Color new_color;
                new_color.r = rand() % 256;
                new_color.g = rand() % 256;
                new_color.b = rand() % 256;
                rectangle.setFillColor(new_color);
            }
        }

        window.clear();
        window.draw(rectangle);
        window.display();    
    }

    return 0;
}

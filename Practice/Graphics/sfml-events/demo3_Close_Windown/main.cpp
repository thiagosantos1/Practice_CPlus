// This is the version that will finally work on all computers. It has basic
// "event handling" so that you can close the window.
//
// This is the template for all future SFML code you write.

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
        // to control anything in the screen, we have events, like in java
        // if user move the mouse, button, or anything, you get by event
        sf::Event event;

        // this while get any event you do in the screen
        while(window.pollEvent(event))
        {
            // is this case we wanna the event of click to close the windown
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rectangle);
        window.display();    
    }

    return 0;
}

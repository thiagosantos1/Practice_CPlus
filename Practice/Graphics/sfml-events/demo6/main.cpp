// If you want to see something happen while a key is pressed, you don't want
// to use events, you want to use real-time input.

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(100, 20);
    
    sf::RectangleShape indicator;
    indicator.setSize(sf::Vector2f(100, 50));
    indicator.setFillColor(sf::Color::Black);
    indicator.setPosition(300, 20);

    while (window.isOpen())
    {
        sf::Event event;
        // 2 ways to get events in sfml

        // 1) a while to check if there's some event happening
        // is's call late event
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                sf::Color new_color;
                new_color.r = rand() % 256;
                new_color.g = rand() % 256;
                new_color.b = rand() % 256;
                rectangle.setFillColor(new_color);
            }
        }


        // 2) real time event/input, is the keypressed right now?
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            indicator.setFillColor(sf::Color::White);
            cout<<"sdsd"<<endl;
        }
        else
            ;//indicator.setFillColor(sf::Color::Black);

        window.clear();
        window.draw(rectangle);
        window.draw(indicator);
        window.display();    
    }

    return 0;
}

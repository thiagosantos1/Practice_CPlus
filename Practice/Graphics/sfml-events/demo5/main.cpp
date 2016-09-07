// Events happen in a single frame, so if you do something visually during an
// event, you probably won't be able to see it.

#include <iostream>
#include <SFML/Graphics.hpp>


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
        // 
        indicator.setFillColor(sf::Color::Black);

        sf::Event event;
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


                // continua preto, pq o loop é mt rapido, e entao a cor breta volta para 
                // o retangalo
                indicator.setFillColor(sf::Color::White);
            }
        }

        window.clear();
        window.draw(rectangle);
        window.draw(indicator);
        window.display();    
    }

    return 0;
}

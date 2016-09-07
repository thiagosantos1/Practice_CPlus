// We can start to think about moving things around on screen.

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
            else if (event.type == sf::Event::KeyPressed)
            {
                // event to move right and left the rectangle
                if (event.key.code == sf::Keyboard::Left)
                    rectangle.move(-10, 0);
                
                if (event.key.code == sf::Keyboard::Right)
                    rectangle.move(10, 0);
            }
        }

        window.clear();
        for (int i = 0; i < 2; ++i)
        {
            sf::CircleShape::CircleShape circle(20);
            circle.setPosition(i*25,i*20);
            circle.move(10,10);
            window.draw(circle);
        }
        
        
        window.display();    
    }

    return 0;
}

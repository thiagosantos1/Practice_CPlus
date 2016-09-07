// This is the kind of drawing we did on the first day. It's pretty cruddy;
// the window gets messed up, and it won't work at all on some systems.

#include <iostream>
#include <SFML/Graphics.hpp>


void wait();


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");
    window.clear();

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(100, 20);

    window.draw(rectangle);
    window.display();

    wait();

    return 0;
}


void wait()
{
    std::cout << "Press enter to continue";
    std::cin.get();
}

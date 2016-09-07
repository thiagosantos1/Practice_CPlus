#include <iostream>
#include <SFML/Graphics.hpp>


// These are constants for the size of the window, and 
const int WIDTH = 640;
const int HEIGHT = 480;
const sf::VideoMode WINDOW_SIZE(WIDTH, HEIGHT);


void wait();


int main()
{
    sf::RenderWindow window(WINDOW_SIZE, "The Window Title");

    wait();

    window.clear();

    wait();

    window.display();

    wait();

    sf::Vector2f dims(100.0, 50);
    sf::RectangleShape r1(dims);
    window.draw(r1);
    window.display();

    wait();

    return 0;
}


void wait()
{
    std::cout << "Press enter to continue";
    std::cin.get();
}
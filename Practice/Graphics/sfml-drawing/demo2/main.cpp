#include <iostream>
#include <SFML/Graphics.hpp>


// These are constants for the size of the window, and 
const int WIDTH = 640;
const int HEIGHT = 480;
const sf::VideoMode WINDOW_SIZE(WIDTH, HEIGHT);


void wait();


int main()
{
    sf::RenderWindow window(WINDOW_SIZE, "Demo 2");
    window.clear();

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setFillColor(sf::Color(0, 255, 0));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(100, 20);

	window.draw(rectangle);
    window.display();

    wait();

    sf::CircleShape circle(100);
    										// 128 = trasparecencia = 0 to 255; 0 = transparente
    circle.setFillColor(sf::Color(0, 0, 255, 128));
    circle.setPosition(100, 20);

    window.draw(circle);
    window.display();

    wait();

	sf::VertexArray triangle(sf::Triangles, 3);

	triangle[0].position = sf::Vector2f(10, 200);
	triangle[1].position = sf::Vector2f(10, 400);
	triangle[2].position = sf::Vector2f(300, 400);

	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;

	window.draw(triangle);
	window.display();

	wait();


    return 0;
}


void wait()
{
    std::cout << "Press enter to continue";
    std::cin.get();
}

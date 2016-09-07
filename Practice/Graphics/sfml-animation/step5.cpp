// In step 5, we make a first attempt at bouncing off the right edge of
// the screen.

#include <cstdlib>
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

    sf::Texture ballTexture;
    ballTexture.loadFromFile("basketball.png");

    sf::Sprite ball;
    ball.setTexture(ballTexture);
    ball.setPosition(500, 200);

    float speed = -1.0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //  bound the ball in x cordenate
        if (ball.getPosition().x <= 1 || ball.getPosition().x >= 640)
            speed = -speed;

        ball.move(speed, 0);

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}


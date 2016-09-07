// In step 4, we make the ball "bounce" off the left side of the screen.

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

        // Here we check to see if the ball has gone off the left
        // side.  If so, we change its direction.
        if (ball.getPosition().x <= 0)
            speed = -speed;

        ball.move(speed, 0);

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}

// This fixed the left edge, but we still need to fix the right edge...

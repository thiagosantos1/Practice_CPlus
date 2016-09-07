// In step 8, we fix a subtle bug in the in ball movement.

#include <cstdlib>
#include <cmath>
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

    sf::Texture ballTexture;
    ballTexture.loadFromFile("basketball.png");

    sf::Sprite ball;
    ball.setTexture(ballTexture);
    ball.setPosition(500, 200);

    // Now the speed is measured in pixels/second
    float speed = -200;

    // And we have to measure how many seconds it has been.
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        int leftSide = ball.getPosition().x;
        int rightSide = leftSide + ball.getGlobalBounds().width;

        // When the ball always moved the same number of pixels per frame,
        // "flipping" its direction was good enough. Now, the ball could be
        // off-screen for several frames in a row, so we need to make sure
        // it keeps heading in the right direction.

        // make sure to don't stop in the border, so it'll always bound
        if (leftSide <= 1)
            speed = std::abs(speed);
        if (rightSide >= 640)
            speed = -std::abs(speed);

        sf::Time elapsedTime = clock.restart();
        ball.move(speed * elapsedTime.asSeconds(), 0);

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}


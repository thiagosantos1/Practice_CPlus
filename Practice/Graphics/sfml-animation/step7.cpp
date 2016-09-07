// In step 7, we make the ball movement much more consistant by measuring
// movement in pixels per second, rather than a fixed number of pixels moved
// in each frame.

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

    // Now the speed is measured in pixels/second
    // better way to make to move, to be the same in all computers
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

        if (leftSide <= 0 || rightSide >= 640)
            speed = -speed;

        // Move the ball the correct distance based on how long it's
        // been since the last update
        sf::Time elapsedTime = clock.restart();
        ball.move(speed * elapsedTime.asSeconds(), 0);

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}


// In step 9, we add some user control.

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

    float horizSpeed = -200;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsedTime = clock.restart();

        // make differences to then you can use keyboard
        int leftSide = ball.getPosition().x;
        int rightSide = leftSide + ball.getGlobalBounds().width;
        if (leftSide <= 1)
            horizSpeed = std::abs(horizSpeed); // this function converte the value t
                                                // to the oposite, - to + and + to -
        else if (rightSide >= 640)
            horizSpeed = -std::abs(horizSpeed);

        // If the up arrow is currently pressed, move the ball up
        // If the down arrow is currently pressed, move the ball down
        float vertSpeed = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            vertSpeed += -100;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            vertSpeed += 100;

        ball.move(horizSpeed * elapsedTime.asSeconds(),
                  vertSpeed * elapsedTime.asSeconds());

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}


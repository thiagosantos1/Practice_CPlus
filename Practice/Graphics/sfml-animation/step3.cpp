// In step 3, we make the ball move left across the screen.

#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

    sf::Texture ballTexture;
    ballTexture.loadFromFile("basketball.png");

    sf::Sprite ball;
    ball.setTexture(ballTexture);
    ball.setPosition(400, 200);

    // We will move the ball left one pixel every frame.
    float speed = -1.0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // The setPosition function moves the Sprite to wherever you
        // specificed. The move function moves the Sprite *relative* to its
        // current location. Here, it moves the ball 'speed' pixels
        // horizontally, and 0 pixels vertically.
        
        // move a speed x, but in the same postion, don't change, move just on x positon
        ball.move(speed, 0);

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}

// Now it moves left past the edge of the screen! We'll fix that in step 4.
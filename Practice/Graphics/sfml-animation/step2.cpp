// In step 2, we load an image and display it on screen.

#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

    // SFML has a class named Image, so you might wonder why we don't use
    // that. The Image class is more for creating custom images. The Texture
    // class is for pictures we want to draw on screen.

    // if we want to create more ball with the same picture
    // just create an array and all set texture and pass ballTexture as parameter
    sf::Texture ballTexture;
    ballTexture.loadFromFile("basketball.png");


    // So far, we've mostly use the Shape class to draw things on screen. For
    // images, the Sprite class does basically the same stuff. Most 2D video
    // games are nothing but thousands of Sprites being moved on screen.
    // Basically same from Python, put any picture inside of a rectangle
    // so then you get get x and y position, for then move, etc
    sf::Sprite ball;

    // Instead of setting fill colors or border sizes, you just tell a Sprite
    // to use a Texture. Multiple Sprites can reuse the same Texture; in fact,
    // it's a really good idea, because it save memory.

    ball.setTexture(ballTexture);

    // As usual, the position is the top-left corner of the Sprite.

    ball.setPosition(500, 200);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // We are drawing the ball in the same place each frame.

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}


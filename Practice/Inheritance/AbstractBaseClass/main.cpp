#include <cstdlib>
#include <cmath>
#include <SFML/Graphics.hpp>

class Thing
{
public:
    virtual void doSomething() = 0;
    virtual void drawOn(sf::RenderWindow &) = 0;
};


class ColorThing : public Thing
{
public:
    ColorThing(int x, int y)
    {
        r_shape.setSize(sf::Vector2f(100, 50));
        r_shape.setFillColor(sf::Color::Green);
        r_shape.setPosition(x, y);
    }

    virtual void doSomething()
    {
        sf::Color new_color;
        new_color.r = rand() % 256;
        new_color.g = rand() % 256;
        new_color.b = rand() % 256;
        r_shape.setFillColor(new_color);
    }

    virtual void drawOn(sf::RenderWindow & window)
    {
        window.draw(r_shape);
    }

protected:
    sf::RectangleShape r_shape;
};

class ShapeThing : public Thing
{
public:
    ShapeThing(int x, int y)
    {
        r_shape.setSize(sf::Vector2f(100, 50));
        r_shape.setFillColor(sf::Color::Green);
        r_shape.setPosition(x, y);

        c_shape.setRadius(50);
        c_shape.setFillColor(sf::Color::Green);
        c_shape.setPosition(x, y);

        is_rect = true;
    }

    virtual void doSomething()
    {
        is_rect = !is_rect;
    }

    virtual void drawOn(sf::RenderWindow & window)
    {
        if (is_rect)
            window.draw(r_shape);
        else
            window.draw(c_shape);
    }

private:
    sf::RectangleShape r_shape;
    sf::CircleShape c_shape;
    bool is_rect;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

    const int num_things = 2;
    Thing* things[num_things];

    things[0] = new ColorThing(100, 100);
    things[1] = new ShapeThing(400, 100);

    Thing t;

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                for (int i = 0; i < num_things; i++)
                    things[i]->doSomething();
            }
        }

        window.clear();

        for (int i = 0; i < num_things; i++)
            things[i]->drawOn(window);

        window.display();
    }

    delete things[0];
    delete things[1];

    return 0;
}

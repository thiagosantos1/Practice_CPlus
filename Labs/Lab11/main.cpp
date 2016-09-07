// CISS 245 Lab 11
// All students

#include <iostream> 
#include <SFML/Graphics.hpp>

#include "shape.h"
#include "circle.h"
#include "square.h"

using std::cout;
using std::endl;
using std::cin;

const int NUM_SHAPES = 4;
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;
const int SHAPE_WIDTH = WIN_WIDTH / (2 * NUM_SHAPES + 1);


int main()
{
    // Shape is an abstract base class for both Circle and Square
    Shape* shapes[NUM_SHAPES];

    for (int i = 0; i < NUM_SHAPES; i++)
    {
        char user_choice;
        cout << "Shape " << i + 1 << " is a (c)ircle or (s)quare: ";
        cin >> user_choice;
        
        if (user_choice == 'c')
        {
            // The Circle constructor takes the diameter of the circle
            shapes[i] = new Circle(SHAPE_WIDTH);
        }
        else if (user_choice == 's')
        {
            // The Square constructor takes the width of the square
            shapes[i] = new Square(SHAPE_WIDTH);
        }
        else
        {
            cout << "Invalid input" << endl;
            i--;
            continue;
        }

        int center_x = (WIN_WIDTH / (NUM_SHAPES + 1)) * (i + 1);
        int center_y = (WIN_HEIGHT / 2);

        // The setX function sets the x coordinate of the center of the shape
        shapes[i]->setX(center_x);

        // The setY function sets the y coordinate of the center of the shape
        shapes[i]->setY(center_y);

        // The setGray function sets the color of the shape to some shade of
        // gray, where 0.0 is black and 1.0 is white
        shapes[i]->setGray( (i + 1) / float(NUM_SHAPES) );
    }


    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "SFML");
    while (window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        
        for (int i = 0; i < NUM_SHAPES; i++)
            shapes[i]->drawOn(window);

        window.display();
    }

    return 0;
}

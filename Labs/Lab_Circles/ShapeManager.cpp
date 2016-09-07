#include "ShapeManager.h"

#include <vector>


ShapeManager::ShapeManager(int count)
{
    for (int i = 0; i < count; i++)
    {
        Shape * temp = new Shape();
        shapes.push_back(temp);
    }
}


void ShapeManager::randomize(const sf::Vector2u & window_size)
{
    for (int i = 0; i < shapes.size(); i++)
    {
        // Generate random parameters
        int shape_width = rand() % 40 + 10;
        float x = rand() % (window_size.x - shape_width);
        float y = rand() % (window_size.y - shape_width);
        float vx = rand() % 400 - 200;
        float vy = rand() % 400 - 200;

        // Set randomly generated parameters.
        shapes[i]->setRadius(shape_width / 2);
        shapes[i]->setPosition(x, y);
        shapes[i]->setVelocity(vx, vy);
    }
}


void ShapeManager::moveAll(float time, const sf::Vector2u & window_size)
{    
    for (int i = 0; i < shapes.size(); i++)
        shapes[i]->move(time, window_size);

    for (int i = 0; i < shapes.size(); i++)
    {
        Shape * sp = shapes[i]->getNewShape();
        if (sp != nullptr)
        {
            // Generate random parameters
            int shape_width = rand() % 40 + 10;
            float x = rand() % (window_size.x - shape_width);
            float y = rand() % (window_size.y - shape_width);
            float vx = rand() % 400 - 200;
            float vy = rand() % 400 - 200;

            // Set randomly generated parameters.
            sp->setRadius(shape_width / 2);
            sp->setPosition(x, y);
            sp->setVelocity(vx, vy);

            shapes.push_back(sp);
        }
    }

    for (int i = 0; i < shapes.size(); i++)
    {
        if (shapes[i]->shouldBeDeleted())
        {
            delete shapes[i];
            shapes.erase(shapes.begin() + i);
            i--;
        }        
    }
}


void ShapeManager::drawAll(sf::RenderWindow & window)
{
    for (int i = 0; i < shapes.size(); i++)
        shapes[i]->draw(window);
}


ShapeManager::~ShapeManager()
{
    for (int i = 0; i < shapes.size(); i++)
        delete shapes[i];
}




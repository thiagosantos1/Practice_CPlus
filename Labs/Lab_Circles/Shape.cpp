#include <cmath>

#include "Shape.h"

Shape::Shape()
    : circle(0),
      velocity_x(0),
      velocity_y(0),
      make_new_shape(false),
      times_hit_wall(0)
{
    circle.setPosition(0, 0);
}


Shape::Shape(float x, float y, float radius)
    : circle(radius),
      velocity_x(0),
      velocity_y(0)
{
    circle.setPosition(x, y);
}


void Shape::draw(sf::RenderWindow & window) const
{
    window.draw(circle);
}


void Shape::setVelocity(float vx, float vy)
{
    velocity_x = vx;
    velocity_y = vy;
}


void Shape::setPosition(float x, float y)
{
    circle.setPosition(x, y);
}


void Shape::setRadius(float r)
{
    circle.setRadius(r);
}


void Shape::move(float seconds, const sf::Vector2u & window_size)
{
    float current_x = circle.getPosition().x;
    float current_y = circle.getPosition().y;

    float next_x = current_x + seconds * velocity_x;
    float next_y = current_y + seconds * velocity_y;

    circle.setPosition(next_x, next_y);

    checkWalls(window_size);
}


bool Shape::checkWalls(const sf::Vector2u & window_size)
{
    bool hit_a_wall = false;

    float top = circle.getPosition().y;
    if (top < 0)
    {
        velocity_y = std::abs(velocity_y);
        hit_a_wall = true;
    }

    float left = circle.getPosition().x;
    if (left < 0)
    {
        velocity_x = std::abs(velocity_x);
        hit_a_wall = true;
    }

    float bottom = top + circle.getGlobalBounds().height;
    if (bottom > window_size.y)
    {
        velocity_y = -std::abs(velocity_y);
        hit_a_wall = true;
    }

    float right = left + circle.getGlobalBounds().width;
    if (right > window_size.x)
    {
        velocity_x = -std::abs(velocity_x);
        hit_a_wall = true;
    }

    if (hit_a_wall)
        times_hit_wall++;
    
    if (hit_a_wall and times_hit_wall == 1)
        make_new_shape = true;

    return hit_a_wall;
}


Shape * Shape::getNewShape()
{
    if (!make_new_shape)
        return nullptr;

    make_new_shape = false;
    Shape * sp = new Shape();
    return sp;
}


bool Shape::shouldBeDeleted() const
{
    return (times_hit_wall > 1);
}



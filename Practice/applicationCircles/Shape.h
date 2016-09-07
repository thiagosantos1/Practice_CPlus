#ifndef SHAPE_H
#define SHAPE_H  
 
#include <SFML/Graphics.hpp>

class Shape
{
public:
    Shape();
    Shape(float x, float y, float radius);

    void draw(sf::RenderWindow & window) const;

    void setRadius(float r);
    void setPosition(float x, float y);
    void setVelocity(float vx, float vy);

    void move(float seconds, const sf::Vector2u & window_size);

    // where there's a new shape, it's change, and ShapeManager check every time if shapes has a new child
    // return a pointer to a new shape if needed, otherwise returns NULL
    Shape * getNewShape();

    // track if the shape has to be delete( when it hit the wall for the second time)
    bool shouldBeDeleted();

    

private:
    bool checkWalls(const sf::Vector2u & window_size);

    sf::CircleShape circle;

    // Measure velocity in pixels per second
    float velocity_x;
    float velocity_y;

    bool make_new_shape;

    int times_hit_wall;
};  


#endif
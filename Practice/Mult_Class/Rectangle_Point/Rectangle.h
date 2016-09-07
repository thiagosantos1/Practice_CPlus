#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Point.h"

class Rectangle
{
public:
    // Notice that some of the functions are defined here. They are called
    // "inline" functions. Other functions only have a prototype here, and
    // their implementation goes in the Rectangle.cpp file.

    Rectangle(const Point & topleft_in, int width_in, int height_in);

    int getWidth() const
    {
        return width;
    }

    int getHeight() const
    {
        return height;
    }

    Point getTopleft() const
    {
        return topleft;
    }

    int getArea() const
    {
        return width * height;
    }

    void setWidth(int new_width)
    {
        width = new_width;
    }

    void setHeight(int new_height)
    {
        height = new_height;
    }

    void setTopleft(const Point & p)
    {
        topleft = p;
    }

    bool operator==(const Rectangle & other);

    bool contains(const Point & p) const;

private:
    Point topleft;
    int width;
    int height;
};


// "cannot" use using namespace std, bad code
// pq tbm todo o codigo e copiado para a classe que importa esse file
// sendo assim, usando namespace indica que o outro aquivo tbm sera afetado
// e passara a usar o namespace std tbm, porem o arquivo pode nao querer o usar
// then, have to use std::....

std::ostream & operator<<(std::ostream & lhs, const Rectangle & r);


#endif
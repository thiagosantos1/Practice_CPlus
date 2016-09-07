// // Sample code where we've converted the Rectangle to a class. Now we need to
// // update several uses of private members and generally clean up the code.

 #include <iostream>
 using namespace std;

struct Point
{
    int x;
    int y;
};


bool operator==(const Point& lhs, const Point& rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}


ostream & operator<<(ostream & lhs, const Point & p)
{
    lhs << '(' << p.x << ", " << p.y << ')';
    return lhs;
}

class Rectangle
{
public:
    Rectangle(const Point & topleft_in, int width_in, int height_in)
    {
        topleft = topleft_in;
        width = width_in;
        height = height_in;
    }

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

    bool operator==(const Rectangle & other)
    {
        return topleft == other.topleft &&
               width == other.width &&
               height == other.height;
    }

    bool contains(const Point & p);
    

    // all the variables on private: cannot be change outside, however, you can use
    // the type "friend" above, that allows the functions you're making as friend to allow 
    // to change everything in the class
    // same as ToString in java
    friend ostream & operator <<(ostream & lhs, const Rectangle & r);

private:
    Point topleft;
    int width;
    int height;
};




// This function have to be outside, because the operator << use ostream as 1 value by reference
// if you put inside of the class, the "object" of the class will be always the 1 argument

ostream & operator<<(ostream & lhs, const Rectangle & r)
{
    // we don't have to use gets, because the function is a friend of the class
    lhs << "Top:    " << r.topleft.y << endl
        << "Bottom: " << r.topleft.y - height << endl
        << "Left:   " << r.topleft.x << endl
        << "Right:  " << r.topleft.x + width << endl;

    return lhs;
}



 int main(int argc, char const *argv[])
 {

       Point q = {2, 4};
       Rectangle a(q, 3, 2);

       Point p = {3, 4};

        if (a.contains(p))
        {
            cout << "p is inside a" << endl;
        }

     return 0;
 }


// forma diferente de usar o method. Assim como antes, temos a declaraçao da  funçao e o methodo
 // sendo que vc declara dentro da classe e cria f

    bool Rectangle::contains(const Point & p)
    {
        // Point to the left
        if (p.x < topleft.x)
            return false;

        // Point to the right
        if (p.x > topleft.x + width)
            return false;

        // Point above
        if (p.y > topleft.y)
            return false;

        // Point below
        if (p.y < topleft.y - height)
            return false;

        return true;
    }





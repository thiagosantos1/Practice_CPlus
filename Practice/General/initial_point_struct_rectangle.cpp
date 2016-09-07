#include <iostream>
using namespace std;

/*
struct Point
{
    int x, y;
};

bool isEqual(const Point& lhs, const Point& rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}

bool operator==(const Point& lhs, const Point& rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}

bool operator<(const Point& lhs, const Point& rhs){


    return lhs.x < rhs.x;
}

void print(const Point & p)
{
    cout << '(' << p.x << ", " << p.y << ')';
}

ostream & operator<<(ostream & lhs, const Point & p)
{
    lhs << '(' << p.x << ", " << p.y << ')';
    return lhs;
}
*/

// new structe 

struct Rectangle
{
    Point topleft; // it's enough to localizate where is the rectangle
    Point bottomright // agr vc tem os pontos distintos, entao temos aulture e largura
};

bool operator==(const Rectangle & lhs, const Rectangle & rhs)
{
    return lhs.topleft == rhs.topleft && lhs.bottomright == rhs.bottomright;
}

ostream & operator<<(ostream & lhs, const Rectangle & r)
{
    // imagine como iprimir o retangulo, tendo apenas as coordenadas das pontas topesq e bottomdireit
    lhs <<  "Top: " << r.topleft.y <<endl;  // cordenada na ret y, pois ponto da esquerda
        << "Bottom " << r.bottomright.y <<endl; // coordenada na reta y, point ponto da esquerda
        << "Left " << r.topleft.x <<endl; // coordenada na reta x, poins ponto esta ao exetrmo da reta x
        << " Right " << r.bottomright.x <<endl;
    return lhs;
}

bool inSide(const Point & p, const Rectangle & r){

    
    // make sure the point is between the left and right sides
    // ou seja, estra entre o ponto extremo esquerdo e direito de x
    // basta checar os estremos entao

    // point to the left
    if(p.x < r.topleft.x)
        return false;

    // point to the right
    if(p.x > r.bottomright .x)
        return false;

    //point above
    if(p.y > r.topleft.y)
        return false

    //point below
    if(p.y < r.bottomright.y)
        return false;

    return true;
}

int main(int argc, char const *argv[])
{


    Rectangle a= { {2,4}, {3,2} };
    
    Point p ={3,4}

    if(inSide(p,a)){

        cout <<"P is inside of a" <<endl;
    }




 
    /* For example of Structe Point
    Point a = {3, 6};
    Point b = {3, 5};
/*
    if (isEqual(a, b))
    {
        cout << "Point a ";
        print(a);
        cout << " is the same as Point b." << endl;
    }
    else
    {
        cout << "Point a ";
        print(a);
        cout << " is not the same as Point b ";
        print(b);
        cout << "." << endl;
    }
    


    //another form to do that(operator Overloading)
    // but you can change the signals, criating a function with the name operator +  any operator
    // to overwrite the operator, example below
    // good to make the code simple and beautiful

    if (a ==  b)  // same to if(operator==(a,b))
    {
        cout << "Point a ";
        //print(a);
        //same
        cout << a;
        cout << " is the same as Point b." << endl;
    }
    else
    {
        cout << "Point a ";
       // print(a);
        //same
       cout  << a;
        cout << " is not the same as Point b ";
        print(b);
        cout << "." << endl;
    }
    /*

    if(a<b){
        cout<<"A i less than B\n";
    }


    */



    
    return 0;
}
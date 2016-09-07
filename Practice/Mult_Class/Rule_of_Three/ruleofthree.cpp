#include <iostream>
using namespace std;

class Array
{
public:
    // constructor and default constructor toguether
    Array(int size=5)
    {
        data = new int[size];
        capacity = size;
    }

    // Rule number 3 // copying array by constructor
    Array(const Array & other)
    {
        capacity = other.capacity;
        data = new int[capacity];

        for (int i = 0; i < capacity; i++)
        {
            data[i] = other.data[i];
        }
    }

    // rule number 2 // copying array by deep copy

    void operator=(const Array & other)
    {
        delete [] data;
        capacity = other.capacity;
        data = new int[capacity];

        for (int i = 0; i < capacity; i++)
        {
            data[i] = other.data[i];
        }
    }

    int getData(int idx) const
    {
        return data[idx];
    }

    void setData(int idx, int val)
    {
        data[idx] = val;
    }

    // Rule number 1 
    ~Array()
    {
        delete [] data;
    }

private:
    int * data;
    int capacity;
};


int main()
{
    
    Array a(10);
    // deep copy
    Array b = a;
    //copying by constructor
    Array c(a);

    return 0;
}








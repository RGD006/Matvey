#include <iostream>
#include "vector.h"

int main()
{
    Vector a(3);
    Vector b(3);

    inputVector(a);
    inputVector(b);

    printVector(a);
    printVector(b);
    
    Vector c = a * b;

    printVector(c);

    Vector d = c * 2;

    printVector(d);

    return 0;
}
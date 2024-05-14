#ifndef VECTORH
#define VECTORH

class Vector
{
private:
    double* vec;
    int size;
public:
    Vector(int _size);
    int getSize() { return size; };  
    friend Vector operator*(Vector a, Vector b);
    friend Vector operator*(Vector a, double x);
    double& operator[] (int index);
};

void printVector(Vector& vec); 
void inputVector(Vector& vec);

#endif
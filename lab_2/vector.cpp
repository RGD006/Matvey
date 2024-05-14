#include "vector.h"
#include <iostream>

Vector::Vector(int _size)
{
    if (_size >= 0)
    {
        size = _size;
        vec = new double[size];
    }
}

double& Vector::operator[] (int index)
{
    return vec[index];
}

Vector operator*(Vector a, Vector b)
{
    if (a.size == b.size)
    {
        Vector tmp(a.size);
        for (int i = 0; i < a.size; i++)
        {
            tmp[i] = a[i] * b[i];
        }
        return tmp;
    }
}

Vector operator*(Vector a, double x)
{
    Vector tmp(a.size);
    for (int i = 0; i < a.size; i++)
    {
        tmp[i] = a[i] * x;  
    }
    return tmp;
}

void printVector(Vector &vec)
{
    for (int i = 0; i < vec.getSize(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl; 
}

void inputVector(Vector &vec)
{
    std::cout << "Enter the value of vector: " << std::endl;
    for (int i = 0; i < vec.getSize(); i++)
    {
        std::cout << "[" << i << "] = ";
        std::cin >> vec[i]; 
    }
}
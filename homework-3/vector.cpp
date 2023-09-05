#include "vector.h"
#include <cassert>
#include <iostream>

using namespace std;

int Vector::getSize() { return size; }

void Vector::readData()
{
    cout << "Enter the " << size << " components of the vector:\n";
    for (int component = 0; component < size; component++)
    {
        cout << "vector[" << component << "] = ";
        cin >> data[component];
    }
    cout << endl;
}

void Vector::print()
{
    cout << "(";
    for (int idx = 0; idx < size - 1; idx++)
    {
        cout << data[idx] << ", ";
    }
    cout << data[size - 1] << ")" << endl;
}

double &Vector::operator[](int idx)
{
    assert(idx >= 0 && idx <= size);
    return data[idx];
}

Vector Vector::operator=(Vector &v)
{
    // Method prototype was `Vector &Vector::operator=(Vector &v)`, but
    // we cannot return a reference to a local variable because local
    // variables are destroyed after the return value.
    Vector returnVector(v.getSize());
    for (int idx = 0; idx < size; idx++)
    {
        returnVector[idx] = v[idx];
    }
    return returnVector;
}

Vector::Vector(int n)
{
    size = n;
    data = new double[n];
}

Vector::~Vector()
{
    // Dynamically allocated data using the `new` operator is allocated on the
    // heap and is therefore not deleted automatically when the object goes
    // out of scope. Here we delete manually to prevent memory leaks.
    delete[] data;
}

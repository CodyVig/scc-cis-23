#include "vectorType.h"
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

Vector &Vector::operator=(Vector &v)
{
    if (this == &v) { return *this; }

    // Reallocate memory for vector of correct size
    reshape(v.getSize());

    for (int idx = 0; idx < size; idx++)
    {
        data[idx] = v[idx];
    }

    return *this;
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

void Vector::reshape(int n)
{
    delete[] data;
    size = n;
    data = new double[n];
}

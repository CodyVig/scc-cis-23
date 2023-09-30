#include "vectorType.h"
#include <iostream>

using namespace std;

template <class dataType> int Vector<dataType>::getSize() { return size; }

template <class dataType> void Vector<dataType>::readData()
{
    cout << "Enter the " << size << " components of the vector:\n";
    for (int component = 0; component < size; component++)
    {
        cout << "vector[" << component << "] = ";
        cin >> data[component];
    }
    cout << endl;
}

template <class dataType> void Vector<dataType>::print()
{
    cout << "(";
    for (int idx = 0; idx < size - 1; idx++)
    {
        cout << data[idx] << ", ";
    }
    cout << data[size - 1] << ")" << endl;
}

template <class dataType> dataType &Vector<dataType>::operator[](int idx)
{
    assert(idx >= 0 && idx <= size);
    return data[idx];
}

template <class dataType>
Vector<dataType> &Vector<dataType>::operator=(Vector<dataType> &v)
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

template <class dataType> void Vector<dataType>::reshape(int n)
{
    delete[] data;
    size = n;
    data = new dataType[n];
}

template <class dataType> Vector<dataType>::Vector(int n)
{
    size = n;
    data = new dataType[n];
}

template <class dataType> Vector<dataType>::~Vector() { delete[] data; }
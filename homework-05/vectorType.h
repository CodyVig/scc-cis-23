#include <cassert>
#include <iostream>

using namespace std;

/**
 * Template class for variable-size vectors stored using dynamic arrays.
 */
template <class dataType> class Vector
{
public:
    /** Returns the size of the array. */
    int getSize();

    /** Prompts the user to enter data into the array. */
    void readData();

    /** Prints the array in a human-readable from. */
    void print();

    /**
     * Overloads index retrieval.
     *
     * @param `idx`: The index of the component we wish to retrieve.
     * @return The element at index `idx`.
     */
    dataType &operator[](int idx);

    /**
     * Overloads vector assignment via deep copy.
     *
     * @param `v`: Another `Vector` object.
     * @return a deep copy of `v` at a distinct location in memory.
     */
    Vector &operator=(Vector &v);

    /**
     * Sets the size of the array.
     *
     * @param `n`: The number of components of the `Vector` object (defaults to
     * 0).
     */
    Vector(int n = 0);

    /** Destructor to prevent memory leaks with dynamic array. */
    ~Vector();

private:
    /**
     * Deletes `size` and `data` and reinitializes the vector object to be of
     * size `n`. Helper function for assignment `=` overload.
     *
     * @param `n`: The new number of components of the `Vector` object.
     */
    void reshape(int n);

    int size;
    dataType *data;
};

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
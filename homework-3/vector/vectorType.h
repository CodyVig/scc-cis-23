#ifndef VECTORTYPE_H_
#define VECTORTYPE_H_

/**
 * Variable-size vectors stored using dynamic arrays.
 */
class Vector
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
    double &operator[](int idx);

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
    double *data;
};

#endif

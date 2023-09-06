#ifndef VECTORTYPE_H_
#define VECTORTYPE_H_

class Vector
{
public:
    /** Returns the size of the array. */
    int getSize();

    /** Prompts the user to enter data into the array */
    void readData();

    /** Prints the array in a human-readable from. */
    void print();

    /** Deletes `size` and `data` and reinitializes the vector object to be of
     * size `n`.
     */
    void reshape(int n);

    /** Overloads index retrieval */
    double &operator[](int idx);

    /** Overloads vector assignment via deep copy */
    Vector &operator=(Vector &v);

    /** Sets the size of the array */
    Vector(int n = 0);

    /** Destructor to prevent memory leaks with dynamic array */
    ~Vector();

private:
    int size;
    double *data;
};

#endif

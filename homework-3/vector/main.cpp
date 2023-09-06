/*****************************************************************************
 * Author:       Cody Vig
 * Assignment:   Homework 3
 * Due Date:     September 13, 2023.
 *****************************************************************************/

#include "vectorType.h"

#include <iostream>

using namespace std;

/**
 * Tests dynamic arrays within `Vector` class.
 */
int main()
{
    Vector v1(3);
    Vector v2;

    v1.readData();
    cout << "v1 = ";
    v1.print();

    cout << "\nDeep copying v1 into v2...\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    v2 = v1;
    cout << "v1 = ";
    v1.print();
    cout << "v2 = ";
    v2.print();

    // Showing that v2 is a deep copy and not a shallow one.
    cout << "\nChanging components of v1...\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    v1[0] = 3.14;
    v1[1] = 1.414;
    v1[2] = 1729;
    cout << "v1 = ";
    v1.print();
    cout << "v2 = ";
    v2.print();

    return 0;
}
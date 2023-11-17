/*****************************************************************************
 * Author:       Cody Vig
 * Assignment:   Homework 5
 * Due Date:     October 3, 2023.
 *****************************************************************************/

#include "vectorType.h"

#include <iostream>

using namespace std;

/**
 * Tests dynamic arrays within `Vector` class.
 */
int main()
{
    // Integer vectors:
    cout << "Testing `Vector<int>`...\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Vector<int> v1(3);
    Vector<int> v2;

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
    v1[0] = 3142;
    v1[1] = 1414;
    v1[2] = 1729;
    cout << "v1 = ";
    v1.print();
    cout << "v2 = ";
    v2.print();

    // Double vectors:
    cout << "\nTesting `Vector<double>`...\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Vector<double> v3(3);
    Vector<double> v4;

    v3.readData();
    cout << "v3 = ";
    v3.print();

    cout << "\nDeep copying v3 into v4...\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    v4 = v3;
    cout << "v3 = ";
    v3.print();
    cout << "v4 = ";
    v4.print();

    // Showing that v2 is a deep copy and not a shallow one.
    cout << "\nChanging components of v3...\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    v3[0] = 3.14;
    v3[1] = 1.414;
    v3[2] = 1.618;
    cout << "v1 = ";
    v3.print();
    cout << "v2 = ";
    v4.print();

    return 0;
}
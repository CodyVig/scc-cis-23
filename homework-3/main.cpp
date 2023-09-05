#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
    Vector v1(3);
    Vector v2;

    v1.readData();
    cout << "v1 = ";
    v1.print();

    cout << "Deep copying v1 into v2...\n";
    v2 = v1;
    cout << "v1 = ";
    v1.print();
    cout << "v2 = ";
    v2.print();

    cout << "Changing components of v1...\n";
    v1[2] = 1729;
    cout << "v1 = ";
    v1.print();
    cout << "v2 = ";
    v2.print();

    return 0;
}
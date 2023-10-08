/**
 * D.S. Malik, C++ 8th Edition
 * Chapter 15 Problem 12
 */

#include <iostream>

using namespace std;

int gcd(int, int);

int main(int argc, char **argv)
{
    int x, y, divisor;

    if (argc == 1)
    {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }
    else if (argc == 3)
    {
        x = atof(argv[1]);
        y = atof(argv[2]);
    }
    else
    {
        throw domain_error("Invalid command line arguments.");
        return 1;
    }

    divisor = gcd(x, y);

    cout << ">>> "
         << "gcd(" << x << ", " << y << ") = " << divisor << "." << endl;

    return 0;
}

/** Finds the greatest common divisor of `x` and `y` via recursion. */
int gcd(int x, int y)
{
    if (y == 0) { return x; }
    else { return gcd(y, x % y); }
}
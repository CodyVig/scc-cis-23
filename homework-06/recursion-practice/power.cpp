/**
 * D.S. Malik, C++ 8th Edition
 * Chapter 15 Problem 11
 */

#include <iostream>

using namespace std;

double power(int, int);

int main(int argc, char **argv)
{
    int x, y;
    double p;

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

    p = power(x, y);

    cout << ">>> " << x << " ** " << y << " = " << p << "." << endl;

    return 0;
}

/** Caclulates x ** y using recursion. */
double power(int x, int y)
{
    if (y == 0) { return 1; }
    if (y == 1) { return x; }
    if (y > 1) { return x * power(x, y - 1); }
    if (y < 0) { return 1 / power(x, -y); }
    else { throw domain_error("Invalid x or y."); }
}
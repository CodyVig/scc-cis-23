/**
 * D.S. Malik, C++ 8th Edition
 * Chapter 15 Problem 13
 */

#include <iostream>

using namespace std;

unsigned long long ackermann(unsigned long long, unsigned long long);

int main(int argc, char **argv)
{
    unsigned long long m, n, a;

    if (argc == 1)
    {
        cout << "Enter m: ";
        cin >> m;
        cout << "Enter n: ";
        cin >> n;
    }
    else if (argc == 3)
    {
        m = atof(argv[1]);
        n = atof(argv[2]);
    }
    else
    {
        throw domain_error("Invalid command line arguments.");
        return 1;
    }

    cout << "Calculating A(" << m << ", " << n << ")...\n";
    a = ackermann(m, n);
    cout << "\033[A"    // Move cursor up one line
         << "\33[2K\r"; // Delete current line

    cout << ">>> "
         << "A(" << m << ", " << n << ") = " << a << "." << endl;

    return 0;
}

/**
 * Caclulates Ackermann's function for small inputs via recursion.
 *
 * See:
 * https://en.wikipedia.org/wiki/Ackermann_function#Table_of_values
 */
unsigned long long ackermann(unsigned long long m, unsigned long long n)
{
    // cout << "(m, n) = (" << m << ", " << n << ")\n";
    if (m < 0 || n < 0) { throw domain_error("m and n must be nonnegative!"); }
    else if (m == 0) { return n + 1; }
    else if (m > 0 && n == 0) { return ackermann(m - 1, 1); }
    else { return ackermann(m - 1, ackermann(m, n - 1)); }
}
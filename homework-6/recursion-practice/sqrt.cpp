#include <iostream>

using namespace std;

double newtonSqrt(double x, double epsilon = 0.001);
double recursiveSqrt(double x, double a, double epsilon = 0.001);

int main(int argc, char **argv)
{
    double x, sn, sr;

    if (argc == 1)
    {
        cout << "Enter `x`: ";
        cin >> x;
    }
    else if (argc == 2) { x = atof(argv[1]); }
    else
    {
        throw domain_error("Invalid command line arguments.");
        return 1;
    }

    cout << "Testing base "
            "implementation...\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    sn = newtonSqrt(x);

    cout << ">>> "
         << "sqrt(" << x << ") = " << sn << ".\n\n";

    cout << "Testing recursive implementation...\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    sr = recursiveSqrt(x, x);

    cout << ">>> "
         << "sqrt(" << x << ") = " << sr << ".\n";

    return 0;
}

double newtonSqrt(double x, double epsilon)
{
    double a = x;

    while (a * a - x > epsilon || a * a - x < -epsilon)
    {
        a = (a * a + x) / (2 * a);
    }

    return a;
}

double recursiveSqrt(double x, double a, double epsilon)
{
    if (a * a - x < epsilon && a * a - x > -epsilon) { return a; }
    return recursiveSqrt(x, (a * a + x) / (2 * a), epsilon);
}

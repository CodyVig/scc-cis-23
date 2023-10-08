#include <iostream>

using namespace std;

int sumSquares(int n);

int main()
{
    int n;

    cout << "Enter a nonnegative integer: ";
    cin >> n;

    cout << "The sum of the squares of the numbers from 0 to " << n << " is "
         << sumSquares(n) << "." << endl;

    return 0;
}

int sumSquares(int n)
{
    if (n == 1) { return 1; }
    return (n * n + sumSquares(n - 1));
}
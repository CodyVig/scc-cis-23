#include <cmath>
#include <iostream>

using namespace std;

/**
 * Struct abstracting the idea of (x, y) points in R^2.
 */
struct coordinate
{
    double x;
    double y;
};

double computeDistance(const coordinate &, const coordinate &);

int main()
{
    coordinate p1;
    coordinate p2;
    double dist;

    cout << "Enter x and y coordinates: ";
    cin >> p1.x >> p1.y;
    cout << "Enter a second x and y coordinate: ";
    cin >> p2.x >> p2.y;

    dist = computeDistance(p1, p2);

    cout << "The distance between "
         << "(" << p1.x << ", " << p1.y << ") and (" << p2.x << ", " << p2.y
         << ") is " << dist << "." << endl;

    return 0;
}

/**
 * Returns the Euclidean distance between coordinates `p1` and `p2`.
 *
 * @param p1: The first coordinate.
 * @param p2: The second coordinate.
 * @return A double representing the Euclidean distance |p2 - p1|.
 */
double computeDistance(const coordinate &p1, const coordinate &p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
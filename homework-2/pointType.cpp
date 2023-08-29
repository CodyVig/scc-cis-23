/* Implementation for pointType.h */

#include "pointType.h"
#include <cmath>
#include <iostream>

using namespace std;

/* Setters and getters for x, y coordinates */
void pointType::setPoint(double a, double b)
{
    x = a;
    y = b;
}

void pointType::setX(double a) { x = a; }

double pointType::getX() { return x; }

void pointType::setY(double b) { y = b; }

double pointType::getY() { return y; }

/**
 * alculates Euclidean distance to another pointType
 *
 * @param second pointType
 * @return double representing distance
 */
double pointType::distance(pointType &point)
{
    return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
}

/**
 * Print out coordinates
 */
void pointType::print() const { cout << "(" << x << ", " << y << ")" << endl; }

/** Constructor that takes in coordinates */
pointType::pointType(double a, double b) { setPoint(a, b); }
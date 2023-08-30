/* Implementation for pointType.h */

#include "pointType.h"
#include <cmath>
#include <iostream>

using namespace std;

void pointType::setPoint(double a, double b)
{
    x = a;
    y = b;
}

void pointType::setX(double a) { x = a; }

double pointType::getX() { return x; }

void pointType::setY(double b) { y = b; }

double pointType::getY() { return y; }

double pointType::distance(pointType &point)
{
    return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
}

void pointType::print() const { cout << "(" << x << ", " << y << ")" << endl; }

pointType::pointType(double a, double b) { setPoint(a, b); }
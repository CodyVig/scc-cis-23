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

double pointType::getX() const { return x; }

void pointType::setY(double b) { y = b; }

double pointType::getY() const { return y; }

double pointType::distance(pointType &p) const
{
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

void pointType::print() const { cout << "(" << x << ", " << y << ")" << endl; }

pointType::pointType(double a, double b) { setPoint(a, b); }
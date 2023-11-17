
/* shapeType  implementation file
 */

#include "shapeType.h"
#include <iomanip>
#include <iostream>

using namespace std;

void shapeType::setArea(double a) { area = a; }

void shapeType::setPerimeter(double p) { perimeter = p; }

double shapeType::getArea() const { return area; }

double shapeType::getPerimeter() const { return perimeter; }

void shapeType::print() const
{
    cout << setprecision(2);
    cout << "2D shape" << endl;
    cout << "\tArea = " << area << endl;
    cout << "\tPerimeter = " << perimeter << endl;
}

shapeType::shapeType()
{
    area = -1;
    perimeter = -1;
}

/* shapeType  implementation file
 */

#include "shapeType.h"
#include <iomanip>
#include <iostream>

using namespace std;

/**
 * Sets the area
 *
 * @param a: a double representing area
 */
void shapeType::setArea(double a) { area = a; }

/**
 * Sets the perimeter
 *
 * @param p: a double representing perimeter of shape
 */
void shapeType::setPerimeter(double p) { perimeter = p; }

/**
 * Returns area
 *
 * @return area double
 */
double shapeType::getArea() const { return area; }

/**
 * Returns perimeter
 *
 *@return double perimeter
 */
double shapeType::getPerimeter() const { return perimeter; }

/**
 * Prints information about the shapeType
 * (area and perimeter)
 */
void shapeType::print() const
{
    cout << setprecision(2);
    cout << "2D shape" << endl;
    cout << "\tArea = " << area << endl;
    cout << "\tPerimeter = " << perimeter << endl;
}

/**
 * Default constructor. Sets the area and perimeter to -1
 * to signify it hasn't been set yet.
 */
shapeType::shapeType()
{
    area = -1;
    perimeter = -1;
}
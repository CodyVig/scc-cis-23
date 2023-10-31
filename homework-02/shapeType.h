
/*
 * Represents any 2D shape with a perimeter and area.
 */

#ifndef H_SHAPETYPE
#define H_SHAPETYPE

#include <iostream>

using namespace std;

/**
 * `shapeType` class is a base class for geometric shapes in R^2. Contains
 * doubles for area and perimeter.
 */
class shapeType
{
public:
    /**
     * Sets private `area`.
     *
     * @param a: The area of the shape.
     */
    void setArea(double a);

    /**
     * Sets private `perimeter`.
     *
     * @param p: The perimeter of the shape.
     */
    void setPerimeter(double p);

    /**
     * Retrieves the area of the shape.
     */
    double getArea() const;

    /**
     * Retrieves the perimeter of the shape.
     */
    double getPerimeter() const;

    /**
     * Prints 'area' and 'perimeter' of the shape.
     */
    void print() const;

    /**
     * Default constructor. Sets the area and perimeter to -1 to signify it
     * hasn't been set yet.
     */
    shapeType();

private:
    double area;
    double perimeter;
};

#endif

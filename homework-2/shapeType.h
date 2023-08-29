
/* shapeType definition.
 Represents any 2D shape with a perimeter and area.
 */

#ifndef H_SHAPETYPE
#define H_SHAPETYPE

#include <iostream>

using namespace std;

class shapeType
{
private:
	double area;
	double perimeter;

public:
	// setters and getters
	void setArea(double a);
	void setPerimeter(double p);
	double getArea() const;
	double getPerimeter() const;

	// print some info about the shape
	void print() const;

	// constructor
	shapeType();
};

#endif

/*
Question 4: What would change in your code if shapeType.h declared area and
            perimeter to be protected instead of private? What changes, if any,
            would you have to make to circleType?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Answer:     Functionally, nothing would be different. Private and protected
            member variables are both inaccessible from outside of the class.
            The only difference is that protected member variables are
            accessible from subclasses, so instead of calling the setter
            methods for the area and perimeter in our `circleType` constructor,
            we could have just edited the area and perimeter directly.

*/

#include "circleType.h"
#include <cmath>
#include <iostream>

using namespace std;

void circleType::setCenter(pointType c) { center = c; }

void circleType::setRadius(double r) { radius = r; }

void circleType::getCenter(pointType &c) { c = center; }

double circleType::getRadius() const { return radius; }

void circleType::print() const
{
    shapeType::print();

    cout << "\tRadius = " << radius << endl;
    cout << "\tCenter: ";
    center.print();
}

bool circleType::isConcentric(circleType &p)
{
    return p.center.getX() == center.getX() && p.center.getY() == center.getY();
}

circleType::circleType(double r, pointType c)
{
    setRadius(r);
    setCenter(c);

    setPerimeter(2 * M_PI * r);
    setArea(M_PI * r * r);
}

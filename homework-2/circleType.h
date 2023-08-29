/*
Subclass of `shapeType` which stores information about circles.
*/

#ifndef H_CIRCLETYPE
#define H_CIRCLETYPE

#include "pointType.h"
#include "shapeType.h"
#include <iostream>

class circleType : protected shapeType
{
    /*
    We should inherit with protection. We want to call the getters and setters
    of `shapeType` when writing our getters and setters, but we do not want
    users accessing those methods. Instead, we want them to use our
    `circleType` specific getters and setters.
    */

public:
    /**
     * Sets the center of the circle.
     *
     * @param c: `pointType` center of the circle.
     */
    void setCenter(pointType c);

    /**
     * Sets the radius of the circle.
     *
     * @param r: `double` radius of the circle.
     */
    void setRadius(double r);

    /**
     * Retrieves the center of the circle.
     *
     * @param c: `pointType` reference to where the center will be stored.
     */
    void getCenter(pointType &c);

    /**
     * Retrieves the radius of the circle.
     *
     * @return a `double` representing the radius of the circle.
     */
    double getRadius() const;

    /**
     * Prints the center and radius to the console. Calls `pointType::print()`.
     */
    void print() const;

    /**
     * Whether or not `this` and `p` are concentric circles.
     *
     * @param p: A reference to a second `circleType`.
     * @return `true` if concentric, `false` otherwise.
     */
    bool isConcentric(circleType &);

    circleType(double r, pointType c);

private:
    double radius;
    pointType center;
};

#endif
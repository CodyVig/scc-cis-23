/*****************************************************************************
 * Author:       Cody Vig
 * Assignment:   Homework 2
 * Due Date:     September 7, 2023.
 *****************************************************************************/

#include "circleType.h"
#include "pointType.h"
#include "shapeType.h"

#include <iostream>

using namespace std;

/**
 * Prompts user to enter information about two circles. Prints the information
 * and determine whether or not the circle are concentric.
 */
int main()
{
    double x, y, r;

    cout << "Enter first circle's center x coordinate: ";
    cin >> x;
    cout << "Enter first circle's center y coordinate: ";
    cin >> y;
    cout << "Enter first circle's radius: ";
    cin >> r;

    circleType c1 = circleType(r, pointType(x, y));

    cout << "Enter second circle's center x coordinate: ";
    cin >> x;
    cout << "Enter second circle's center y coordinate: ";
    cin >> y;
    cout << "Enter second circle's radius: ";
    cin >> r;

    circleType c2 = circleType(r, pointType(x, y));

    cout << "\nCircle 1 information:\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~\n";

    c1.print();

    cout << "\nCircle 2 information:\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~\n";

    c2.print();

    if (c1.isConcentric(c2)) { cout << "\nThe two circles are concentric.\n"; }
    else { cout << "\nThe two circles are *not* concentric.\n"; }

    return 0;
}

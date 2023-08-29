#include "circleType.h"
#include "pointType.h"
#include "shapeType.h"

#include <iostream>

using namespace std;

int main()
{
    pointType p1 = pointType(0, 0);
    pointType p2 = pointType(1, 2);

    circleType c1 = circleType(1, p1);
    circleType c2 = circleType(3, p2);

    c1.print();

    return 0;
}
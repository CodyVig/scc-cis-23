/*
 * Definition of a pointType object which represents an (x, y) coordinate.
 */

#ifndef H_POINTTYPE
#define H_POINTTYPE

class pointType
{
public:
    void setPoint(double a = 0, double b = 0);
    void setX(double a = 0);
    void setY(double b = 0);

    double getX();
    double getY();

    double distance(pointType &point);
    void print() const;

    pointType(double a = 0.0, double b = 0.0);

private:
    double x;
    double y;
};

#endif

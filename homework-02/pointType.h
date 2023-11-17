/*
 * Definition of a pointType object which represents an (x, y) coordinate.
 */

#ifndef H_POINTTYPE
#define H_POINTTYPE

/**
 * `pointType` object abstracts coordinates in R^2. Base class for `circleType`.
 */
class pointType
{
public:
    void setPoint(double a = 0, double b = 0);
    void setX(double a = 0);
    void setY(double b = 0);

    double getX() const;
    double getY() const;

    /**
     * Calculates Euclidean distance to another `pointType`.
     *
     * @param `p`: A reference to another `pointType`.
     * @return Double representing Euclidean distance.
     */
    double distance(pointType &p) const;

    /**
     * Prints out coordinates in the form (x, y).
     */
    void print() const;

    pointType(double a = 0.0, double b = 0.0);

private:
    double x;
    double y;
};

#endif

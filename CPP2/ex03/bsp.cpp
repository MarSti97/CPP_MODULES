#include "Fixed.hpp"
#include "Point.hpp"

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float A = area (getX(a), getY(a), getX(b), getY(b), getX(c), getY(c));
    float A1 = area (getX(point), getY(point), getX(b), getY(b), getX(c), getY(c));
    float A2 = area (getX(a), getY(a), getX(point), getY(point), getX(c), getY(c));
    float A3 = area (getX(a), getY(a), getX(b), getY(b), getX(point), getY(point));
    return (A == A1 + A2 + A3);
}

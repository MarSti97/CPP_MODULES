#include "Fixed.hpp"
#include "Point.hpp"

float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
    return std::abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float A = area (a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
    float A1 = area (point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
    float A2 = area (a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
    float A3 = area (a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());
	// std::cout << "A = " << A << "\nA1 = " << A1 << "\nA2 = " << A2 << "\nA3 = " << A3 << std::endl;
	if (A1 == 0.0 || A2 == 0.0 || A3 == 0.0)
		return false;
    return (A == A1 + A2 + A3);
}

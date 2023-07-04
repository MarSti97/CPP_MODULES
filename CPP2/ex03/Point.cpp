#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
{
    // std::cout << "default point constructer called" << std::endl;
}

Point::Point(const Point& point) : x(point.x), y(point.y)
{
    // std::cout << "copy point constructer called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	// std::cout << "constructor called" << std::endl;
}

Point::~Point()
{
	// std::cout << "destructor called" << std::endl;
}

float	Point::getX(void) const
{
	return (this->x.toFloat());
}

float	Point::getY(void) const
{
	return (this->y.toFloat());
}
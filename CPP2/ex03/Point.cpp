#include "Point.hpp"

Point::Point()
{
    std::cout << "default point constructer called" << std::endl;
    return ;
}

Point::Point(const Point& point)
{
    std::cout << "copy point constructer called" << std::endl;
    x = point.x;
    y = point.y;
}

Point::Point(const float x, const float y);
Point::~Point();
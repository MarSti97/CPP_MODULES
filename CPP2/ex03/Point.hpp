#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

class Point 
{
    private :
        const Fixed x;
        const Fixed y;
    public :
        Point();
        Point(const Point& point);
        Point(const float x, const float y);
        ~Point();

        Point&  operator = (const Point &point);
		float	getX(void) const;
		float	getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
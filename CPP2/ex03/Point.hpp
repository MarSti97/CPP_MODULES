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

        

}

#endif
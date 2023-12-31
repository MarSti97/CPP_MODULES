#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <bitset>

class Fixed
{
    private :
        int                 value;
        static const int    _bits = 8;
    public :
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int);
        Fixed(const float);
        ~Fixed();

        Fixed&  operator = (const Fixed &fixed);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream&  operator << (std::ostream& out, const Fixed &fixed);

#endif
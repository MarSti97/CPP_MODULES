#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private :
        int                 value;
        static const int    bits = 8;
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
        int     toInt(void) const; //Do i need to round??? test
};

std::ostream&  operator << (std::ostream& out, const Fixed &fixed);

#endif
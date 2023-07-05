#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private :
        int value;
        static const int bits = 8;
    public :
        Fixed();
        Fixed(const Fixed &fixed);
        ~Fixed();
        Fixed&	operator = (const Fixed &fixed);
		
        int		getRawBits(void) const;
        void	setRawBits(int const raw);
};

#endif
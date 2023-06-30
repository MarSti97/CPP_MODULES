#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl << "My tests" << std::endl;
	Fixed const nbr(5.49f);
    std::cout << "nbr as float " << nbr << std::endl;
    std::cout << "nbr as int " << nbr.toInt() << std::endl << std::endl;
	Fixed const nbr2(5.5f);
    std::cout << "nbr2 as float " << nbr2 << std::endl;
    std::cout << "nbr2 as int " << nbr2.toInt() << std::endl << std::endl;
	Fixed const nbr3(5.51f);
    std::cout << "nbr3 as float " << nbr3 << std::endl;
    std::cout << "nbr3 as int " << nbr3.toInt() << std::endl << std::endl;
    return 0;
}
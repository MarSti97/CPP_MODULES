#include "Fixed.hpp"

int main(void)
{
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "My tests" << std::endl;

	Fixed const sum = Fixed(10) + Fixed(5);
	std::cout << "Sum 10 + 5 = " << sum.toInt() << std::endl;
    return 0;
}
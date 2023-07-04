#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "My tests" << std::endl;
	Fixed x(10);
	Fixed y(5);
	Fixed sum = x + y;
	std::cout << "Sum 10 + 5 = " << sum.toInt() << std::endl;
	std::cout << "Min between 10 and 5 :" << Fixed::min(x, y) << std::endl;
	std::cout << "Max between 5 and 10 :" << Fixed::max(Fixed(5), Fixed(10)) << std::endl;
	// std::cout << "incremented " << sum.toInt() << std::endl;

    return 0;
}
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
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	Fixed x(10);
	Fixed y(5);
	Fixed sum = x + y;
	std::cout << "Sum 10 + 5 = " << sum.toInt() << std::endl;
	std::cout << "Min between 10 and 5 :" << Fixed::min(x, y) << std::endl;
	std::cout << "Max between 5 and 10 :" << Fixed::max(Fixed(5), Fixed(10)) << std::endl << std::endl;

	Fixed const x2(10.5f);
	Fixed const y2(5.5f);
	Fixed sum2 = x2 + y2;
	std::cout << "Sum 10.5 + 5.5 = " << sum2.toFloat() << std::endl;
	std::cout << "Min between 10.5 and 5.5 is " << Fixed::min(x2, y2) << std::endl;
	std::cout << "Max between 5.5 and 10.5 is " << Fixed::max(Fixed(5.5f), Fixed(10.5f)) << std::endl << std::endl;
	
	std::cout << "5 - 3 = " << (Fixed(5) - Fixed(3)) << std::endl;
	std::cout << "5.5 - 3.3 = " << (Fixed(5.5f) - Fixed(3.3f)) << std::endl;
	std::cout << "2 * 3 = " << (Fixed(2) * Fixed(3)) << std::endl;
	std::cout << "2.2 * 3.3 = " << (Fixed(2.2f) * Fixed(3.3f)) << std::endl;
	std::cout << "2 / 3 = " << (Fixed(2) / Fixed(3)) << std::endl;
	std::cout << "2.2 / 3.3 = " << (Fixed(2.2f) / Fixed(3.3f)) << std::endl;
	if(x2 > y2)
		std::cout << "10.5 is bigger then 5.5" << std::endl;
	else
		std::cout << "10.5 is NOT bigger then 5.5" << std::endl;
	if(x2 < y2)
		std::cout << "10.5 is smaller then 5.5" << std::endl;
	else
		std::cout << "10.5 is NOT smaller then 5.5" << std::endl;
	if(x2 != y2)
		std::cout << "10.5 doen't equal 5.5" << std::endl;
	else
		std::cout << "10.5 equals 5.5" << std::endl;
	if(x2 == y2)
		std::cout << "10.5 equals 5.5" << std::endl;
	else
		std::cout << "10.5 doen't equal 5.5" << std::endl;
    return 0;
}
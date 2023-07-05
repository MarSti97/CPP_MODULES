#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	std::cout << "          a (10, 15)		" << std::endl;
	std::cout << "          /\\				" << std::endl;
	std::cout << "         /  \\			" << std::endl;
	std::cout << "        /  P \\			" << std::endl;
	std::cout << "       /      \\			" << std::endl;
	std::cout << "b(0.0) ---------  c(20,0)	" << std::endl;
	std::cout << "P = (5,5)" << std::endl;

	Point a(10, 15);
	Point b(0, 0);
	Point c(20, 0);
	Point P(5, 5);
	if (bsp(a, b, c, P))
		std::cout << "This point is inside!" << std::endl;
	else
		std::cout << "This point is outside!" << std::endl;

	std::cout << std::endl << "          a (10, 15)		" << std::endl;
	std::cout << "          /\\	   P	" << std::endl;
	std::cout << "         /  \\			" << std::endl;
	std::cout << "        /    \\			" << std::endl;
	std::cout << "       /      \\			" << std::endl;
	std::cout << "b(0.0) ---------  c(20,0)	" << std::endl;
	std::cout << "P = (30,30)" << std::endl;

	Point e(0.5, 0.5);
	Point f(1.5, 1.5);
	Point g(1.0, 2.5);
	Point P2(1.0, 2.5);
	P = P2;
	std::cout << "P x: " << P.getX() << "\nP y: " << P.getY() << std::endl;
	if (bsp(e, f, g, P))
		std::cout << "This point is inside!" << std::endl;
	else
		std::cout << "This point is outside!" << std::endl;
    return 0;
}
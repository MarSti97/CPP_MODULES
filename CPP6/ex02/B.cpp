#include "Base.hpp"
#include "B.hpp"

B::B() : type("B")
{
	std::cout << "B constructor" << std::endl;
}

B::~B()
{
	std::cout << "B destructor" << std::endl;
}

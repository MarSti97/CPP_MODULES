#include "Base.hpp"
#include "C.hpp"

C::C() : type("C")
{
	std::cout << "C constructor" << std::endl;
}

C::~C()
{
	std::cout << "C destructor" << std::endl;
}

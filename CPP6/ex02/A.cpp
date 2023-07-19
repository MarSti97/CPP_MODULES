#include "Base.hpp"
#include "A.hpp"

A::A() : type("A")
{
	std::cout << "A constructor" << std::endl;
}

A::~A()
{
	std::cout << "A destructor" << std::endl;
}

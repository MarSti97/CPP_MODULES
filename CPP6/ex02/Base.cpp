#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	// std::cout << "Base destructor" << std::endl;
}

Base*	generate(void)
{
	int randomNum = rand() % 3;
	Base* res;
	switch (randomNum)
	{
		case 0:
			std::cout << "A generated." << std::endl;
			res = new A();
			break ;
		case 1:
			std::cout << "B generated." << std::endl;
			res = new B();
			break ;
		case 2:
			std::cout << "C generated." << std::endl;
			res = new C();
			break ;
	}
	return res;
}

void	identify(Base* p)
{
	A* a = dynamic_cast<A*> (p);
	if (a)
		std::cout << "A detected!" << std::endl;
	B* b = dynamic_cast<B*> (p);
	if (b)
		std::cout << "B detected!" << std::endl;
	C* c = dynamic_cast<C*> (p);
	if (c)
		std::cout << "C detected!" << std::endl;
}

void	identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&> (p);
		std::cout << "A detected!" << std::endl;
		(void)a;
	}
	catch (std::exception& e) {}

	try {
		B& b = dynamic_cast<B&> (p);
		std::cout << "B detected!" << std::endl;
		(void)b;
	}
	catch (std::exception& e) {}

	try {
		C& c = dynamic_cast<C&> (p);
		std::cout << "C detected!" << std::endl;
		(void)c;
	}
	catch (std::exception& e) {}
}
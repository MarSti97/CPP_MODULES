#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	std::srand(std::time(0));
    {
        std::cout << "----- Basic test -----" << std::endl;
        Base* random = generate();
        identify(random);
		delete random;
    }
    {
        std::cout << "----- Reference test -----" << std::endl;
        Base* random2 = generate();
        identify(*random2);
		delete random2;
    }
}
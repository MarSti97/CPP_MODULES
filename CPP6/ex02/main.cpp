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
    }
    {
        std::cout << "----- Reference test -----" << std::endl;
        Base* random2 = generate();
        identify(random2);
    }
}
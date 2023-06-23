#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "String address: " << &str << std::endl;
	std::cout << "Pointer address: " << &strPTR << std::endl;
	std::cout << "Reference address: " << &strREF << std::endl;
	std::cout << std::endl;
	std::cout << "String value: " << str << std::endl;
	std::cout << "Pointer value: " << *strPTR << std::endl;
	std::cout << "Reference value: " << strREF << std::endl;
}
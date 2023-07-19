#include "Serializer.hpp"

int main()
{
	uintptr_t nbr = 42;
	Data* empty;
	Data* data;
	data->i = 73;
	data->c = 'M';
	Serializer ser;
	std::cout << nbr << " and " << nbr* << std::endl;
	std::cout << std::endl;
	empty = ser.deserialize(nbr);
	std::cout << empty* << std::endl;
}
#include "Serializer.hpp"
#include "data.hpp"

int main()
{
	Serializer ser;
	{
		Data ths;
		ths.i = 73;
		std::cout << "Original: " << ths.i << std::endl;
		uintptr_t res = ser.serialize(&ths);
		std::cout << "Serialize: " << res << std::endl;
		Data* tht = ser.deserialize(res);
		std::cout << "Deserialize: " << tht->i << std::endl;
	}
	std::cout << std::endl;
	{
		Data* lol = new Data;
		lol->i = 42;
		std::cout << "Original: " << lol->i << std::endl;
		uintptr_t res = ser.serialize(lol);
		std::cout << "Serialize: " << res << std::endl;
		Data* fin = ser.deserialize(res);
		std::cout << "Deserialize: " << fin->i << std::endl;
		delete lol;
	}
	std::cout << std::endl;
	{
		Data ths;
		ths.i = 73;
		ths.str = "The ultimate number!";
		std::cout << "Original: " << ths.i << ", " << ths.str << std::endl;
		uintptr_t res = ser.serialize(&ths);
		std::cout << "Serialize: " << res << std::endl;
		Data* tht = ser.deserialize(res);
		std::cout << "Deserialize: " << tht->i << ", " << tht->str << std::endl;
	}
	return (0);
}
#include "Serializer.hpp"
#include "data.hpp"

int main()
{
	
	{
		Data ths;
		ths.i = 73;
		std::cout << "Original: " << ths.i << std::endl;
		uintptr_t res = Serializer::serialize(&ths);
		std::cout << "Serialize: " << res << std::endl;
		Data* tht = Serializer::deserialize(res);
		std::cout << "Deserialize: " << tht->i << std::endl;
	}
	std::cout << std::endl;
	{
		Data* lol = new Data;
		lol->i = 42;
		std::cout << "Original: " << lol->i << std::endl;
		uintptr_t res = Serializer::serialize(lol);
		std::cout << "Serialize: " << res << std::endl;
		Data* fin = Serializer::deserialize(res);
		std::cout << "Deserialize: " << fin->i << std::endl;
		delete lol;
	}
	std::cout << std::endl;
	{
		Data ths;
		ths.i = 73;
		ths.str = "The ultimate number!";
		std::cout << "Original: " << ths.i << ", " << ths.str << std::endl;
		uintptr_t res = Serializer::serialize(&ths);
		std::cout << "Serialize: " << res << std::endl;
		Data* tht = Serializer::deserialize(res);
		std::cout << "Deserialize: " << tht->i << ", " << tht->str << std::endl;
	}
	return (0);
}
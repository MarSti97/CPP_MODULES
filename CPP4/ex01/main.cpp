#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;
		j->makeSound();
		i->makeSound();
		std::cout << std::endl;
		j->haveIdea("Play with something!");
		j->haveIdea("Bark at nothing for no reason!");
		j->haveIdea("Chase a cat!");
		j->thinking();
		std::cout << std::endl;
		delete j;
		delete i;
	}
	{
		std::cout << "\n----------- Animal Array -----------" << std::endl;
		int size = 6;
		const Animal* arr[size];
		for (int i = 0; i < size; i++){
			if (i < (size / 2))
				arr[i] = new Dog();
			else
				arr[i] = new Cat();
		}
		std::cout << std::endl;
		for (int j = 0; j < size; j++)
			arr[j]->makeSound();

		// std::cout << std::endl;
		// for (int k = 0; k < size; k++)
		// 	arr[k]->haveIdea("POO");

		// std::cout << std::endl;
		// for (int p = 0; p < size; p++)
		// 	arr[p]->thinking();

		std::cout << std::endl;
		for (int f = 0; f < size; f++)
			delete arr[f];
	}
	std::cout << "\n----------- Deep Copy Tests -----------" << std::endl;
	Cat kitty;
	kitty.haveIdea("Sleeeeeeep.....");
	std::cout << std::endl;
	Cat copy = kitty;
	kitty.haveIdea("Trying to think of a new idea!");
	copy.thinking();
	copy.haveIdea("GIVE ME FOOD HUMAN!");
	std::cout << std::endl;
	kitty.thinking();
	std::cout << std::endl;
	copy.thinking();
	std::cout << std::endl;
	return 0;
}
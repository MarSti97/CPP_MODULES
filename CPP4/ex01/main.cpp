#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	j->makeSound();
	i->makeSound();
	std::cout << std::endl;
	j->haveIdea("Play with something!");
	j->thinking();
	delete j;
	delete i;
	return 0;
}
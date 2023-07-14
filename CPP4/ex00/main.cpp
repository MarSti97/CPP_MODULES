#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "Wrong tests\n" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();
	const WrongCat * cat = new WrongCat();
	std::cout << std::endl;
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound();
	meta2->makeSound();
	cat->makeSound();
	
	std::cout << std::endl;
	delete meta2;
	delete i2;
	delete cat;
	return 0;
}
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << "\nMy tests" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* Rambo = new Character("Rambo");
		ICharacter* Batman = new Character("Batman");
		Rambo->use(0, *Batman);
		AMateria* tmp;
		tmp = src->createMateria("ice");
		Rambo->equip(tmp);
		tmp = src->createMateria("cure");
		Rambo->equip(tmp);
		tmp = src->createMateria("ice");
		Rambo->equip(tmp);
		tmp = src->createMateria("cure");
		Rambo->equip(tmp);
		tmp = src->createMateria("ice");
		Rambo->equip(tmp);
		delete tmp;
		Rambo->use(0, *Batman);
		Rambo->unequip(0);
		Rambo->unequip(1);
		Rambo->unequip(1);
		Rambo->use(0, *Batman);
		std::cout << "\nDeep copy tests" << std::endl;
		IMateriaSource* copy = new MateriaSource();
		copy = src;
		copy->learnMateria(new Cure());
		copy->learnMateria(new Cure());
		copy->learnMateria(new Ice());
		ICharacter* RamClone = new Character("Random");
		RamClone = Rambo;
		tmp = copy->createMateria("cure");
		RamClone->equip(tmp);
		tmp = copy->createMateria("ice");
		RamClone->equip(tmp);
		RamClone->use(0, *Rambo);
		RamClone->use(1, *Rambo);
		RamClone->use(2, *Rambo);
		RamClone->use(3, *Rambo);
		std::cout << "\nOriginal Rambo should be unchanged" << std::endl;
		Rambo->use(0, *RamClone);
		delete Rambo;
		delete Batman;
		delete src;
		delete RamClone;
		delete copy;
		clearDropped();
	}
	return 0;
}
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
		Rambo->equip(src->createMateria("ice"));
		Rambo->equip(src->createMateria("cure"));
		Rambo->equip(src->createMateria("ice"));
		Rambo->equip(src->createMateria("cure"));
		Rambo->equip(src->createMateria("ice"));
		Rambo->use(0, *Batman);
		Rambo->unequip(0);
		Rambo->unequip(1);
		Rambo->unequip(1);
		delete Rambo;
		delete Batman;
		std::cout << "HERE" << std::endl;
		delete src;
		clearDropped();
	}
	return 0;
}
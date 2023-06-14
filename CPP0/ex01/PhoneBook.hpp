#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <string>

class Contact
{
	public:
		std::string name;
		unsigned long nbr;
};

class PhoneBook
{
	private : 
		Contact contacts[8];
	public :
		Contact ADD(std::string name, unsigned long nbr);
};

// PhoneBook::ADD(std::string name, unsigned long nbr);

#endif
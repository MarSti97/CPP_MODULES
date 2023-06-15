#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private : 
		Contact contacts[8];
	public :
		// PhoneBook();
		Contact ADD();
};

// Contact PhoneBook::ADD(void);

#endif
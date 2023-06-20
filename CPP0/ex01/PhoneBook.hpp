#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private : 
		Contact contacts[8];
	public :
		// PhoneBook();
		void ADD(int i);
		void SEARCH();
};

// Contact PhoneBook::ADD(void);

#endif
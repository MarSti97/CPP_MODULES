#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private : 
		Contact contacts[8];
	public :
		void ADD(int i);
		void SEARCH();
};

#endif
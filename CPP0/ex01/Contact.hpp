#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <stdlib.h>
#include <string>

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string nbr;
		std::string darkest_secret;
		int index;
		int flag;

		Contact();
};

#endif
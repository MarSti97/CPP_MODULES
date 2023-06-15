#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	std::string input;
	std::cout << "Welcome to the Phonebook" << std::endl << "Use the keywords ADD, SEARCH or EXIT to navigate the Phonebook" << std::endl;
	PhoneBook NewBook;
	int i = 0;
	while(1)
	{
		std::cout << "> ";
		std::cin >> input;
		if (input == "ADD")
		{
			NewBook.contacts[i] = NewBook.ADD();
			if (i != 7)
				i++;
		}
		else if (input == "EXIT")
			exit(0);
		std::cout << std::endl;
	}
}
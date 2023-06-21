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
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			NewBook.ADD(i);
			if (i == 7)
				i = -1;
			i++;
		}
		else if (input == "SEARCH")
			NewBook.SEARCH();
		else if (input == "EXIT")
			exit(0);
		// std::cout << std::endl;
	}
}
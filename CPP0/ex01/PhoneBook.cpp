#include "PhoneBook.hpp"

Contact PhoneBook::ADD()
{
	Contact NewContact;

	std::cout << "Enter Name: ";
	std::cin >> NewContact.name;
	// std::cout << std::endl;
	// NewContact.name = name;
	std::cout << "Enter Number: ";
	std::cin >> NewContact.nbr;
	std::cout << "Contact Added";
	// NewContact.nbr = nbr;
	return NewContact;
}

// PhoneBook::PhoneBook();
// {
// 	PhoneBook.contacts = NULL;
// }

// Contact	PhoneBook::SEARCH(std::string name, unsigned long nbr)
// {
// 	//search by name or number

// }

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
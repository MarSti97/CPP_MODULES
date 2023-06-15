#include "PhoneBook.hpp"
#include "Contact.hpp"

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

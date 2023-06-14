#include "PhoneBook.hpp"

Contact PhoneBook::ADD(std::string name, unsigned long nbr)
{
	Contact NewContact;

	NewContact.name = name;
	NewContact.nbr = nbr;
}

Contact	PhoneBook::SEARCH(std::string name, unsigned long nbr)
{
	//search by name or number

}

int main()
{
	std::string input;
	std::cout << "Welcome to the Phonebook" << std::endl << "Use the keywords ADD, SEARCH or EXIT to navigate the Phonebook" << std::endl;
	while(1)
	{
		std::cout << "> ";
		std::cin >> input;
		if (input == "ADD")
			
	}
}
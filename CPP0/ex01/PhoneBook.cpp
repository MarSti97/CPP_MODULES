#include "PhoneBook.hpp"
#include "Contact.hpp"

void	PhoneBook::ADD(int i)
{
	contacts[i].index = i;
	contacts[i].flag = 1;
	std::cout << "Enter First Name: ";
	std::cin >> contacts[i].first_name;
	std::cout << "Enter Last Name: ";
	std::cin >> contacts[i].last_name;
	std::cout << "Enter Nickname: ";
	std::cin >> contacts[i].nickname;
	std::cout << "Enter Number: ";
	std::cin >> contacts[i].nbr;
	std::cout << "Enter Darkest Secret: ";
	std::cin >> contacts[i].darkest_secret;
	std::cout << "Contact Added";
}

void	PhoneBook::SEARCH()
{
	std::cout << "Contacts\n -------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10) << "Name" << "|" << std::setw(10) << "LastName" << "|" << std::setw(10) << "Secret"  << "|" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		if (contacts[i].flag == 1)
			std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << contacts[i].first_name << "|" << std::setw(10) << contacts[i].last_name << "|" << std::setw(10) << contacts[i].darkest_secret << "|" << std::endl;
		else
			std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << " " << "|" << std::setw(10) << " " << "|" << std::setw(10) << " "  << "|" << std::endl;
		std::cout << " -------------------------------------------" << std::endl;
	}
	

}

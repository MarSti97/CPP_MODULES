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
	// while (contacts[i].nbr.find_first_not_of("0123456789") == -1)

	std::cout << "Enter Darkest Secret: ";
	std::cin >> contacts[i].darkest_secret;
	std::cout << "Contact Added";
}

void	PhoneBook::SEARCH()
{
	int	chosen;

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
	std::cout << "Choose which contact info you would like to see based on its index (0 - 7)\nIndex: ";
	std::cin >> chosen;
	std::cout << "First Name: " << contacts[chosen].first_name << std::endl;
	std::cout << "Last Name: " << contacts[chosen].last_name << std::endl;
	std::cout << "Nickame: " << contacts[chosen].nickname << std::endl;
	std::cout << "Number: " << contacts[chosen].nbr << std::endl;
	std::cout << "Darkest Secret: " << contacts[chosen].darkest_secret << std::endl;
}

#include "PhoneBook.hpp"
#include "Contact.hpp"

bool blank(std::string str)
{
	int i = -1;

	while (str[++i])
	{
		// printf("HERE\n");
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}

std::string	get_info(std::string msg)
{
	std::string data;
	std::cout << msg << std::endl;
	while(true)
	{
		std::getline(std::cin, data);
		if (data.find_first_not_of(" \n\t\0"))
			std::cout << "Invalid input, try again\n" << msg;
		// if (blank(data))
		else
			break ;
	}
	return (data);
}

void	PhoneBook::ADD(int i)
{
	contacts[i].index = i;
	contacts[i].flag = 1;
	contacts[i].first_name = get_info("Enter First Name: ");
	// std::cout << "Enter First Name: ";
	// std::cin >> contacts[i].first_name;
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

std::string	trnc(std::string str)
{
	std::string new_str;

	if (str.length() > 9)
	{
		new_str = str.substr(0, 9);
		new_str += ".";
		return (new_str);
	}
	return (str);
}

void	PhoneBook::SEARCH()
{
	int	chosen;

	std::cout << "Contacts\n -------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10) << "Name" << "|" << std::setw(10) << "LastName" << "|" << std::setw(10) << "Nickname"  << "|" << std::endl;
	std::cout << " -------------------------------------------" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		if (contacts[i].flag == 1)
			std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << trnc(contacts[i].first_name) << "|" << std::setw(10) << trnc(contacts[i].last_name) << "|" << std::setw(10) << trnc(contacts[i].nickname) << "|" << std::endl;
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

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	get_info(std::string msg)
{
	std::string data;
	std::cout << msg;
	std::getline(std::cin, data);
	while(data.find_first_not_of(" \n\t") == std::string::npos)
	{
		std::cout << "Invalid input, try again\n" << msg;
		std::getline(std::cin, data);
	}
	return (data);
}

void	PhoneBook::ADD(int i)
{
	contacts[i].index = i;
	contacts[i].flag = 1;
	contacts[i].first_name = get_info("Enter First Name: ");
	contacts[i].last_name = get_info("Enter Last Name: ");
	contacts[i].nickname = get_info("Enter Nickname: ");
	std::cout << "Enter Number: ";
	std::getline(std::cin, contacts[i].nbr);
	while (contacts[i].nbr.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Invalid input, try again\n" << "Enter Number: ";
		std::getline(std::cin, contacts[i].nbr);
	}
	contacts[i].darkest_secret = get_info("Enter Darkest Secret: ");
	std::cout << "Contact Added" << std::endl;
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
	std::string	chosen;
	int index;

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
	std::getline(std::cin, chosen); // need to parse and atoi so can use as index
	while (chosen.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Invalid input, try again\n" << "Index: ";
		std::getline(std::cin, chosen);
	}
	std::istringstream iss(chosen);
	iss >> index;
	if (index < 0 || index > 7)
	{
		std::cout << "Index doesn't exist" << std::endl;
		return ;
	}
	std::cout << "First Name: " << contacts[index].first_name << std::endl;
	std::cout << "Last Name: " << contacts[index].last_name << std::endl;
	std::cout << "Nickame: " << contacts[index].nickname << std::endl;
	std::cout << "Number: " << contacts[index].nbr << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].darkest_secret << std::endl;
}

#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	typedef std::pair<std::string, void(Harl::*)(void)> data;
	std::list<data> pairList;

	pairList.push_back(data("DEBUG", &Harl::debug));
	pairList.push_back(data("INFO", &Harl::info));
	pairList.push_back(data("WARNING", &Harl::warning));
	pairList.push_back(data("ERROR", &Harl::error));

	std::list<data>::iterator it;
	for (it = pairList.begin(); it != pairList.end(); ++it)
	{
		if (it->first == level)
		{
			(this->*(it->second))();
			break ;
		}
	}
}

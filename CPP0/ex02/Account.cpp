#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

Account::Account(int initial_deposit)
{
	for (acc_begin )

	_amount = ;
}

void Account::_displayTimestamp(void)
{
	time_t time;
	tm *full_time;

	std::time(&time);
	full_time = std::localtime(&time);
	std::cout << "[" << (1900 + full_time->tm_year);
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_mon; // giving weird month...
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_sec << "]" << std::endl;
}
#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t time;
	tm *full_time;

	std::time(&time);
	full_time = std::localtime(&time);
	std::cout << "[" << (1900 + full_time->tm_year);
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_sec << "]";
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int	Account::checkAmount(void) const
{
	return(_amount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return(_totalNbWithdrawals);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts;	
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawels:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

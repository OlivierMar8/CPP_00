//Account.cpp	CPP00 / ex02

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void) {

	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout  << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created" << std::endl;

	return;
}

Account::Account( int initial_deposit) : _amount(initial_deposit) {

	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount+= initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout  << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created" << std::endl;

	return;
}

Account::~Account( void) {

	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;

	return;
}

int	Account::getNbAccounts( void ) {

	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {

	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {

	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {

	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {

	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount ;
	std::cout << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" ;
	std::cout << Account::_totalNbWithdrawals << std::endl;
}
	   
void Account::makeDeposit( int deposit ) {

	int		p_amount;

	p_amount = this->_amount;
	if (deposit > 0)
	{
		this->_amount += deposit;
		Account::_totalAmount += deposit;
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
	}
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << p_amount << ";deposit:" << deposit;
	std::cout << ":amount:" << this->_amount << ";nb_deposits:";
	std::cout << this->_nbDeposits << std::endl;
	return;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	int		p_amount;
	bool	refused;

	p_amount = this->_amount;
	if (withdrawal > this->_amount)
		refused = true;
	else
	{
		refused = false;
		if (withdrawal > 0)
		{
			this->_amount -= withdrawal;
			Account::_totalAmount -= withdrawal;
			this->_nbWithdrawals++;
			Account::_totalNbWithdrawals++;
		}
	}
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << p_amount << ";withdrawal:";
	if (refused)
		std::cout << "refused:";
	else
	{
		std::cout  << withdrawal << ":amount:" << this->_amount;
		std::cout  << ";nb_withdrawals:"<< this->_nbWithdrawals;
	}
	std::cout << std::endl;
	return (refused);
}

int		Account::checkAmount( void ) const {

	return (this->_amount);
}

void	Account::displayStatus ( void ) const {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << _amount << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;

	return;
}

void Account::_displayTimestamp( void ) {

	time_t now;

	time(&now);
	tm utc_tm = *localtime(&now);
	std::cout << std::setfill('0') << "[" << (utc_tm.tm_year + 1900);
	std::cout << std::setw(2) <<utc_tm.tm_mon + 1;
	std::cout << std::setw(2) <<utc_tm.tm_mday <<"_";	
	std::cout << std::setw(2) <<utc_tm.tm_hour;
	std::cout << std::setw(2) <<utc_tm.tm_min;
	std::cout << std::setw(2) <<utc_tm.tm_sec << "] ";
	return;
}


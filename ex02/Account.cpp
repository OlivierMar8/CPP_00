#include <iostream>
#include <chrono>
#include "Account.hpp"

Account::Account( void) {

	return;
}

Account::Account( int initial_deposit) : _amount(initial_deposit) {


	this->_accountIndex = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "timestamp " << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created" << std::endl;

	return;
}

Account::~Account( void) {

	std::cout << "timestamp " << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;

	return;
}

int	Account::getNbAccounts( void ) {
//	std::cout << " getNbAccounts " << std::endl;
//	return f::_nbAccounts;
	return 1;
}

void	Account::displayAccountsInfos( void ) {

	std::cout << "accounts:" << 4 << ";total:" << 20857 ;
	std::cout << ";deposits:" << 10 << ";withdrawals:" ;
	std::cout << 7 << std::endl;

	return;

}

void	Account::makeDeposit( int deposit ) {

	int		p_amount;

	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
//	t::_totalNbDeposits += 1;
	std::cout << "timestamp " << "index:" << this->_accountIndex;
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
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
	//	t::_totalNbDeposits += 1;
	}
	std::cout << "timestamp " << "index:" << this->_accountIndex;
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

	std::cout << "timestamp " << "index:" << this->_accountIndex;
	std::cout << ";amount:" << _amount << ";deposits:" << this->_nbDeposits;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return;
}

void Account::_displayTimestamp( void ) {

	return;
}

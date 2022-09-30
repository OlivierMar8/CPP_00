#include <iostream>
#include "Account.hpp"

Account::Account( int initial_deposit) : _amount(initial_deposit) {

	this->_accountIndex = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "timestamp " << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created" << std::endl;

	return;
}

Account::~Account( void) {

	return;
}
/*
int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}
*/
void	Account::makeDeposit( int deposit ) {

	int		p_amount;

	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
//	t::_totalNbDeposits += 1;
	std::cout << "timestamp " << "index:" << this->_nbDeposits << ";";
	std::cout << "p_amount:" << p_amount << ";deposit:" << deposit;
	std::cout << ":amount:" << this->_amount << ";nb_deposits:";
	std::cout << this->_nbDeposits;
	return;
}


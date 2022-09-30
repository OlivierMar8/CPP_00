#include "Account.hpp"
#include <iostream>
int main (void)
{

	Account	acc(42);
	Account	bbb(30);
	acc.displayStatus();
	bbb.displayStatus();
	acc.makeDeposit(5);
	bbb.makeDeposit(100);
	acc.makeDeposit(3);
	acc.makeWithdrawal(10);
	acc.makeWithdrawal(60);
	bbb.makeWithdrawal(30);
	acc.makeWithdrawal(4);
	std::cout << "total comptes: " << Account::getNbAccounts() << std::endl;
	acc.displayStatus();
	bbb.displayStatus();

	return (1);
}

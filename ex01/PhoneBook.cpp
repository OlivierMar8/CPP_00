#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

	this->count = -1;
	return;
}

PhoneBook::~PhoneBook( void ) {

	return;
}

void	PhoneBook::enterCmd( void ) {

	std::string	cmd;

	cmd = "a";
    std::cout << "My Awesome PhoneBook" << std::endl;
	while (cmd.compare("EXIT") != 0)
	{
		std::cout << "Please enter a command: ADD, SEARCH or EXIT";
		std::cout  << std::endl;
		std::cin >> cmd;
		if (cmd.compare("ADD") == 0)
			this->collectData();
		else if (cmd.compare("SEARCH") == 0)
			this->searchContact();


		std::cout << "Command: " << cmd << std::endl;
	}
}

void	PhoneBook::collectData( void ) {

	std::string data[5];
/*	std::string lm;
	std::string nn;
	std::string pn;
	std::string ds;
*/	
	
	std::cout << "First name: " << std::endl;
	std::cin >> data[0];
	std::cout << "Last name: " << std::endl;
	std::cin >> data[1];
	std::cout << "Nickname: " << std::endl;
	std::cin >> data[2];
	std::cout << "Phone number: " << std::endl;
	std::cin >> data[3];
	std::cout << "Darkest secret: " << std::endl;
	std::cin >> data[4];
	this->addContact( data );
}

void	PhoneBook::addContact( std::string data[5] ) {

	(void)data;
	Contact	c(data[0], data[1], data[2], data[3], data[4]);
	if (this->count == 7 || this->count == -1)
		this->count = 0;
	this->tab[count] = c;
	this->count++;
}

int		PhoneBook::searchContact( void ) const {

	if (this->count < 1)
		std::cout << "No contact in the PhoneBook !"  << std::endl;

	printList();

	return 1;
}

void    PhoneBook::printFormList( std::string s) const {
	
	if (s.size() > 10)
	{
		s = s.insert(9, ".");
		s = s.substr(0, 10);
	}
	else
		std::cout << std::setw(10);
	std::cout << s;
}



void	PhoneBook::printList( void ) const {
	
		std::cout << "*********************************************"  << std::endl;
		std::cout << "*     Index|First Name| Last Name|  Nickname*" << std::endl;
		std::cout << "*********************************************"  << std::endl;
		for (int i = 0; i < this->count; i++)
		{
			std::cout << "*         " << i + 1 << "|";
			printFormList(this->tab[i].getFirstName());
			std::cout  << "|";
			printFormList(this->tab[i].getLastName());
			std::cout  << "|";
			printFormList(this->tab[i].getNickname());
			std::cout << "*" << std::endl;
		}
		std::cout << "*********************************************"  << std::endl;
}




void	PhoneBook::printContact( int i) const {
(void)i;
}


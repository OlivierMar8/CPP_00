//PhoneBook.cpp	CPP00 / ex01

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

	this->_count = -1;
	this->_oldest = -1;
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
		std::cout << "Please enter a command: ADD, SEARCH or EXIT: ";
		std::cout  << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0)
			this->collectData();
		else if (cmd.compare("SEARCH") == 0)
			this->searchContact();
	}
	return;
}

void	PhoneBook::collectData( void ) {

	std::string data[5];
	
std::cout << "First name: ";
while (!(std::getline(std::cin, data[0])) || data[0].size() < 1)
	std::cout << "Field is mandatory. First name: ";
std::cout << "Last name: ";
while (!(std::getline(std::cin, data[1])) || data[1].size() < 1)
	std::cout << "Field is mandatory. Last name: ";
std::cout << "Nickname: ";
while (!(std::getline(std::cin, data[2])) || data[2].size() < 1)
	std::cout << "Field is mandatory. Nickname: ";
std::cout << "Phone number: ";
while (!(std::getline(std::cin, data[3])) || data[3].size() < 1)
	std::cout << "Field is mandatory. Phone Number: ";
std::cout << "Darkest secret: ";
while (!(std::getline(std::cin, data[4])) || data[4].size() < 1)
	std::cout << "Field is mandatory. Darkest secret: ";
this->addContact( data );
}

void	PhoneBook::addContact( std::string data[5] ) {

int	i;

Contact	c(data[0], data[1], data[2], data[3], data[4]);
if (this->_count == -1)
{
	i = 0;
	this->_oldest = 0;
}
else if (this->_count == 7)
{
	i = this->_oldest;
	this->_oldest++;
	if (this->_oldest > 7)
		this->_oldest = 0;
	this->_count--;
}
else
	i = this->_count + 1;
	this->_tab[i] = c;
	this->_count++;
}

void	PhoneBook::searchContact( void ) const {

	int			index;

	if (this->_count < 0)
		std::cout << "No contacts in the PhoneBook !"  << std::endl;
	else
	{
		printList();
		std::cout << "Please enter an index: 1 - " << this->_count + 1 << std::endl;
		while (!(std::cin >> index) || index < 1 || index > this->_count + 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error : bad index ! Enter an index: " << std::endl; 
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		printContact(index);
		std::cout << "*********************************************"  << std::endl;
	}
	return;
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
	return;
}

void	PhoneBook::printList( void ) const {
	
		std::cout << "*********************************************"  << std::endl;
		std::cout << "*     Index|First Name| Last Name|  Nickname*" << std::endl;
		std::cout << "*********************************************"  << std::endl;
		for (int i = 0; i <= this->_count; i++)
		{
			std::cout << "*         " << i + 1 << "|";
			printFormList(this->_tab[i].getFirstName());
			std::cout  << "|";
			printFormList(this->_tab[i].getLastName());
			std::cout  << "|";
			printFormList(this->_tab[i].getNickname());
			std::cout << "*" << std::endl;
		}
		std::cout << "*********************************************"  << std::endl;
		return;
}

void	PhoneBook::printContact( int i) const {

	i--;
	std::cout << "First name: " << "\t";
	std::cout <<this->_tab[i].getFirstName();
	std::cout  << std::endl;
	std::cout << "Last name: " << "\t";
	std::cout <<this->_tab[i].getLastName();
	std::cout  << std::endl;
	std::cout << "Nickname: " << "\t";
	std::cout <<this->_tab[i].getNickname();
	std::cout  << std::endl;
	std::cout << "Phone number: " << "\t";
	std::cout <<this->_tab[i].getPhoneNumber();
	std::cout  << std::endl;
	std::cout << "Darkest secret: ";
	std::cout <<this->_tab[i].getDarkestSecret();
	std::cout  << std::endl;
	return;
}


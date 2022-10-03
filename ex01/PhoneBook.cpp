#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

	this->count = -1;
	this->oldest = -1;
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
	std::getline(std::cin, data[0]);
	std::cout << "Last name: ";
	std::getline(std::cin, data[1]);
	std::cout << "Nickname: ";
	std::getline(std::cin, data[2]);
	std::cout << "Phone number: ";
	std::getline(std::cin, data[3]);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, data[4]);
	this->addContact( data );
}

void	PhoneBook::addContact( std::string data[5] ) {

	int	i;

	Contact	c(data[0], data[1], data[2], data[3], data[4]);
	if (this->count == -1)
	{
		i = 0;
		this->oldest = 0;
	}
	else if (this->count == 7)
	{
		i = this->oldest;
		this->oldest++;
		if (this->oldest > 7)
			this->oldest = 0;
		this->count--;
	}
	else
		i = this->count + 1;
	this->tab[i] = c;
	this->count++;
}

void	PhoneBook::searchContact( void ) const {

	int			index;

	if (this->count < 0)
		std::cout << "No contacts in the PhoneBook !"  << std::endl;
	else
	{
		printList();
		std::cout << "Please enter an index: 1 - " << this->count + 1 << std::endl;
		while (!(std::cin >> index) || index < 1 || index > this->count + 1)
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
		for (int i = 0; i <= this->count; i++)
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
		return;
}

void	PhoneBook::printContact( int i) const {

	i--;
	std::cout << "First name: " << "\t";
	std::cout <<this->tab[i].getFirstName();
	std::cout  << std::endl;
	std::cout << "Last name: " << "\t";
	std::cout <<this->tab[i].getLastName();
	std::cout  << std::endl;
	std::cout << "Nickname: " << "\t";
	std::cout <<this->tab[i].getNickname();
	std::cout  << std::endl;
	std::cout << "Phone number: " << "\t";
	std::cout <<this->tab[i].getPhoneNumber();
	std::cout  << std::endl;
	std::cout << "Darkest secret: ";
	std::cout <<this->tab[i].getDarkestSecret();
	std::cout  << std::endl;
	return;
}


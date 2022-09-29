#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main( void ) {

	std::string d[5];
	Contact	my_c( "Jean", "Dupont", "Didi", "456 33 22", "lol");
	PhoneBook	book;
	d[0]="Paul";d[1]="Dupont";d[2]="ldu";d[3]="123456789abc";d[4]="lol";
	book.addContact(d);
	d[0]="Jean";d[1]="DeMontmollin";d[2]="jmo";d[3]="98765412";d[4]="test";
	book.addContact(d);

	book.enterCmd();
	
/*	std::cout << "My Awesome PhoneBook" << std::endl;
	std::cout << "Please enter a command: ADD, SEARCH or EXIT" << std::endl;
	std::cin >> cmd;
	std::cout << "Command: " << cmd << std::endl;
*/

	std::cout << "First name: " << my_c.getFirstName() << std::endl;
	std::cout << "Phone: " << my_c.getPhoneNumber() << std::endl;

	return (0);
}


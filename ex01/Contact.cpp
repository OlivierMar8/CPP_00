// Contact.cpp	CPP00 / ex01
 
#include <iostream>
#include "Contact.hpp"

Contact::Contact( void ) {

	return;
}

Contact::Contact( std::string fn, std::string ln, std::string nn, \
   			      std::string pn, std::string ds ) : _firstName(fn),  \
				  _lastName(ln), _nickname(nn), _phoneNumber(pn), \
	   			  _darkestSecret(ds) {

	return;
}

Contact::~Contact( void ) {

	return;
}

std::string	Contact::getFirstName( void ) const {

	return this->_firstName;
}

std::string	Contact::getLastName( void ) const {

	return this->_lastName;
}

std::string	Contact::getNickname( void ) const {

	return this->_nickname;
}

std::string	Contact::getPhoneNumber( void ) const {

	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret( void ) const {

	return this->_darkestSecret;
}

void	Contact::setFirstName( std::string fn ) {

	this->_firstName = fn;
}

void	Contact::setLastName( std::string ln ) {

	this->_lastName = ln;
}

void	Contact::setNickame( std::string nn ) {

	this->_nickname = nn;
}

void	Contact::setPhoneNumber( std::string pn ) {

	this->_phoneNumber = pn;
}

void	Contact::setDarkestSecret( std::string ds ) {

	this->_darkestSecret = ds;
}


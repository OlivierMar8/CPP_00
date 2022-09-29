#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main( void ) {

	std::string d[5];
	PhoneBook	book;
	d[0]="Paul";d[1]="Dupont";d[2]="ldu";d[3]="123456789abc";d[4]="lol";
	book.addContact(d);
	d[0]="Jean";d[1]="DeMontmollin";d[2]="jmo";d[3]="98765412";d[4]="test";
	book.addContact(d);
	d[0]="Toto";d[1]="Dulac";d[2]="lac";d[3]="000123456789abc";d[4]="tri";
	book.addContact(d);
	d[0]="Rene";d[1]="Berger";d[2]="rbe";d[3]="AA789abc";d[4]="sel";
	book.addContact(d);
	d[0]="Maria";d[1]="Lini";d[2]="mli";d[3]="994589";d[4]="the";
	book.addContact(d);
	d[0]="Susi";d[1]="Chen";d[2]="sche";d[3]="44 55 88 77";d[4]="secret";
	book.addContact(d);
	d[0]="Matt";d[1]="Dirk";d[2]="didi";d[3]="4477220202c";d[4]="cola";
	book.addContact(d);
	d[0]="captain";d[1]="Wag";d[2]="42";d[3]="5252525abc";d[4]="43";
	book.addContact(d);
	d[0]="Romain";d[1]="Savoir";d[2]="sav";d[3]="963852";d[4]="cpp";
	book.addContact(d);

	book.enterCmd();
	
	return (0);
}


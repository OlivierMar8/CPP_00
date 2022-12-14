//PhoneBook.hpp	CPP00 / ex01

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook {

	public:

		PhoneBook( void );
		~PhoneBook( void );
		int		getCount( void ) const;
		void	setCount( int c );	
		int		getOldest( void ) const;
		void	setOldest( int c );	

		void	enterCmd( void );
		void	collectData( void );
		void	addContact( std::string data[5]);
		void	searchContact( void ) const;
		void	printFormList( std::string s) const;
		void	printList( void ) const;
		void	printContact( int i ) const;


	private:

		Contact	_tab[8];
		int		_count;
		int		_oldest;

};

#endif

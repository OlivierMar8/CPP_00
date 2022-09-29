#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>


class Contact {

	public:
	
		Contact( void );
		Contact( std::string fn, std::string ln, std::string nn, \
                 std::string pn, std::string ds);
		~Contact( void );
		void	printContact( int index, Contact p);
		
		std::string	getFirstName( void ) const;
		std::string	getLastName( void ) const;
		std::string	getNickname( void ) const;
		std::string	getPhoneNumber( void ) const;
		std::string	getDarkestSecret( void ) const;


		void	setFirstName( std::string fn );	
		void	setLastName( std::string ln );	
		void	setNickame( std::string nn );	
		void	setPhoneNumber( std::string pn );	
		void	setDarkestSecret( std::string ds );

	private:

		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

};

#endif

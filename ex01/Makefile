SRCS		= Contact.cpp PhoneBook.cpp main.cpp	

OBJS		= $(SRCS:.cpp=.o)

NAME		= phonebook

CC			= c++

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra -std=c++98 


all:		${NAME}

%.o: %.cpp
			$(CC) $(CFLAGS) -c $< 

${NAME}:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			

.PHONY:		all clean fclean  re

clean:	
			$(RM) $(OBJS)


fclean:		clean
			$(RM) $(NAME)

re:			fclean all

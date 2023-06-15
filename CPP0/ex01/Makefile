SRC = PhoneBook.cpp main.cpp Contact.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
NAME = Phonebook
INC = PhoneBook.hpp Contact.hpp


all : $(NAME)

$(NAME) : $(INC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo DONE

run : 
	./$(NAME)

clean : 
	@rm $(NAME)

re : clean all
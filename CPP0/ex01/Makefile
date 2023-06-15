SRC = PhoneBook.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
NAME = Phonebook


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo DONE

run : 
	./$(NAME)

clean : 
	@rm $(NAME)

re : clean all
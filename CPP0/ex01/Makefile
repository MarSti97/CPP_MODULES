SRC = PhoneBook.cpp main.cpp Contact.cpp
OBJ = $(SRC:%.cpp=%.o)
FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
NAME = Phonebook
INC = PhoneBook.hpp Contact.hpp

COLOUR =\033[0;32m
END =\033[0m

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(COLOUR) DONE $(END)"


%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

run : 
	@./$(NAME)

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
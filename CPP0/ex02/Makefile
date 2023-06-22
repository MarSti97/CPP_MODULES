SRC = Account.cpp tests.cpp
OBJ = $(SRC:%.cpp=%.o)
FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
NAME = Account
INC = Account.hpp

COLOUR =\033[0;32m
END =\033[0m

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(COLOUR) DONE $(END)"

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

run : 
	@./$(NAME) > result.log

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
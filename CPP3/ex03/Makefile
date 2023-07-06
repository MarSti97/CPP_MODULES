SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ = $(SRC:%.cpp=%.o)
FLAGS = -Wall -Werror -Wextra -Wshadow -std=c++98
CC = c++
NAME = battle
INC = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

COLOUR =\033[0;32m
END =\033[0m

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(COLOUR) DONE $(END)"


%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

run : all
	@./$(NAME)

valgrind : all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
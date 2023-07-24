SRC = main.cpp
BIN = bin
OBJ = $(SRC:%.cpp=${BIN}/%.o)
FLAGS = -Wall -Werror -Wextra -Wshadow -g -std=c++98
CC = c++
NAME = UltimateStack
INC = MutantStack.hpp 

COLOUR =\033[0;32m
END =\033[0m

all : $(NAME)

$(NAME) : $(BIN) $(OBJ) $(INC)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(COLOUR) DONE $(END)"

$(BIN) :
	@mkdir -p $(BIN)

$(BIN)/%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

run : all
	@./$(NAME)

valgrind : all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean : 
	@rm -rf $(OBJ) $(BIN)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
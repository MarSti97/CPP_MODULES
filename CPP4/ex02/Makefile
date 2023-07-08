SRC = main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
BIN = bin
OBJ = $(SRC:%.cpp=${BIN}/%.o)
FLAGS = -Wall -Werror -Wextra -Wshadow -std=c++98
CC = c++
NAME = Zoo
INC = AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp

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
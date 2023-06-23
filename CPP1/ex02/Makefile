SRC = main.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
NAME = brain

COLOUR =\033[0;32m
END =\033[0m

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "$(COLOUR) DONE $(END)"

run :
	./$(NAME)

clean : 
	@rm $(NAME)

re : clean all

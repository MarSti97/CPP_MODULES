SRC = megaphone.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
NAME = megaphone

COLOUR =\033[0;32m
END =\033[0m

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "$(COLOUR) DONE $(END)"

run :
	./$(NAME);
	./$(NAME) something to write in caps;
	./$(NAME) MixTure Of CapS and 2455421 ",.,;-=-=+";

clean : 
	@rm $(NAME)

re : clean all

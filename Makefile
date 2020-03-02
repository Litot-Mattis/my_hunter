##
## EPITECH PROJECT, 2018
## Makefile_my_hunter
## File description:
## makefile
##

CC	=	gcc -I include

SRC	=	src/my_hunter.c		\
		src/my_create.c		\
		src/my_putstr.c 	\
		src/main.c		\
		src/menu.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -l csfml-graphics -l csfml-audio -l csfml-system -lcsfml-window -l m

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean re

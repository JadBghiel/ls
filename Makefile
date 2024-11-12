##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile with the folling rules: re, clean and fclean rules
##

CC = gcc

SRC = src/my_ls.c \
	src/main.c \
	src/my_putchar.c \
	src/my_putstr.c \
	src/my_strlen.c \
	src/my_strcmp.c \
	src/handle_flags.c \
	src/a_flag.c \
	src/d_flag.c \
	src/r_flag.c \
	src/t_flag.c \
	src/r_uppercase_flag.c

OBJ = $(SRC:.c=.o)

NAME = my_ls

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

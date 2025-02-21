##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile with the folling rules: re, clean and fclean rules
##

CC = gcc

SRC = src/my_ls.c \
	src/main.c \
	src/lib/my_putchar.c \
	src/lib/my_putstr.c \
	src/lib/my_strlen.c \
	src/lib/my_strcmp.c \
	src/handle_flags.c \
	src/flags/a_flag.c \
	src/flags/d_flag.c \
	src/flags/r_flag.c \
	src/flags/t_flag.c \
	src/handle_entries.c \
	src/flags/r_uppercase_flag.c

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

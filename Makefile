##
## EPITECH PROJECT, 2025
## makefils
## File description:
## f
##

SRC =	src/pars/parsing.c \
		src/pars/init.c \
		src/pars/add.c \
		src/del.c \
		src/algo/dfs.c \
		src/algo/robot.c \

MAIN =	src/main.c \

OBJ = $(SRC:.c=.o) $(MAIN:.c=.o)

CC = gcc

NAME = amazed

INCLUDE = -I./include/

LIB = -L./lib/ -lmy -llist

CFLAGS = -Wall -Wextra -Werror -g3

all: buildlib $(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIB) $(CFLAGS)

clean:
		@rm -fr $(OBJ)
		@rm -fr *.gcno
		@rm -fr *.gcda
		@rm -fr $(TOBJ)

fclean: clean fcleanlib
		@rm -rf $(NAME) $(TNAME)

re: fclean all

buildlib:
		@make -C ./lib

cleanlib:
		@make clean -C ./lib

fcleanlib:
		@make fclean -C ./lib

relib:
		@make re -C ./lib

TSRC = tests/tests.c \

TNAME = unit_tests

TLIB = $(LIB) -lcriterion --coverage

unit_tests: clean
		@$(CC) -o $(TNAME) $(TSRC) $(SRC) $(INCLUDE) $(TLIB)
u: unit_tests

tests_run: unit_tests
		@./unit_tests && gcovr
t: tests_run

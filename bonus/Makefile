##
## EPITECH PROJECT, 2024
## makefile
## File description:
## is a makefile
##

NAME    =       amazed

SRCS    =	src/amazed_graph.c \
			src/handle_events.c \
			src/create_elements.c \
			src/draw_elements.c \
			src/singletons.c \

OBJ	=	$(MAIN:.c=.o) $(SRCS:.c=.o)

CFLAGS	=	 -Wextra -Wall -I./includes \
			-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CC	=	gcc

all	:	$(OBJ)
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
		mv amazed ../amazed

clean	:
			rm -rf $(OBJ)
			rm ../amazed

fclean	:	clean
			rm -rf $(NAME)

re	:	fclean all

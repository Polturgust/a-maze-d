##
## EPITECH PROJECT, 2024
## makefile
## File description:
## is a makefile
##

NAME    =       amazed_bonus

SRCS    =	src/amazed_graph.c \
			src/handle_events.c \
			src/create_elements.c \
			src/draw_elements.c \
			src/singletons.c \
\
			src/resources/my_stwa.c \

OBJ	=	$(MAIN:.c=.o) $(SRCS:.c=.o)

CFLAGS	=	 -Wextra -Wall -I./includes \
			-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CC	=	gcc

all	:	$(OBJ)
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
		mv amazed_bonus ../amazed_bonus

clean	:
			rm -rf $(OBJ)
			rm ../amazed_bonus

fclean	:	clean
			rm -rf $(NAME)

re	:	fclean all


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
			src/move_bots.c \
			src/calculate_bot_pos.c \
			src/fill_elements.c \
			src/destroy_all.c \
			src/fill_files.c \
\
			src/resources/my_stwa.c \
			src/resources/my_itoa.c \

OBJ	=	$(MAIN:.c=.o) $(SRCS:.c=.o)

CFLAGS	=	 -Wextra -Wall -I./includes -lcsfml-graphics \
			-lcsfml-window -lcsfml-system -lcsfml-audio -lm
CC	=	gcc

all	:	$(OBJ)
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
		mv $(NAME) ../$(NAME)

clean	:
			rm -rf $(OBJ)

fclean	:	clean
			rm -rf ../$(NAME)

re	:	fclean all

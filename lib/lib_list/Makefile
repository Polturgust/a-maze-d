##
## EPITECH PROJECT, 2024
## quest
## File description:
## Makefile
##

NAME = liblist.a

SRCS =	src/link_list.c \
		src/link_list2.c \

OBJS =	$(SRCS:.c=.o)

all :	$(NAME)

$(NAME)	:	$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@cp $(NAME) ../
			@cp src/list.h ../../include/

clean :
		@rm -rf $(OBJS)

fclean :	clean
			@rm -rf ../$(NAME)
			@rm -rf $(NAME)

re :	fclean all

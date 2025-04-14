##
## EPITECH PROJECT, 2024
## Mackfile
## File description:
## ez
##

SRC =   my_put_uint.c \
		my_putchar.c \
		my_put_nbr.c \
		put_sce.c \
		my_getnbr.c \
		my_strlen.c \
		my_compute_power_rec.c \
		put_nbr_base.c \
		put_nbr_hex.c \
		my_printf.c \
        flag_c.c \
        flag_s.c \
        flag_pr.c \
        flag_i_d.c \
        flag_n.c \
		flag_o.c \
		flag_e.c \
		flag_f.c \
		flag_u.c \
		flag_x.c \
		my_put_float.c \
		flag_g.c \
		coma.c \
		flag_p.c \
		take_pres.c \
		my_putstr.c \
		my_put_nstr.c \
		my_put_nnbr.c \
		flag_a.c \
		flag_amaj.c \
		in.c \
        flag_char.c \
        recup_modul.c \
		str_is.c \
		is.c \
		my_str.c \
		my_str2.c \
		error_output.c \
		word_array.c \
		str_merge.c \
		file.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@mv $(NAME) ../
	@cp my.h ../../include

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ../$(NAME)

re:  fclean all

/*
** EPITECH PROJECT, 2024
** flag_c.c
** File description:
** char
*/

#include "my.h"

void flag_c(va_list list, inf_frmt_t ellemnt, int *acc)
{
    if (ellemnt.ind_conv == 'c')
        acc += my_putchar(va_arg(list, int));
}

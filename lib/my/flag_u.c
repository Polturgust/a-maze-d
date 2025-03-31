/*
** EPITECH PROJECT, 2024
** unsigned int
** File description:
** int
*/

#include "my.h"

void flag_u(va_list list, inf_frmt_t ellemnt, int *count)
{
    unsigned int i;
    int p;

    if (ellemnt.ind_conv != 'u'){
        return;
    }
    i = va_arg(list, unsigned int);
    p = take_pres(list, ellemnt.tab_inf[1], 'u');
    my_put_uint(i, count, p);
}

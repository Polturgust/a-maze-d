/*
** EPITECH PROJECT, 2024
** flag_s
** File description:
** string
*/

#include "my.h"

void flag_s(va_list list, inf_frmt_t ellemnt, int *acc)
{
    int p;
    char *str;

    if (ellemnt.ind_conv != 's')
        return;
    str = va_arg(list, char *);
    p = take_pres(list, ellemnt.tab_inf[1], ellemnt.ind_conv);
    if (p < 0)
        my_putstr(str, acc);
    else
        my_put_nstr(str, p, acc);
}

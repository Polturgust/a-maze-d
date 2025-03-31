/*
** EPITECH PROJECT, 2024
** octal
** File description:
** octal
*/

#include "my.h"

void flag_o(va_list list, inf_frmt_t ellemnt, int *acc)
{
    int p;
    unsigned int o;

    if (ellemnt.ind_conv != 'o')
        return;
    o = va_arg(list, unsigned int);
    if (is_in('#', ellemnt.tab_inf[0]) && o != 0)
        *acc += my_putchar('0');
    p = take_pres(list, ellemnt.tab_inf[1], ellemnt.ind_conv);
    put_nbr_base(o, 8, acc, p);
}

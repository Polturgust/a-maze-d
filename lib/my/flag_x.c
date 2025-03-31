/*
** EPITECH PROJECT, 2024
** flag
** File description:
** x X
*/

#include "my.h"

void flag_x(va_list list, inf_frmt_t ellemnt, int *count)
{
    int i;
    int p;

    if (ellemnt.ind_conv != 'x' && ellemnt.ind_conv != 'X')
        return;
    i = va_arg(list, unsigned int);
    p = take_pres(list, ellemnt.tab_inf[1], ellemnt.ind_conv);
    if (is_in('#', ellemnt.tab_inf[0]) && i != 0) {
        if (ellemnt.ind_conv == 'x')
            my_putstr("0x", count);
        if (ellemnt.ind_conv == 'X')
            my_putstr("0X", count);
    }
    if (p > 0)
        for (; get_power(i, 16) < p; p--)
            *count += my_putchar('0');
    if (ellemnt.ind_conv == 'x')
        hexa_min(i, count);
    if (ellemnt.ind_conv == 'X')
        hexa_maj(i, count);
}

/*
** EPITECH PROJECT, 2024
** flags f
** File description:
** flags
*/

#include "my.h"

void flag_f(va_list list, inf_frmt_t ellemnt, int *count)
{
    double d;
    int p;

    if (ellemnt.ind_conv != 'f' && ellemnt.ind_conv != 'F')
        return;
    d = va_arg(list, double);
    if (is_in(' ', ellemnt.tab_inf[0]) && d > 0.0)
        *count += my_putchar(' ');
    p = take_pres(list, ellemnt.tab_inf[1], ellemnt.ind_conv);
    if (p < 0)
        my_put_float(d, 6, count);
    else
        my_put_float(d, p, count);
}

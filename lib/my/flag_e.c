/*
** EPITECH PROJECT, 2024
** flag e
** File description:
** e
*/

#include "my.h"

void flag_e(va_list list, inf_frmt_t ellemnt, int *count)
{
    int p;
    double d;

    if (ellemnt.ind_conv != 'e' && ellemnt.ind_conv != 'E')
        return;
    d = va_arg(list, double);
    if (is_in(' ', ellemnt.tab_inf[0]) && d > 0.0)
        *count += my_putchar(' ');
    p = take_pres(list, ellemnt.tab_inf[1], ellemnt.ind_conv);
    if (p < 0)
        p = 6;
    if (ellemnt.ind_conv == 'e')
        put_scemin(d, p, count, ellemnt.ind_conv);
    if (ellemnt.ind_conv == 'E')
        put_scemaj(d, p, count, ellemnt.ind_conv);
}

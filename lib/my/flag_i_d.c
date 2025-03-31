/*
** EPITECH PROJECT, 2024
** flag_i_d.c
** File description:
** int
*/

#include "my.h"

static void flag_ll_id(long lnb, int p, inf_frmt_t ellemnt, int *acc)
{
    if (is_in(' ', ellemnt.tab_inf[0]) && lnb > 0L)
        *acc += my_putchar(' ');
    if (p <= 0)
        my_put_llnbr(lnb, acc);
    else
        my_put_llnnbr(lnb, acc, p);
}

void flag_i_d(va_list list, inf_frmt_t ellemnt, int *acc)
{
    long lnb;
    int nb;
    int p;

    if (ellemnt.ind_conv != 'i' && ellemnt.ind_conv != 'd')
        return;
    if (is_in('l', ellemnt.tab_inf[2])){
        lnb = va_arg(list, long);
        p = take_pres(list, ellemnt.tab_inf[1], 'i');
        return flag_ll_id(lnb, p, ellemnt, acc);
    }
    nb = va_arg(list, int);
    p = take_pres(list, ellemnt.tab_inf[1], 'i');
    if (is_in(' ', ellemnt.tab_inf[0]) && nb > 0)
        *acc += my_putchar(' ');
    if (p <= 0)
        my_put_nbr(nb, acc);
    else
        my_put_nnbr(nb, acc, p);
}

/*
** EPITECH PROJECT, 2024
** my_put_nnbr.c
** File description:
** put n char of a number
*/

#include "my.h"

void my_put_llnnbr(long nb, int *acc, int pres)
{
    if (nb < 0L) {
        nb *= - 1L;
        *acc += my_putchar('-');
    }
    for (; get_lpower(nb, 10) < pres; pres--)
        *acc += my_putchar('0');
    my_put_llnbr(nb, acc);
}

void my_put_nnbr(int nb, int *acc, int pres)
{
    if (nb < 0) {
        nb *= - 1;
        *acc += my_putchar('-');
    }
    for (; get_power(nb, 10) < pres; pres--)
        *acc += my_putchar('0');
    my_put_nbr(nb, acc);
}

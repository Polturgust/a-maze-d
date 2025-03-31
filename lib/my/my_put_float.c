/*
** EPITECH PROJECT, 2024
** my_put_float
** File description:
** float
*/

#include "my.h"

void verif_flags(char f, int j, int *count)
{
    if (j == 0 && f == '#')
        *count += my_putchar('.');
}

void my_put_float(double i, int pres, int *count)
{
    int j = 0;

    j = (int)i;
    i = i - j;
    my_put_nbr(j, count);
    if (j < 0)
        i = i * - 1;
    for (int k = 0; pres > k; k++)
        i = i * 10.0;
    j = (int)i;
    if (pres == 0)
        return;
    *count += my_putchar('.');
    if (j == 0)
        for (; pres > 1; pres--)
            *count += my_putchar('0');
    if ((int)(i * 10) % 10 >= 5.0)
        my_put_nbr(j + 1, count);
    else
        my_put_nbr(j, count);
}

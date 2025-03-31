/*
** EPITECH PROJECT, 2024
** flag_amaj
** File description:
** oui
*/

#include "my.h"

void char_diez(const char *f, int *count, int *idc)
{
    int len = 0;

    len = my_strlen(f) - 1;
    if (f[0] != '#')
        return;
    if (f[len] == 'O' || f[len] == 'o')
        *count += my_putchar('0');
    if (f[len] == 'x'){
        *count += 2;
        write(1, "0x", 2);
    }
    if (f[len] == 'X'){
        *count += 2;
        write(1, "0X", 2);
    }
    *idc += 1;
}

void char_nbr(const char *f, int *count, int *idc)
{
    int nbr = my_getnbr(f);

    if (nbr == 0)
        return;
    for (int i = 0; i < nbr; i++)
        *count += my_putchar(' ');
    for (nbr; nbr > 10; nbr / 10)
        *idc += 1;
    *idc += 1;
}

/*
** EPITECH PROJECT, 2024
** take_pres.c
** File description:
** take prescision
*/

#include "my.h"

int test_pres(int nb, char f)
{
    if (f == 'e' || f == 'E' || f == 'F' ||
        f == 'f' || f == 'g' || f == 'G') {
        if (nb >= 6)
            return 6;
    }
    if ((f == 'a' || f == 'A') && nb >= 13)
        return 13;
    if (nb < 0)
        return -1;
    return nb;
}

int take_pres(va_list list, char *pres, char f)
{
    int nb = -1;

    if (!pres)
        return -1;
    if (pres[0] == '*')
        nb = va_arg(list, int);
    if (pres[0] == '.') {
        nb = 0;
        for (int i = 1; pres[i] != '\0'; i++) {
            nb = nb * 10;
            nb += pres[i] - 48;
        }
    }
    return test_pres(nb, f);
}

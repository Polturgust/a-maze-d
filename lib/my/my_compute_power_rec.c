/*
** EPITECH PROJECT, 2024
** my_compute_power_rec
** File description:
** ezfzef
*/

#include "my.h"

unsigned long long my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    else
        return my_compute_power_rec(nb, p - 1) * nb;
}

int get_power(unsigned int nb, int base)
{
    int compt = 1;

    while (nb > (base - 1)) {
        nb /= base;
        compt++;
    }
    return compt;
}

int get_lpower(unsigned long nb, int base)
{
    int compt = 1;

    while (nb > (base - 1)) {
        nb /= base;
        compt++;
    }
    return compt;
}

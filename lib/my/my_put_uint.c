/*
** EPITECH PROJECT, 2024
** my_put_uint.c
** File description:
** put unsigned int
*/

#include "my.h"

int my_put_uint(unsigned int nb, int *size, int p)
{
    int nb_courrant;

    while (get_power(nb, 10) < p) {
        *size += my_putchar('0');
        p--;
    }
    p = 0;
    nb_courrant = (nb % 10) + 48;
    if (nb >= 10) {
        *size += 1;
        my_put_uint(nb / 10, size, p);
        return (write(1, &nb_courrant, 1));
    } else {
        *size += 1;
        return (write(1, &nb_courrant, 1));
    }
}

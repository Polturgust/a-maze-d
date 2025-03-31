/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** ...
*/

#include "my.h"

static int llneg_abs(long nb, int *size)
{
    if (nb == -9223372036854775807) {
        write(1, "-9223372036854775807", 20);
        (*size) += 21;
        return (0);
    }
    return 1;
}

static int neg_abs(int nb, int *size)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        (*size) += 11;
        return (0);
    }
    return 1;
}

int my_put_llnbr(long nb, int *size)
{
    long nb_courrant;

    nb_courrant = (nb % 10) + 48;
    if (llneg_abs(nb, size) == 0)
        return 0;
    if (nb < 0) {
        *size += my_putchar('-');
        my_put_llnbr(-1 * nb, size);
        return 0;
    }
    if (nb >= 10L) {
        my_put_llnbr(nb / 10L, size);
        *size += my_putchar(nb_courrant);
        return 0;
    } else {
        (*size) += my_putchar(nb_courrant);
        return 0;
    }
}

int my_put_nbr(int nb, int *size)
{
    int nb_courrant;

    nb_courrant = (nb % 10) + 48;
    if (neg_abs(nb, size) == 0)
        return 0;
    if (nb < 0) {
        *size += my_putchar('-');
        my_put_nbr(-1 * nb, size);
        return 0;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10, size);
        *size += my_putchar(nb_courrant);
        return 0;
    } else {
        (*size) += my_putchar(nb_courrant);
        return 0;
    }
}

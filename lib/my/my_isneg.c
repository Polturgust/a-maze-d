/*
** EPITECH PROJECT, 2024
** my_isneg.c
** File description:
**  negatif or not
*/

#include "my.h"

int my_isneg(int n)
{
    char n_or_p;

    if (n >= 0){
        n_or_p = 'P';
        my_putchar(n_or_p);
    } else {
        n_or_p = 'N';
        my_putchar(n_or_p);
    }
}

/*
** EPITECH PROJECT, 2024
** flag_%
** File description:
** %
*/

#include "my.h"

void flag_pr(char f, int *acc)
{
    if (f == '%') {
        *acc += my_putchar('%');
    }
}

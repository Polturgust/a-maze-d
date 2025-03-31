/*
** EPITECH PROJECT, 2024
** lenght modifier
** File description:
** cheh
*/

#include "my.h"

void lenght_h(va_list list, char *h, int *count)
{
    if (h[0] != 'h')
        return;
}

void lenght_l(va_list list, char *h, int *count)
{
    if (h[0] != 'l')
        return;
}

void lenght_ll(va_list list, char *h, int *count)
{
    if (h[0] != 'l' && h[1] != 'l')
        return 0;
}

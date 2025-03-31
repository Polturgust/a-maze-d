/*
** EPITECH PROJECT, 2024
** put_nbr
** File description:
** en base
*/

#include "my.h"

void put_nbr_base(unsigned int n, int base, int *count, int pres)
{
    if (pres > 0) {
        while (get_power(n, 8) < pres) {
            *count += my_putchar('0');
            pres--;
        }
        pres = - 1;
    }
    if (n < base) {
        count += my_putchar(n + 48);
    } else {
        put_nbr_base(n / base, base, count, pres);
        count += my_putchar(n % base + 48);
    }
}

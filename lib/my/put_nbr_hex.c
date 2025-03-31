/*
** EPITECH PROJECT, 2024
** base hexadecimale
** File description:
** oui
*/

#include "my.h"

void hexa_min(unsigned int n, int *count)
{
    char *hex = "0abcdef";

    if (n < 16){
        if (n > 9)
            *count += my_putchar(hex[n - 9]);
        else
            *count += my_putchar(n + 48);
    } else {
        hexa_min(n / 16, count);
        if (n % 16 > 9)
            *count += my_putchar(hex[n % 16 - 9]);
        else
            *count += my_putchar(n % 16 + 48);
    }
}

void hexa_maj(unsigned int n, int *count)
{
    char *hex = "0ABCDEF";

    if (n < 16){
        if (n > 9)
            *count += my_putchar(hex[n - 9]);
        else
            *count += my_putchar(n + 48);
    } else {
        hexa_maj(n / 16, count);
        if (n % 16 > 9)
            *count += my_putchar(hex[n % 16 - 9]);
        else
            *count += my_putchar(n % 16 + 48);
    }
}

void hexa_minlong(unsigned long n, int *count)
{
    char *hex = "0abcdef";

    if (n < 16){
        if (n > 9)
            *count += my_putchar(hex[n - 9]);
        else
            *count += my_putchar(n + 48);
    } else {
        hexa_minlong(n / 16, count);
        if (n % 16 > 9)
            *count += my_putchar(hex[n % 16 - 9]);
        else
            *count += my_putchar(n % 16 + 48);
    }
}

void hexa_majlong(unsigned long n, int *count)
{
    char *hex = "0ABCDEF";

    if (n < 16){
        if (n > 9)
            *count += my_putchar(hex[n - 9]);
        else
            *count += my_putchar(n + 48);
    } else {
        hexa_majlong(n / 16, count);
        if (n % 16 > 9)
            *count += my_putchar(hex[n % 16 - 9]);
        else
            *count += my_putchar(n % 16 + 48);
    }
}

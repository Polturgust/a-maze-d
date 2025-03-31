/*
** EPITECH PROJECT, 2024
** my_put_nstr.c
** File description:
** put n char of a str
*/

#include "my.h"

void my_put_nstr(char *str, int n, int *acc)
{
    for (int i = 0; (str[i] != '\0' && i < n); i++) {
        *acc += my_putchar(str[i]);
    }
}

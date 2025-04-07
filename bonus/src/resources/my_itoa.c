/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** my_itoa.c
*/

#include <stdlib.h>

char *my_itoa(int num)
{
    int len = 0;
    int n = num;
    char *str;

    if (num == 0)
        return "0";
    while (n != 0) {
        n /= 10;
        len++;
    }
    str = malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    while (num != 0) {
        len--;
        str[len] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}

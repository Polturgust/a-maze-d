/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-eric.faure-dunand-bruschi
** File description:
** my_str2.c
*/

#include "my.h"

char *str_dupby(char *str, char *by, int less)
{
    char *dest;
    int forward = 0;
    int size;

    if (!str)
        return NULL;
    size = (my_strlen(str) - (size_wrd(str, 0, by) + less));
    dest = malloc(sizeof(char) * (size + 1));
    if (!dest)
        return NULL;
    for (; !is_in(str[forward], by); forward++);
    forward += less;
    for (int i = 0; str[i + forward] && i < size; i++)
        dest[i] = str[i + forward];
    dest[size] = '\0';
    return dest;
}

int my_strncmp(char *str1, char *str2, int nb)
{
    if (!str1)
        return - 1;
    if (!str2)
        return 1;
    if (my_strlen(str1) != my_strlen(str2)) {
        if (nb > my_strlen(str2))
            return 1;
        if (nb > my_strlen(str1))
            return - 1;
    }
    for (int i = 0; str1[i] && i < nb; i++)
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    return 0;
}

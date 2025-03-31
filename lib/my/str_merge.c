/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell2-eric.faure-dunand-bruschi
** File description:
** str_merge.c
*/

#include "my.h"

char *my_str_merge(char *str1, char *str2)
{
    char *result;
    int i;

    if (!str1)
        return str2;
    if (!str2)
        return str1;
    result = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    if (!result)
        return NULL;
    for (i = 0; str1[i]; i++)
        result[i] = str1[i];
    for (int j = 0; str2[j]; j++)
        result[i + j] = str2[j];
    result[my_strlen(str1) + my_strlen(str2)] = '\0';
    return result;
}

char *str_merge(int nb, ...)
{
    va_list list;
    char *str;
    char *temp;
    char *res;

    if (nb == 0)
        return NULL;
    va_start(list, nb);
    res = va_arg(list, char *);
    for (int i = 1; i != nb; i++) {
        str = va_arg(list, char *);
        temp = res;
        res = my_str_merge(temp, str);
        if (i != 1)
            free(temp);
    }
    va_end(list);
    return res;
}

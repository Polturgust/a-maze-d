/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** euuu
*/

#include "my.h"

char *my_strdup(char *str)
{
    char *dup;

    if (!str)
        return NULL;
    dup = malloc(sizeof(char) * my_strlen(str) + 1);
    if (!dup)
        return NULL;
    for (int i = 0; str[i]; i++)
        dup[i] = str[i];
    dup[my_strlen(str)] = '\0';
    return dup;
}

char *my_strndup(char *str, int n)
{
    char *dup;
    int size = my_strlen(str);

    if (!str || n == 0)
        return NULL;
    if (size < n)
        dup = malloc(sizeof(char) * (size + 1));
    else
        dup = malloc(sizeof(char) * (n + 1));
    if (!dup)
        return NULL;
    for (int i = 0; str[i] && i < n; i++)
        dup[i] = str[i];
    if (size < n)
        dup[size] = '\0';
    else
        dup[n] = '\0';
    return dup;
}

int my_strcmp(char *str1, char *str2)
{
    if (!str1)
        return - 1;
    if (!str2)
        return 1;
    if (my_strlen(str1) > my_strlen(str2))
        return 1;
    if (my_strlen(str1) < my_strlen(str2))
        return - 1;
    for (int i = 0; str1[i]; i++)
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    return 0;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int size = my_strlen(src);

    for (; i < size; i++)
        dest[i] = src[i];
    dest[size] = '\0';
    return dest;
}

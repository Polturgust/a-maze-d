/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-eric.faure-dunand-bruschi
** File description:
** str_is.c
*/

#include "my.h"

int str_is_alpa(char *str)
{
    if (!str)
        return 1;
    for (int i = 0; str[i]; i++)
        if (!is_alpha(str[i]))
            return 0;
    return 1;
}

int str_is_num(char *str)
{
    if (!str)
        return 1;
    for (int i = 0; str[i]; i++)
        if (!is_num(str[i]))
            return 0;
    return 1;
}

int str_is_alphanum(char *str)
{
    if (!str)
        return 1;
    for (int i = 0; str[i]; i++)
        if (!is_alphanum(str[i]))
            return 0;
    return 1;
}

/*
** EPITECH PROJECT, 2024
** recup + modulaire
** File description:
** modulaire
*/

#include "my.h"

inf_frmt_t recup_lenghtmodif(char *str, inf_frmt_t ellemnt)
{
    return ellemnt;
}

char *recup_format(const char *str, char *st)
{
    int i = 0;
    int j = 0;

    for (i; is_in(str[i], "idoxXcsugGeEaAn") != 1; i++);
    st = malloc(sizeof(char) * (i + 1));
    if (!st)
        return NULL;
    if (is_in(str[j], "idoxXcsugGeEaAn") == 0)
        for (j; is_in(str[j], "idoxXcsugGeEaAn") != 1; j++)
            st[j] = str[j];
    st[j] = str[j];
    st[i + 1] = '\0';
    return st;
}

/*
** EPITECH PROJECT, 2024
** printf
** File description:
** is.c
*/

#include "my.h"

int is_num(char c)
{
    if (c >= 48 && c <= 57)
        return 1;
    return 0;
}

int is_char_trb(char c, int i)
{
    if (c == '#' || c == '0' || c == '-' || c == '+')
        return 1;
    return 0;
}

int is_prs(char c, int i)
{
    if (i == 0 && (c == '.' || c == '*'))
        return 1;
    if (i != 0 && is_num(c))
        return 1;
    return 0;
}

int is_mod_lng(char c, int i)
{
    if (c == 'h' || c == 'l' || c == 'L' || c == 'q' || c == 'j' || c == 'z' ||
    c == 't')
        return 1;
    return 0;
}

int is_id_cnv(char c, int i)
{
    if (is_in(c, "diouxXeEfFgGaAcspn%") && i == 0);
        return 1;
    return 0;
}

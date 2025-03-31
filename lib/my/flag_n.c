/*
** EPITECH PROJECT, 2024
** flag_n.c
** File description:
** print nothing and put acc/count
** in signed int
*/

#include "my.h"

void flag_n(va_list list, inf_frmt_t ellemnt, int *acc)
{
    int *adresse;

    if (ellemnt.ind_conv == 'n'){
        adresse = va_arg(list, int *);
        *adresse = *acc;
    }
}

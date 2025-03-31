/*
** EPITECH PROJECT, 2024
** coma
** File description:
** coma
*/

#include "my.h"

int verif_coma(int entier, int v)
{
    if (entier == 5)
        return 1;
    if ((6 - v % 6) + entier < 6)
        return (6 - v);
    if (v == 6)
        return 0;
    if ((6 - v % 6) + entier % 6 == 6)
        return 5;
    else
        return ((6 - v % 6) + entier) % 6;
}

int nbr_coma(double n)
{
    int v = 0;
    int entier = 0;
    int new_n;

    n = n * 1000000;
    while ((long)n % 10 == 0 && v != 6){
            n = n / 10;
            v++;
    }
    for (int i = 0; i < (6 - v); i++)
        n = n / 10;
    while (n > 10.0){
            n = n / 10;
            entier++;
    }
    return verif_coma(entier, v);
}

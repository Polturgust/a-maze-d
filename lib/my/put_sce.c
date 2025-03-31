/*
** EPITECH PROJECT, 2024
** put_sce
** File description:
** putsce
*/

#include "my.h"

int expo(int n, int *count)
{
    if (n < 0){
        *count += my_putchar('-');
        n = n * - 1;
    } else
        *count += my_putchar('+');
    if (n < 10)
        *count += my_putchar('0');
    if (n == 0)
        *count += my_putchar('0');
    return n;
}

void put_scemin(double n, int pres, int *count, char f)
{
    int cpt = 0;

    if ((n < 1.0 && n > - 1.0) && n != 0.0)
        while (n < 1.0 && n > - 1.0){
            n = n * 10;
            cpt--;
        }
    if ((n > 10.0 || n < - 10.0) && n != 0.0)
        while (n > 10.0 || n < - 10.0){
            n = n / 10;
            cpt++;
        }
    if (f == 'g')
        pres = 6 - nbr_coma(n);
    if (pres < 6)
        my_put_float(n, pres, count);
    else
        my_put_float(n, 6, count);
    *count += my_putchar('e');
    my_put_nbr(expo(cpt, count), count);
}

void put_scemaj(double n, int pres, int *count, char f)
{
    int cpt = 0;

    if (n < 1.0 && n > - 1.0)
        while (n < 1.0 && n > - 1.0){
            n = n * 10;
            cpt--;
        }
    if (n > 10.0 || n < - 10.0)
        while (n > 10.0 || n < - 10.0){
            n = n / 10;
            cpt++;
        }
    if (f == 'G')
        pres = 6 - nbr_coma(n);
    if (pres < 6)
        my_put_float(n, pres, count);
    else
        my_put_float(n, 6, count);
    *count += my_putchar('E');
    my_put_nbr(expo(cpt, count), count);
}

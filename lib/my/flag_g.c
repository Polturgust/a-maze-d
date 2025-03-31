/*
** EPITECH PROJECT, 2024
** flag g
** File description:
** g
*/

#include "my.h"

int cpt_exp(double n)
{
    int cpt = 0;

    while ((n > 10.0 || n < - 10.0) && n != 0.0){
            n = n / 10;
            cpt++;
        }
    while ((n < 1.0 && n > - 1.0) && n != 0.0){
        n = n * 10;
        cpt++;
        }
    return cpt;
}

void verif_count(int cpt, int v, double n, int *count)
{
    if (cpt == 5)
        my_put_nbr((int)n, count);
    else
        my_put_float(n, v, count);
}

static void spaceg(inf_frmt_t ellemnt, double n, int *count)
{
    if (is_in(' ', ellemnt.tab_inf[0]) && n > 0.0)
        *count += my_putchar(' ');
}

void flag_g(va_list list, inf_frmt_t ellemnt, int *count)
{
    int v;
    double n;
    int cpt;

    if (ellemnt.ind_conv != 'g' && ellemnt.ind_conv != 'G')
        return;
    n = va_arg(list, double);
    cpt = cpt_exp(n);
    spaceg(ellemnt, n, count);
    if (n < 0.0)
        v = nbr_coma(n * - 1);
    else
        v = nbr_coma(n);
    if (cpt >= 6 || cpt <= - 4) {
        if (ellemnt.ind_conv == 'g')
            put_scemin(n, 6 - v, count, 'g');
        else
            put_scemaj(n, 6 - v, count, 'G');
    } else
        verif_count(cpt, v, n, count);
}

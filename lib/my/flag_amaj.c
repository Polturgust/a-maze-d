/*
** EPITECH PROJECT, 2024
** flag A
** File description:
** the true honored one
*/

#include "my.h"

void expo_maj(int cpt, int *count)
{
    if (cpt > 0)
        *count += my_putchar('+');
    my_put_nbr(cpt, count);
}

void verif_zeromaj(long j, int *count, double i)
{
    long accu = 1;
    int cpt_zero = 0;

    if (j % 16 == 0)
        while (j % 16 == 0 && cpt_zero != 13){
            cpt_zero++;
            j = j / 16;
        }
    for (int i = 0; i < 13 - cpt_zero; i++)
        accu = accu * 16;
    while ((j / (accu / 16)) % 16 == 0){
        *count += my_putchar('0');
        accu = accu / 16;
    }
    j = j % accu;
    if ((long)(i * 16) % 16 >= 8.0)
        hexa_majlong(j + 1, count);
    else
        hexa_majlong(j, count);
}

void my_put_floathexmaj(double i, int *count)
{
    long j = 0;
    int pres = 0;
    long accu = 1;

    *count += 2;
    write(1, "0X", 2);
    j = (long)i;
    hexa_majlong(j, count);
    for (pres; pres < 26; pres++){
        i = i * 16.0;
        pres++;
        accu = accu * 16;
    }
    j = (long)i;
    if (j % accu == 0)
        return;
    *count += my_putchar('.');
    verif_zeromaj(j, count, i);
}

void put_scehexmaj(double n, int *count)
{
    int cpt = 0;
    int pres = 0;

    if (n < 1.0 && n > - 1.0)
        while (n < 1.0 && n > - 1.0){
            n = n * 2;
            cpt--;
        }
    if (n >= 2.0 || n <= - 2.0)
        while (n >= 2.0 || n <= - 2.0){
            n = n / 2;
            cpt++;
        }
    if (n < 0.0){
        n = n * - 1;
        *count += my_putchar('-');
    }
    my_put_floathexmaj(n, count);
    *count += my_putchar('P');
    expo_maj(cpt, count);
}

void flag_amaj(va_list list, inf_frmt_t ellemnt, int *count)
{
    double A;

    if (ellemnt.ind_conv != 'A')
        return;
    A = va_arg(list, double);
    if (is_in(' ', ellemnt.tab_inf[0]) && A > 0.0)
        *count += my_putchar(' ');
    put_scehexmaj(A, count);
}

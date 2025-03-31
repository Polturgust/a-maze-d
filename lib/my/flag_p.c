/*
** EPITECH PROJECT, 2024
** flag p
** File description:
** p
*/

#include "my.h"

void put_adress_point(unsigned long p, int *count)
{
    char *str = "0123456789abcdef";

    if (p < 16){
        *count += my_putchar(str[p]);
        return;
    } else {
        put_adress_point(p / 16, count);
        *count += my_putchar(str[p % 16]);
        return;
    }
}

void flag_p(va_list list, inf_frmt_t ellemnt, int *count)
{
    if (ellemnt.ind_conv == 'p'){
        write(1, "0x", 2);
        *count += 2;
        put_adress_point(va_arg(list, unsigned long), count);
    }
    return;
}

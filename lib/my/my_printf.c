/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** vZ
*/

#include "my.h"

static int take_info(const char *format, int i, inf_frmt_t *inf_frmt)
{
    int (*tab[])(char, int) = {is_char_trb, is_prs, is_mod_lng};
    int in;

    for (int y = 0; y < 3; y++) {
        for (in = 0; tab[y](format[i], in); i++) {
            inf_frmt->tab_inf[y][in] = format[i];
            in++;
        }
        inf_frmt->tab_inf[y][in] = '\0';
    }
    if (is_id_cnv(format[i], 0))
        inf_frmt->ind_conv = format[i];
    else
        inf_frmt->ind_conv = '\0';
    return i;
}

void put_not_flag(int *acc, char f)
{
    *acc += my_putchar('%');
    *acc += my_putchar(f);
}

void test_flags(va_list list, const char *str, int *acc, int *i)
{
    void (*tab[])(va_list list, inf_frmt_t ellemnt, int *acc) =
        {flag_i_d, flag_c, flag_s, flag_n, flag_e, flag_o,
        flag_f, flag_x, flag_u, flag_g, flag_p, flag_a, flag_amaj, 0};
    inf_frmt_t ellemnt;

    *i += 1;
    *i = take_info(str, * i, &ellemnt);
    if (ellemnt.ind_conv == '%')
        return flag_pr(ellemnt.ind_conv, acc);
    if (is_in(ellemnt.ind_conv, "idcsneEofFxXugGpaA") == true)
        for (int k = 0; tab[k] != 0; k++)
            tab[k](list, ellemnt, acc);
    else
        put_not_flag(acc, ellemnt.ind_conv);
}

int my_printf(const char *format, ...)
{
    va_list list;
    int acc = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            test_flags(list, format, &acc, &i);
        } else {
            my_putchar(format[i]);
            acc++;
        }
    }
    va_end(list);
    return acc;
}

/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** enfaite je sais
*/

#include "my.h"

int my_put_char_tab(char **arr)
{
    if (!arr)
        return 84;
    for (int i = 0; arr[i]; i++) {
        my_putstr(arr[i], NULL);
        write(1, "\n", 1);
    }
    return 0;
}

int my_putstr(char *str, int *acc)
{
    if (!str) {
        my_puterror_str("(Null)");
        return 84;
    }
    write(1, str, my_strlen(str));
    if (acc)
        *acc += my_strlen(str);
    return 1;
}

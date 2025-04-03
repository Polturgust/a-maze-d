/*
** EPITECH PROJECT, 2025
** word_array.c
** File description:
** trake str and retuen array
*/

#include <stdlib.h>
#include "my.h"

unsigned int size_wrd(char *str, int forward, char *separ)
{
    int acc = 0;

    for (; str[forward] && !is_in(str[forward], separ); forward++)
        acc++;
    return acc;
}

unsigned int nb_word(char *str, char *separ)
{
    int acc = 0;

    if (!str || str[0] == '\0')
        return 0;
    if (!is_in(str[0], separ))
        acc++;
    for (int i = 0; str[i + 1]; i++)
        if ((is_in(str[i], separ) && !is_in(str[i + 1], separ)))
            acc++;
    return acc;
}

char **str_to_word_array(char *str, char *separ)
{
    unsigned int nb_wrd = nb_word(str, separ);
    unsigned int forward = 0;
    char **array = malloc(sizeof(char *) * (nb_wrd + 1));
    unsigned int i = 0;

    if (!array)
        return NULL;
    for (unsigned int comp = 0; comp < nb_wrd; comp++) {
        for (; is_in(str[forward], separ); forward++);
        array[comp] = malloc(sizeof(char) *
        (size_wrd(str, forward, separ) + 1));
        for (i = 0; str[forward] && !is_in(str[forward], separ); forward++) {
            array[comp][i] = str[forward];
            i++;
        }
        array[comp][i] = '\0';
        forward++;
    }
    array[nb_wrd] = NULL;
    return array;
}

void destroy_array(void **arr)
{
    if (!arr)
        return;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

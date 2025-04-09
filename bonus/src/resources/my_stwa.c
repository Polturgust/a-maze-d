/*
** EPITECH PROJECT, 2024
** sutumper_resources
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdio.h>

static int cnt_words(char *str, char delimiter)
{
    int word_nbr = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == delimiter)
            i++;
        if (str[i] != '\0')
            word_nbr++;
        while (str[i] != '\0' && str[i] != delimiter)
            i++;
    }
    return word_nbr;
}

static char **malloc_to_size(char *input_str, char delimiter)
{
    int word_nbr = cnt_words(input_str, delimiter);
    char **res = malloc(sizeof(char *) * (word_nbr + 1));
    int i = 0;
    int cur_word = 0;
    int start = 0;
    int len = 0;

    while (input_str[i] != '\0') {
        for (; input_str[i] == delimiter; i++);
        start = i;
        while (input_str[i] != '\0' && input_str[i] != delimiter)
            i++;
        len = i - start;
        if (len > 0) {
            res[cur_word] = malloc(sizeof(char) * (len + 1));
            cur_word++;
        }
    }
    res[cur_word] = NULL;
    return res;
}

char **my_stwa(char *input_str, char delimiter)
{
    char **res;
    int cur_word = 0;
    int pos_in_word = 0;

    if (input_str == NULL)
        return NULL;
    res = malloc_to_size(input_str, delimiter);
    for (int i = 0; input_str[i] != '\0';) {
        for (; input_str[i] == delimiter; i = i + 1);
        if (input_str[i] == '\0')
            break;
        for (; input_str[i] != '\0' && input_str[i] != delimiter; i++) {
            res[cur_word][pos_in_word] = input_str[i];
            pos_in_word++;
        }
        res[cur_word][pos_in_word] = '\0';
        cur_word++;
        pos_in_word = 0;
    }
    return res;
}

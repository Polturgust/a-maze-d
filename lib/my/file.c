/*
** EPITECH PROJECT, 2024
** B-CPE-200-NCE-2-1-robotfactory-charles.corsiero
** File description:
** file.c
*/

#include "my.h"

char *get_file(char *path)
{
    char *res;
    struct stat st;
    int fd;

    if (!is_file(path))
        return NULL;
    stat(path, &st);
    fd = open(path, O_RDONLY);
    res = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, res, st.st_size);
    res[st.st_size] = '\0';
    close(fd);
    return res;
}

char **get_stdin_file(void)
{
    char *input = NULL;
    char *tmp = NULL;
    char *res_tmp = NULL;
    char **res;
    size_t n;

    if (getline(&tmp, &n, stdin) == -1)
        return NULL;
    while (getline(&input, &n, stdin) != -1) {
        res_tmp = str_merge(2, tmp, input);
        free(tmp);
        tmp = NULL;
        tmp = res_tmp;
    }
    free(input);
    tmp = NULL;
    res = str_to_word_array(res_tmp, "\n");
    free(res_tmp);
    return res;
}

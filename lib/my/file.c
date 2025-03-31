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

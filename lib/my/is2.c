/*
** EPITECH PROJECT, 2024
** ls
** File description:
** is2.c
*/

#include "my.h"

int is_only(char *str, char *chara)
{
    if (!str)
        return 1;
    for (int i = 0; str[i]; i++)
        if (!is_in(str[i], chara))
            return 0;
    return 1;
}

int is_alpha(char c)
{
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
        return 1;
    return 0;
}

int is_alphanum(char c)
{
    if (is_num(c) || is_alpha(c))
        return 1;
    return 0;
}

int is_dir(char *path)
{
    DIR *dir = opendir(path);

    if (!dir)
        return 0;
    closedir(dir);
    return 1;
}

int is_file(char *path)
{
    DIR *dir = opendir(path);
    struct stat buffer;

    if (stat(path, &buffer) != - 1 && !dir)
        return 1;
    if (dir)
        closedir(dir);
    return 0;
}

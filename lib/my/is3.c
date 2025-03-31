/*
** EPITECH PROJECT, 2024
** B-PSU-200-NCE-2-1-minishell1-eric.faure-dunand-bruschi
** File description:
** is3.c
*/

#include "my.h"

int is_exe(char *path)
{
    struct stat st;

    if (!path)
        return 0;
    if (stat(path, &st) == -1)
        return 0;
    if (st.st_mode & S_IXUSR)
        return 1;
    return 0;
}

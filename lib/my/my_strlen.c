/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** j'ai pas lu c'est quoi encore
*/

int my_arraylen(char **str)
{
    int i = 0;

    if (!str)
        return 0;
    for (; str[i]; i++);
    return i;
}

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    for (; str[i]; i++);
    return i;
}

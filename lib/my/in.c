/*
** EPITECH PROJECT, 2024
** in
** File description:
** in
*/

int is_in(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

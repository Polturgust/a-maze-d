/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** la mort en code
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int long res = 0;
    int signe = 1;

    while (str[i] != '\0' && ((48 <= str[i] && str[i] < 58)
    || str[i] == '-' || str[i] == '+')) {
        if (str[i] >= 48 && str[i] < 58)
            res = (res * 10) + (str[i] - 48);
        if (str[i] == '-')
            signe = -1 * signe;
        i++;
    }
    res = res * signe;
    if (res > 2147483647 || res < -2147483648)
        return 0;
    return (int)res;
}

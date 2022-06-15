/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** task13
*/

int my_str_isnum(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

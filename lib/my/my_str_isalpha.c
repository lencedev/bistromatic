/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task12
*/

int my_str_isalpha(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 0 && str[i] <= 31)
            return 0;
        if (str[i] == 127)
            return 0;
    }
    return 1;
}

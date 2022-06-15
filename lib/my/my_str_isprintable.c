/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task16
*/

int my_str_isprintable(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] <= 31 && str[i] >= 0)
            return 0;
    }
    return 1;
}

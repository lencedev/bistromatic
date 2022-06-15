/*
** EPITECH PROJECT, 2021
** Day03
** File description:
** Task03
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task03
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int i;
    int size = (my_strlen(str) - 1);
    char temp;
    int j = size / 2;

    while (i <= j) {
        temp = str[i];
        str[i] = str[size];
        str[size] = temp;
        i++;
        size--;
    }
    return str;
}

/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task09
*/

char *my_strlowcase(char *str)
{
    int i;
    int a;

    for (i = 0; str[i] != '\0'; i++) {
        a = str[i];
        if (a <= 90 && a >= 65) {
            a += 32;
            str[i] = a;
        }
    }
    return str;
}

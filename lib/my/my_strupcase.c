/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task08
*/

char *my_strupcase(char *str)
{
    int i;
    int a;

    for (i = 0; str[i] != '\0'; i++) {
        a = str[i];
        if (a > 96) {
            a -= 32;
            str[i] = a;
        }
    }
    return str;
}

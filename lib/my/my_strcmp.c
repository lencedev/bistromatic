/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i;
    int a;
    int b;

    for (i = 0; s1[i] != '\0'; i++) {
        a = s1[i];
        b = s2[i];
        if (a < b)
            return (a * (-1));
        else if (a > b)
            return a;
    }
    return (-1);
}

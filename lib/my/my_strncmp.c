/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int a;
    int b;

    while (s1[i] != '\0' && i < n) {
        a = s1[i];
        b = s2[i];
        if (a < b)
            return (a * (-1));
        else if (a > b)
            return a;
        i++;
    }
    return -1;
}

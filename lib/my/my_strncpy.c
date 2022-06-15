/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i < n; i++) {
        dest[i] = src[i];
        if (src[i] == '\0')
            break;
    }
    return dest;
}

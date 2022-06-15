/*
** EPITECH PROJECT, 2021
** Day07
** File description:
** Task02
*/

int my_strlen(char const *str);

char *my_strncat(char *dest , char const *src, int n)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}

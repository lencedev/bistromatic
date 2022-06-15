/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_get_nbrbase
*/

#include <stdlib.h>

int my_strlen(char const *str);

int check_ifbase(char c, char const *base)
{
    for (int j = 0; base[j] != '\0'; j++) {
        if (c == base[j])
            return j;
    }
    return (-1);
}

char *base_to_nbr(char *str, char const *base, char *final)
{
    int i = 1;
    int c;
    char *decimal = "0123456789";

    while (check_ifbase(str[0], base) != (-1)) {
        if (check_ifbase(str[0], base) >= 10) {
            final[i] = ((check_ifbase(str[0], base) / 10 + '0'));
            final[i + 1] = (((check_ifbase(str[0], base)) % 10) + '0');
            i++;
            *str += 1;
        } else {
            c = check_ifbase(str[0], base) % my_strlen(decimal);
            final[i] = decimal[c];
            i++;
            *str += 1;
        }
    }
    if (final[0] == '\0')
        return &final[1];
    return final;
}

char *my_get_nbrbase(char *str, char const *base)
{
    int minus = 0;
    char *final = malloc(sizeof(char) * my_strlen(str));
    while (str[0] == '+' || str[0] == '-') {
        if (str[0] == '-')
            minus++;
        *str += 1;
    }
    if (minus % 2 == 1)
        final[0] = '-';
    return base_to_nbr(str, base, final);
}

/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-theo.faupin
** File description:
** new_number
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);
int is_digit(char c);

char *new_number(char **str)
{
    int i = 0;
    int minus = 0;
    char *final = malloc(sizeof(char) * (my_strlen(*str) + 1));

    for (int j = 0; j < my_strlen(*str) + 1; j++)
        final[j] = '\0';
    while (*str[0] == '-' || *str[0] == '+') {
        if (*str[0] == '-')
            minus++;
        *str += 1;
    }
    if (minus % 2 == 1) {
        final[i] = '-';
        i++;
    }
    while(is_digit(*str[0]) == 1) {
        final[i] = *str[0];
        i++;
        *str += 1;
    }
    return final;
}

/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** infinsub
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

char *add_char(char const *s1, char const *s2);
char *print_str(char *final, int carry);

char *infin_sub(char const *s1, char const *s2, char *final)
{
    int a;
    int b;
    int result = 0;
    int carry = 0;
    int diff = (my_strlen(s1) - my_strlen(s2));
    for (int i = (my_strlen(s1) - 1); i >= 0; i--) {
        a = (s1[i] - '0');
        if ((i - diff) < 0)
            b = 0;
        else
            b = s2[i - diff] - '0';
        result = a - (b + carry);
        carry = 0;
        if (result < 0) {
            result += 10;
            carry = 1;
        }
        final[i + 1] = ((result % 10) + '0');
    }
    return print_str(final, carry);
}

char *translate(char *temp)
{
    char *final = malloc(sizeof(char) * my_strlen(temp) + 2);
    int i = 0;

    if (temp[0] == '0' && temp[1] == '\0')
        return "0";
    for (int j = 0; j < my_strlen(temp) + 2; j++)
        final[j] = '\0';
    final[0] = '-';
    for (i = 0; temp[i] != '\0'; i++)
        final[i + 1] = temp[i];
    return final;
}

char *sign_add(char const *s1, char const *s2)
{
    char *final = malloc((sizeof(char) * (my_strlen(s1)) + 2));

    for (int i = 0; i < (my_strlen(s1) + 2); i++)
        final[i] = '\0';
    if (s1[0] != '-' && s2[0] != '-') {
        final = add_char(s1, s2);
        return final;
    }
    if (s1[0] == '-' && s2[0] == '-') {
        final = translate(add_char(&s1[1], &s2[1]));
    } else {
        if (s1[0] == '-') {
            final = translate(infin_sub(&s1[1], s2, final));
        } else
            final = (infin_sub(s1, &s2[1], final));
    }
    return final;
}

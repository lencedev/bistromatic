/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-theo.faupin
** File description:
** eval_expr
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

char *parse_summands(char **str);
char *parse_factors(char **str);
char *infinadd(char const *s1, char const *s2);
char *sign_div(char const *s1, char const *s2);
char *sign_mod(char const *s1, char const *s2);
char *sign_mult(char const *s1, char const *s2);

char *parse_parentheses(char **str)
{
    char *final = malloc(sizeof(char * ) * my_strlen(*str) + 1);
    char *temp = malloc(sizeof(char) * my_strlen(*str) + 1);
    for (int a = 0; a != my_strlen(*str); a++) {
        final[a] = '\0';
        temp = '\0';
    }
    if (**str == '(') {
        *str += 1;
        final = parse_summands(str);
        *str += 1;
    } else if (*str[0] == '-' && *str[1] == '(') {
        *str += 2;
        final[0] = '-';
        temp = parse_summands(str);
        for (int i = 0; temp[i] != '\0'; i++)
            final[i + i] = temp[i];
        *str += 1;
    } else
        final = new_number(str);
    return final;
}

char *parse_factors(char **str)
{
    char *final = parse_parentheses(str);

    while (**str == '*' || **str == '/' || **str == '%') {
        if (**str == '*') {
            *str += 1;
            final = sign_mult(final, parse_parentheses(str));
        } else if (**str == '/') {
            *str += 1;
            final = sign_div(final, parse_parentheses(str));
        } else {
            *str += 1;
            final = sign_mod(final, parse_parentheses(str));
        }
    }
    return final;
}

char *parse_summands(char **str)
{
    char *final = parse_factors(str);

    while (**str == '+' || **str == '-') {
        if (**str == '+') {
            *str += 1;
            final = infinadd(final, parse_factors(str));
        } else
            final = infinadd(final, parse_factors(str));
    }
    return final;
}

char *eval_expr(char *buffer)
{
    return (parse_summands((char**) &buffer));
}

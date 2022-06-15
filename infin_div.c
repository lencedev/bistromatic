/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** infindiv
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/bistromatic.h"
#include <stdio.h>

char *infinadd(char const *s1, char const *s2);
int compare_char(char const *s1, char const *s2);
char *divfaster(char *f, char *temp, char *add, int j);

char *check_div(char *final, char *diviseur)
{
    if (diviseur[0] == '-' && diviseur[1] == '0' && diviseur[2] == '\0') {
        write(2, "syntax error", 13);
        exit(EXIT_USAGE);
    }
    if (diviseur[0] == '-' && diviseur[1] == '1' && diviseur[2] == '\0')
        return final;
    if (my_strlen(final) < my_strlen(&diviseur[1]))
        return "0";
    if (my_strlen(final) == my_strlen(&diviseur[1])) {
        if (compare_char(final, &diviseur[1]) == 2)
            return 0;
    }
    return NULL;
}

char *division(char *final, char *diviseur)
{
    char *temp = malloc(sizeof(char) * my_strlen(final) + 1);
    char *add = malloc(sizeof(char) * my_strlen(final) + 1);
    int j;
    int a = (my_strlen(final) - (my_strlen(diviseur) - 1) - 1);

    if (check_div(final, diviseur) != NULL)
        return check_div(final, diviseur);
    for (j = 0; j != my_strlen(diviseur); j++)
        temp[j] = diviseur[j];
    for (; j <= (((my_strlen(diviseur)) + a)); j++) {
        temp[j] = '0';
        temp[j + 1] = '\0';
        add[(j - my_strlen(diviseur) + 1)] = '0';
        add[(j - my_strlen(diviseur) + 2)] = '\0';
    }
    add[0] = '1';
    return divfaster(final, temp, add, j);
}

char *infindiv(char const *s1, char const *s2)
{
    char *final = malloc(sizeof(char) * (my_strlen(s1) + 2));
    char *diviseur = malloc(sizeof(char) * (my_strlen(s2) + 3));
    int i = 0;
    int j = 0;

    for (int i = 0; i != my_strlen(s2) + 2; i++)
        diviseur[i] = '\0';
    for (j = 0; s1[j] != '\0'; j++) {
        final[j] = s1[j];
        final[j + 1] = '\0';
    }
    diviseur[i] = '-';
    for (i = 0; s2[i] != '\0'; i++)
        diviseur[i + 1] = s2[i];
    diviseur[i + 2] = '\0';
    return (division(final, diviseur));
}

int check_sign_div(char const *s1, char const *s2)
{
    int a;

    if (s1[0] != '-' && s2[0] != '-')
        a = 0;
    if (s1[0] == '-' && s2[0] != '-')
        a = 1;
    if (s2[0] == '-' && s1[0] != '-')
        a = 2;
    if (s1[0] == '-' && s2[0] == '-')
        a = 3;
    return a;
}

char *sign_div(char const *s1, char const *s2)
{
    char *temp = malloc(sizeof(char) * (my_strlen(s1) + 1));
    char *result = malloc(sizeof(char) * (my_strlen(s1) + 1));
    int i = 0;
    int a = 0;
    int b = 0;
    if (check_sign_div(s1, s2) == 1 || check_sign_div(s1, s2) == 2) {
        result[i] = '-';
        i++;
    }
    if (s1[0] == '-')
        a++;
    if (s2[0] == '-')
        b++;
    temp = infindiv(&s1[a], &s2[b]);
    for (int j = 0; temp[j] != '\0'; j++) {
        result[i] = temp[j];
        i++;
    }
    result[i] = '\0';
    return result;
}

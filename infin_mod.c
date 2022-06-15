/*
** EPITECH PROJECT, 2021
** Bistro-matic
** File description:
** infin modulo
*/

#include "include/my.h"
#include "include/bistromatic.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_sign_div(char const * s1, char const * s2);
char *infinadd(char const *s1, char const *s2);
int compare_char(char const *s1, char const *s2);
int comp_div(char const *final, char const *temp);

char *modfaster(char *f, char *temp, char *diviseur, int j)
{
    while (my_strlen(temp) >= my_strlen(diviseur)) {
        f = infinadd(f, &temp[1]);
        while ((f[0] != '0' && f[0] != '-') && comp_div(f, &temp[1]) != 2)
            f = infinadd(f, temp);
        temp[j] = '\0';
        j--;
    }
    return f;
}

char *check_mod(char *final, char *diviseur)
{
    if (diviseur[0] == '-' && diviseur[1] == '0' && diviseur[2] == '\0') {
        write(2, "syntax error", 13);
        exit(EXIT_USAGE);
    }
    if (diviseur[0] == '-' && diviseur[1] == '1' && diviseur[2] == '\0')
        return "0";
    if (my_strlen(final) < my_strlen(&diviseur[1]))
        return final;
    if (my_strlen(final) == my_strlen(&diviseur[1])) {
        if (compare_char(final, &diviseur[1]) == 2)
            return final;
    }
    return NULL;
}

char *modulo(char *final, char *diviseur)
{
    char *temp = malloc(sizeof(char) * my_strlen(final) + 1);
    int j;
    int a = (my_strlen(final) - (my_strlen(diviseur) - 1) - 1);

    if (check_mod(final, diviseur) != NULL)
        return check_mod(final, diviseur);
    for (j = 0; j != my_strlen(diviseur); j++)
        temp[j] = diviseur[j];
    for (; j < (((my_strlen(diviseur)) + a)); j++) {
        temp[j] = '0';
        temp[j + 1] = '\0';
    }
    return modfaster(final, temp, diviseur, j);
}

char *infinmod(char const *s1, char const *s2)
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
    return (modulo(final, diviseur));
}

char *sign_mod(char const *s1, char const *s2)
{
    char *temp = malloc(sizeof(char) * (my_strlen(s1) + 1));
    char *result = malloc(sizeof(char) * (my_strlen(s1) + 1));
    int i = 0;
    int a = 0;
    int b = 0;
    if (check_sign_div(s1, s2) == 1 || check_sign_div(s1, s2) == 3) {
        result[i] = '-';
        i++;
    }
    if (s1[0] == '-')
        a++;
    if (s2[0] == '-')
        b++;
    temp = infinmod(&s1[a], &s2[b]);
    for (int j = 0; temp[j] != '\0'; j++) {
        result[i] = temp[j];
        i++;
    }
    result[i] = '\0';
    return result;
}

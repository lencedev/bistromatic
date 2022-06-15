/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** infin_mul
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *infinadd(char const *s1, char const *s2);
char *infin_sub(char const *s1, char const *s2, char *final);
int compare_char(char const *s1, char const *s2);
int check_sign_div(char const *s1, char const *s2);
char *mult_comp(char const *s1, char const *s2, char *t, char *r);
char *multfaster(char *f, char *multi, char *temp, char *add);

char *check_mult(char *final, char *multiplicity)
{
    if (multiplicity[0] == '0' && multiplicity[1] == '\0')
        return "0";
    if (multiplicity[0] == '1' && multiplicity[1] == '\0')
        return final;
    return NULL;
}

char *mult(char *f, char *multi)
{
    char *temp = malloc(sizeof(char) * (my_strlen(f) + my_strlen(multi) + 1));
    char *add = malloc(sizeof(char) * (my_strlen(multi) + 2));
    int j;
    if (check_mult(f, multi) != NULL)
        return check_mult(f, multi);
    for (j = 0; f[j] != '\0'; j++)
        temp[j] = f[j];
    temp[j] = '\0';
    add[0] = '-';
    add[1] = '1';
    add[2] = '\0';
    if ((my_strlen(multi) - 2) > 1) {
        for (; j <= ((my_strlen(f)) + (my_strlen(multi) - 2)); j++) {
            temp[j] = '0';
            temp[j + 1] = '\0';
            add[((j - my_strlen(f)) + 2)] = '0';
            add[((j - my_strlen(f)) + 3)] = '\0';
        }
    }
    return multfaster(f, multi, temp, add);
}

char *infinmult(char const *s1, char const *s2)
{
    char *final = malloc(sizeof(char) * (my_strlen(s1) + 2));
    char *multiplicity = malloc(sizeof(char) * (my_strlen(s2) + 3));
    int i = 0;
    int j = 0;

    for (j = 0; s1[j] != '\0'; j++) {
        final[j] = s1[j];
        final[j + 1] = '\0';
    }
    for (i = 0; s2[i] != '\0'; i++) {
        multiplicity[i] = s2[i];
        multiplicity[i + 1] = '\0';
    }
    return (mult(final, multiplicity));
}

char *sign_mult(char const *s1, char const *s2)
{
    char *temp = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
    char *result = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
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
    temp = infinmult(&s1[a], &s2[b]);
    for (int j = 0; temp[j] != '\0'; j++) {
        result[i] = temp[j];
        i++;
    }
    result[i] = '\0';
    return result;
}

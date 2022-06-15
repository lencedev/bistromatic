/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-theo.faupin
** File description:
** opti
*/

#include <stdlib.h>
#include "include/my.h"
#include <stdio.h>

char *infinadd(char const *s1, char const *s2);
char *infin_sub(char const *s1, char const *s2, char *final);
int check_sign_div(char const *s1, char const *s2);
char *infinmult(char const *s1, char const *s2);

char *neg_char(char *str)
{
    char *final = malloc(my_strlen(str) + 3);

    if (str[0] != '-') {
        final[0] = '-';
        for (int i = 0; str[i] != '\0'; i++) {
            final[i + 1] = str[i];
            final[i + 2] = '\0';
        }
    } else {
        for (int i = 0; str[i + 1] != '\0'; i++) {
            final[i] = str[i + 1];
            final[i + 1] = '\0';
        }
    }
    return final;
}

int comp_div(char const *final, char const *temp)
{
    if (final[0] == '-')
        return comp_div(&final[1], temp);
    if (my_strlen(final) > my_strlen(temp))
        return 1;
    if (my_strlen(temp) > my_strlen(final))
        return 2;
    for (int i = 0; final[i] != '\0'; i++) {
        if (final[i] > temp[i])
            return 1;
        if (final[i] < temp[i])
            return 2;
    }
    return 1;
}

char *divfaster(char *f, char *temp, char *add, int j)
{
    int j_min = ((my_strlen(temp)) - (my_strlen(add)));
    char *count = malloc(my_strlen(f) + 1);
    char *neg_add = neg_char(add);

    for (int i = 0; i != my_strlen(f) + 1; i++)
        count[i] = '\0';
    while (my_strlen(add) >= 1) {
        while ((f[0] != '0' && f[0] != '-') && comp_div(f, &temp[1]) != 2) {
            f = infinadd(f, temp);
            count = infinadd(count, add);
        }
        f = infinadd(f, &temp[1]);
        count = infinadd(count, neg_add);
        temp[j] = '\0';
        add[(j) - j_min] = '\0';
        neg_add[(j + 1) - j_min] = '\0';
        j--;
    }
    count = infinadd(count, "1");
    return count;
}

char *multfaster(char *f, char *multi, char *temp, char *add)
{
    char *neg_temp = neg_char(temp);
    char *neg_add = neg_char(add);
    int j = my_strlen(f) - 1;
    if ((my_strlen(multi) > 2))
        j += (my_strlen(multi) - 1);
    while (my_strlen(add) >= 2) {
        while (multi[0] != '0' && multi[0] != '-') {
            f = infinadd(f, temp);
            multi = infinadd(multi, add);
        }
        f = infinadd(f, neg_temp);
        multi = infinadd(multi, neg_add);
        temp[j] = '\0';
        add[j + 1] = '\0';
        neg_add[j] = '\0';
        neg_temp[j + 1] = '\0';
        j--;
    }
    f = infinadd(f, neg_temp);
    return f;
}

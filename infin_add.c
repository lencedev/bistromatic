/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** infinadd
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include <stdio.h>

char *sign_add(char const *s1, char const *s2);

int compare_char(char const *s1, char const *s2)
{
    if (s1[0] == '-')
        return compare_char(&s1[1], s2);
    if (s2[0] == '-')
        return compare_char(s1, &s2[1]);
    if (my_strlen(s1) != my_strlen(s2))
        return 1;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return 2;
    }
    return 1;
}

char *print_str(char *final, int carry)
{
    int a = 0;

    if (carry == 1)
        final[0] = '1';
    else
        a++;
    while (final[a] < '1' && final[a + 1] != '\0')
        a++;
    if (final[a] == 'Q')
        final[a] = '0';
    return (&final[a]);
}

char *add_char(char const *s1, char const *s2)
{
    int a;
    int b;
    int result = 0;
    char *final = malloc((sizeof(char) * (my_strlen(s1)) + 2));
    int carry = 0;

    for (int j = 0; j != my_strlen(s1) + 2; j++)
        final[j] = '\0';
    for (int i = (my_strlen(s1) - 1); i >= 0; i--) {
        a = (s1[i] - '0');
        if ((i - (my_strlen(s1) - my_strlen(s2))) < 0)
            b = 0;
        else
            b = s2[i - (my_strlen(s1) - my_strlen(s2))] - '0';
        result = (a + b + carry);
        final[i + 1] = ((result % 10) + '0');
        carry = result / 10;
    }
    return print_str(final, carry);
}

char *infinadd(char const *s1, char const *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int longest_str;

    if (s1[0] == '-')
        len1--;
    if (s2[0] == '-')
        len2--;
    longest_str = (len1 > len2) ? 1 : 2;
    if (len1 == len2)
        longest_str = compare_char(s1, s2);
    if (longest_str == 1)
        return(sign_add(s1, s2));
    if (longest_str == 2)
        return(sign_add(s2, s1));
    return (sign_add(s1, s2));
}

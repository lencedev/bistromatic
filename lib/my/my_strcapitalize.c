/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task10
*/

int verif_bfr_case(char ch)
{
    if (ch == ' ' || ch == '-' || ch == '+')
        return 1;
    if (ch >= 'a' && ch <= 'z')
        return 2;
    if (ch >= 'A' && ch <= 'Z')
        return 2;
    return 0;
}

int verif_case(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i;
    int a;

    if (verif_case(str[0]))
        str[0] -= 32;
    for (i = 1; str[i] != '\0'; i++) {
        a = str[i];
        if (verif_bfr_case(str[i - 1]) && verif_case(str[i])) {
            a -= 32;
            str[i]  = a;
        } else if (verif_case(str[i]) == 0 && verif_bfr_case(str[i - 1]) == 2) {
            a += 32;
            str[i]  = a;
        }
    }
    return str;
}

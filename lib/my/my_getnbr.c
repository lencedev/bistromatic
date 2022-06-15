/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday11-theo.faupin
** File description:
** my_getnbr
*/

int check_sign(char const *str)
{
    int i = 0;
    int minus = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            minus++;
    }
    if (minus % 2 == 1)
        return (-1);
    return (1);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = check_sign(str);
    long int a = 0;
    int result;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '1' && str[i] <= '9')
            a = ((a * 10) + str[i]) - '0';
        else if (str[i] != '+' || str[i] != '-')
            return (a * sign);
        if (a > 2147483647 || a < -2147483648)
            return (0);
    }
    result = (a * sign);
    return (result);
}

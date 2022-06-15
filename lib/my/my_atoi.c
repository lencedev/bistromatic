/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_atoi
*/

int my_atoi(char const *str)
{
    int a = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign *= -1;
        i++;
    }
    for (; str[i] != '\0'; i++) {
        a *= 10;
        a += (str[i] - '0');
    }
    return (a * sign);
}

/*
** EPITECH PROJECT, 2021
** Day04
** File description:
** Task02
*/

void my_putchar(char ch);

int my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}

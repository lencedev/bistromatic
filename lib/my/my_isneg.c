/*
** EPITECH PROJECT, 2021
** Day03
** File description:
** Task04
*/

void my_putchar(char ch);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else if (n >= 0)
        my_putchar('P');
    return 0;
}

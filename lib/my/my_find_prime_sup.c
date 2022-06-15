/*
** EPITECH PROJECT, 2021
** Day05
** File description:
** Task07
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int prime = my_is_prime(nb);

    if (nb < 2)
        return 2;
    if (nb == 2147483647)
        return 0;
    while (prime != 1) {
        nb += 1;
        prime = my_is_prime(nb);
    }
    return nb;
}

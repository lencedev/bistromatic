/*
** EPITECH PROJECT, 2021
** Day05
** File description:
** Task06
*/

int my_compute_power_rec(int nb, int p);

int square(int nb)
{
    int num;
    int i;

    if (nb == 0)
        return 1;
    for (i = 0; i < 46341; i ++) {
        num = my_compute_power_rec(i, 2);
        if (num == nb)
            return i;
        else if (num > nb)
            return i;
    }
    return 0;
}

int my_is_prime(int nb)
{
    int sqrt = square(nb);

    if (nb == 2)
        return 1;
    if (nb < 2 || nb % 2 == 0)
        return 0;
    for (sqrt = square(nb); sqrt > 1; sqrt--) {
        if ((nb % sqrt) == 0)
            return 0;
    }
    return 1;
}

/*
** EPITECH PROJECT, 2021
** Day05
** File description:
** Task05
*/

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb)
{
    int num;
    int i;

    if (nb == 0) {
        return 0;
    } else if (nb < 0)
        return 0;
    for (i = 0; i < 46341; i++) {
        num = my_compute_power_rec(i, 2);
        if (num == nb) {
            return i;
        } else if (nb < num) {
            return 0;
        }
    }
    return 0;
}

/*
** EPITECH PROJECT, 2021
** Day04
** File description:
** Task06
*/

void my_swap(int *a, int *b);

void compare_int(int *n, int *find)
{
    if (*n > *(n + 1)) {
        my_swap(n, (n + 1));
        *find = 1;
    }
}

void my_sort_int_array(int *array, int size)
{
    int find = 1;
    int *begin = array;

    while (find) {
        find = 0;
        for (int i = 0; i < size - 1; i++)
            compare_int(array, &find);
        array = begin;
    }
}

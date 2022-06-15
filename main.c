/*
** EPITECH PROJECT, 2021
** bistro-matic
** File description:
** main.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "include/bistromatic.h"

char *obtain_calc(char const *base, char const *op, char const *expr,
                  unsigned int s);
void check_base_comp(char b, char const *op, char const *base);
void check_op_comp(char const *op, char operator);
char *get_expr(unsigned int size);
void check_in_base(char const *b, char const *op, char c);
void check_misplaced_ops(char *expr, char const *op);

static void usage(char **av)
{
    my_putstr("USAGE\n");
    my_putstr(av[0]);
    my_putstr(" base operators size_read\n");
    my_putstr("\nDESCRIPTION\n- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the parentheses and the 5");
    my_putstr(" operators\n- size_read: number of characters to be");
    my_putstr(" read\n");
    exit(EXIT_USAGE);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_OPS);
    }
    for (int i = 0; ops[i] != '\0'; i++) {
        check_op_comp(ops, ops[i]);
    }
}

static void check_base(char const *b, char const *op)
{
    if (my_strlen(b) < 2) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_BASE);
    }
    for (int i = 0; b[i] != '\0'; i++)
        check_base_comp(b[i], op, b);
}

static void check_size(char const *size)
{
    if (my_str_isnum(size) != 1) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_USAGE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        usage(av);
    } else if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+-*/%\" exp_len\n");
        exit (EXIT_USAGE);
    }
    check_base(av[1], av[2]);
    check_ops(av[2]);
    check_size(av[3]);
    size = my_atoi(av[3]);
    expr = get_expr(size);
    for (int i = 0; expr[i] != '\0'; i++)
        check_in_base(av[1], av[2], expr[i]);
    check_misplaced_ops(expr, av[2]);
    my_putstr(obtain_calc(av[1], av[2], expr, size));
    return (EXIT_SUCCESS);
}

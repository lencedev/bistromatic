/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-theo.faupin
** File description:
** mainc_comp
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "include/bistromatic.h"

int check_mp(char c, char b, char const *ops);

void check_base_comp(char b, char const *op, char const *base)
{
    int count = 0;

    for (int i = 0; op[i] != '\0'; i++) {
        if (b == op[i]) {
            write(2, SYNTAX_ERROR_MSG, 13);
            exit(EXIT_BASE);
        }
    }
    for (int i = 0; base[i] != '\0'; i++) {
        if (b == base[i])
            count++;
    }
    if (count != 1) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_BASE);
    }
}

void check_op_comp(char const *op, char operator)
{
    int count = 0;

    for (int i = 0; op[i] != '\0'; i++) {
        if (operator == op[i])
            count++;
    }
    if (count != 1) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_BASE);
    }
}

void check_in_base(char const *b, char const *op, char c)
{
    int counta = 0;
    int countb = 0;

    for (int i = 0; b[i] != '\0'; i++) {
        if (c != b[i])
            counta++;
    }
    for (int i = 0; op[i] != '\0'; i++) {
        if (c != op[i])
            countb++;
    }
    if (counta == my_strlen(b) && countb == my_strlen(op)) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_BASE);
    }
}

void check_misplaced_ops(char *expr, char const *ops)
{
    char c;

    for (int i = 1; expr[i] != '\0'; i++) {
        c = expr[i - 1];
        if (check_mp(expr[i], c, ops) == 1) {
            write(2, SYNTAX_ERROR_MSG, 13);
            exit(EXIT_BASE);
        }
    }
}

char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        write(2, ERROR_MSG, 6);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        write(2, ERROR_MSG, 6);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return expr;
}

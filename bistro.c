/*
** EPITECH PROJECT, 2021
** bistro-matic
** File description:
** bistro.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/bistromatic.h"
#include "include/my.h"

char *eval_expr(char *buffer);

int check_mp(char c, char b, char const *ops)
{
    if (c == ops[4] || c == ops[5] || c == ops[6]) {
        if (b == ops[4] || b == ops[5] || b == ops[6])
            return 1;
        if (b == ops[2] || b == ops[3] || b == ops[0])
            return 1;
    }
    return 0;
}

char verif(char buffer, char const *op)
{
    char *operator = "()+-*/%";

    for (int i = 0; op[i] != '\0'; i++) {
        if (op[i] == buffer)
            buffer = operator[i];
    }
    return buffer;
}

char *translate_expr(char const *op, char *buffer)
{
    int count_open = 0;
    int count_close = 0;

    for (int j = 0; buffer[j] != '\0'; j++) {
        buffer[j] = verif(buffer[j], op);
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '(')
            count_open++;
        if (buffer[i] == ')')
            count_close++;
    }
    if (count_open != count_close) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_BASE);
    }
    return buffer;
}

char *obtain_calc(char const *base, char const *op, char const *expr,
                  unsigned int size)
{
    char *buffer = malloc(sizeof(char) * (size + 1) );

    for (int i = 0; expr[i] != '\0'; i++) {
        buffer[i] = expr[i];
    }
    buffer[size] = '\0';
    buffer = translate_expr(op, buffer);
    return eval_expr(buffer);
}

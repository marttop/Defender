/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** get_int
*/

#include "utils.h"

int get_int(char *av)
{
    int res = 0;

    if (av[0] == '-') {
        av++;
        for (int i = 0; av[i] != '\0'; i++)
            res = res * 10 + (av[i] - 48);
        res *= -1;
    }
    else {
        for (int i = 0; av[i] != '\0'; i++)
            res = res * 10 + (av[i] - 48);
    }
    return (res);
}
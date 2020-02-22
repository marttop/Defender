/*
** EPITECH PROJECT, 2019
** message
** File description:
** message
*/

#include "defender.h"

int message(void)
{
    write(1, "USAGE\n", 6);
    write(1, "    ./my_defender\n\n", 19);
    write(1, "DESCRIPTION\n", 12);
    write(1, "    Tower defense\n\n", 19);
    write(1, "CONTROLS\n", 9);
    write(1, "    No\n", 7);
    return (EXIT_SUCCESS);
}
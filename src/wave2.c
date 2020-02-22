/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** wave2
*/

#include "defender.h"

void get_random_position(tuto_t *new)
{
    int x = rand() % 42;
    int y = rand() % 42;
    int x_neg = (rand() % 2);
    int y_neg = (rand() % 2);
    if (x_neg == 0 && y_neg == 0) {
        new->pos.x = x, new->pos.y = y;
    } if (x_neg == 1 && y_neg == 1) {
        new->pos.x = (x * -1), new->pos.y = (y * -1);
    } if (x_neg == 1 && y_neg == 0) {
        new->pos.x = (x * -1), new->pos.y = y;
    } if (x_neg == 0 && y_neg == 1) {
        new->pos.x = x, new->pos.y = (y * -1);
    }
}